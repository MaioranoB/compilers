%{
// Includes em C/C++ e outras definições.
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Atributos {
  int linha, coluna; 
  vector<string> c;
};

struct Simbolo {
  int linha, coluna;
  string tipo_decl; // "let", "const" e "var"
};

int linha = 1;
int coluna = 1;

// Pilha de Tabela de símbolos
vector< map< string, Simbolo > >  ts  = { { } };

vector<string> funcoes;

// Tenta declarar uma variável "let", "var" ou "const"
void tenta_declarar_let( string nome, int linha, int coluna );
void tenta_declarar_const( string nome, int linha, int coluna );

// Verifica se a variável já foi declarada como "var" anteriormente
bool ja_declarou_var( string nome, int linha, int coluna );

string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );

void imprime_codigo( vector<string> codigo );
void erro( string msg );

string trim(const string &s, const string caracter);
vector<string> tokeniza (string s);

vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string a, vector<string> b );

// Tipo dos atributos: YYSTYPE é o tipo usado para os atributos.
#define YYSTYPE Atributos

// protótipo para o analisador léxico (gerado pelo lex)
extern "C" int yylex();
void yyerror( const char* );


// string gera_label(string);
int declarar_var(string);
void verificar_var(string);

string tipo_decl = "let";
int num_params = 0;
int nivel_func = 0;

%}

%token	 _MAIG _MEIG _IG _DIF _PLUSPLUS _PLUSEQUAL _BOOL _ASM
%token	 _ID _NUM _STRING _LET _VAR _CONST _IF _ELSE _FOR _WHILE _DO _SWITCH _FUNCTION 
%token	 _CASE _BREAK _DEFAULT _RETURN _DOTDOTDOT

%start  S

%left ','
%right '=' 
%nonassoc '<' '>' 
%left '+' '-'
%left '*' '/' '%'
%left '[' '('

%%

S : CMDs { imprime_codigo( $1.c + "." + funcoes );  }
  ;

CMDs : CMD CMDs { $$.c = $1.c + $2.c; }
     | CMD
     ;

CMD : DECL_VAR ';'
    | CMD_IF
    | CMD_FOR
    | CMD_WHILE
    | DECLA_FUNC
    | E _ASM ';'     { $$.c = $1.c + $2.c + "^"; }
    | _RETURN E ';' { $$.c = $2.c + "'&retorno'" + "@" + "~"; }
    | ';'           { $$.c.clear(); }
    | BLOCO_CMDs
    ;

BLOCO_CMDs : '{''}' { $$.c.clear(); }
           | '{' NOVO_ESCOPO CMDs '}' DESTROI_ESCOPO { $$.c.clear(); $$.c = $$.c + "<{" + $3.c + "}>"; }
           ;

NOVO_ESCOPO : { ts.push_back( {} ); }
            ;
            
DESTROI_ESCOPO : { ts.pop_back(); }
               ;    

DECL_VAR : _LET { tipo_decl = "let"; } NOMEVAR     { $$.c = $3.c; }
         | _VAR { tipo_decl = "var"; } NOMEVAR     { $$.c = $3.c; }
         | _CONST { tipo_decl = "const"; } NOMEVAR { $$.c = $3.c; }
         | A                                       { $$.c = $1.c + "^"; }
         ;

NOMEVAR : _ID '=' A OUTRAVAR
            {
              $$.c.clear();
              if(declarar_var($1.c[0])) $$.c = $1.c + "&";
              $$.c = $$.c + $1.c + $3.c + "=" + "^" + $4.c;
            }
        | _ID  OUTRAVAR
          {
             $$.c.clear();
             if(declarar_var($1.c[0])) $$.c = $1.c + "&";
             $$.c = $$.c+ $2.c;
          }
        ;      

OUTRAVAR : ',' NOMEVAR  { $$.c = $2.c; }
         |              { $$.c.clear(); }                  
         ;

CMD_WHILE : _WHILE '(' BOOL ')' CMD {
                              string bloco = gera_label("LBL_LOOP");
                              string end_bloco = gera_label("LBL_ENDWHILE");
                              $$.c.clear(); $$.c =  $$.c + (":" + bloco) + $3.c + "!" +  end_bloco + "?" + $5.c + bloco + "#" + (":" + end_bloco);
                              }
          ;

CMD_FOR : _FOR '(' DECL_VAR ';' BOOL ';' A ')' CMD { 
                              string bloco = gera_label("LBL_LOOP");
                              string end_bloco = gera_label("LBL_ENDFOR");
                              $$.c = $3.c + (":" + bloco) + $5.c + "!" + end_bloco + "?" + $9.c + $7.c + "^" + bloco + "#" + (":" + end_bloco);
                              }

CMD_IF  : _IF '(' BOOL ')' CMD CMD_ELSE {
                              string bloco = gera_label("LBL_THEN");
                              string end_bloco = gera_label("LBL_ENDIF");
                              $$.c = $3.c + "!" + bloco+ "?" + $5.c + end_bloco + "#" + (":" + bloco) + $6.c +(":" + end_bloco);
                              } 
        ;

CMD_ELSE : _ELSE  CMD {$$.c = $2.c; }
         |            { $$.c.clear(); }                  
         ;

DECLA_FUNC  : _FUNCTION _ID '(' NOVO_ESCOPO ARGs_FUNC ')' '{'  CMDs '}' DESTROI_ESCOPO
              {
                string labelfunc = gera_label("LABELFUNCAO");
                $$.c = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + labelfunc + "[=]" + "^";
                funcoes = funcoes + (":"+labelfunc) + $5.c + $8.c + "undefined" + "@" + "'&retorno'" + "@" + "~";
              }
            | '(' _ID ')' '('ARGs_FUNC2')'
              {
                num_params++;
                $$.c = $5.c + to_string(num_params) +$2.c + "@" +"$" + "^";
              }
            ;

ARGs_FUNC : _ID { num_params++; } ',' ARGs_FUNC 
            {
              $$.c.clear();
              if(declarar_var($1.c[0])) $$.c = $1.c + "&";
              num_params--;
              $$.c = $$.c + $1.c + "arguments" + "@" + to_string(num_params) + "[@]" + "=" + "^" + $4.c;
            }
          | _ID 
            { 
              $$.c.clear();
              if(declarar_var($1.c[0])) $$.c = $1.c + "&";
              $$.c = $$.c + $1.c + "arguments" + "@" + to_string(num_params) + "[@]" + "=" + "^";
            }
          |   { $$.c.clear(); }
          ;

ARGs_FUNC2 : _ID {num_params++;} ',' ARGs_FUNC
              {
                $$.c.clear();
                if(declarar_var($1.c[0])) $$.c = $1.c + "&";
                num_params--;
                $$.c = $$.c + $1.c + "arguments" + "@" + to_string(num_params) + "[@]" + "=" + "^" + $4.c;
              }
          
          | _ID
            {
              $$.c.clear();
              if(declarar_var($1.c[0])) $$.c = $1.c + "&";;
              $$.c = $$.c + $1.c + "@";
            }
          |   { $$.c.clear();}    
          ; 

BOOL : A '<' A    { $$.c = $1.c  + $3.c + "<"; }
      | A '>' A   { $$.c = $1.c  + $3.c + ">"; }
      | A _IG A   { $$.c = $1.c  + $3.c + "=="; }
      | A _DIF A  { $$.c = $1.c  + $3.c + "!="; }
      | _BOOL
      | A
      ;

A : _ID  '=' A                    { $$.c = $1.c + $3.c + "="; }
  | _ID LVALUEPROP '=' A          { $$.c = $1.c+ "@" + $2.c + $4.c + "[=]"; }
  | F LVALUEPROP '=' A            { $$.c = $1.c + $2.c + $4.c + "[=]"; }
  | '(' _ID ')' LVALUEPROP '=' A  { $$.c = $2.c+ "@" + $4.c + $6.c + "[=]"; }
  | _ID LVALUEPROP '+' A          { $$.c = $1.c+ "@" + $2.c + "[@]"+ $4.c + "+"; }
  | _ID LVALUEPROP '-' A          { $$.c = $1.c+ "@" + $2.c + "[@]"+ $4.c + "-"; }
  | _ID LVALUEPROP '*' A          { $$.c = $1.c+ "@" + $2.c + "[@]"+ $4.c + "*"; }
  | _ID LVALUEPROP                { $$.c = $1.c+ "@" + $2.c + "[@]"; }
  | _ID _PLUSEQUAL A              { $$.c = $1.c + $1.c + "@" + $3.c + "+"+ "="; }
  | _ID LVALUEPROP _PLUSEQUAL A   { $$.c = $1.c+ "@" + $2.c + $1.c+ "@" + $2.c + "[@]" + $4.c + "+" + "[=]"; }
  | E
  ;

RVALUE : _ID _PLUSPLUS { verificar_var($1.c[0]); $$.c = $1.c + "@" + $1.c + $1.c + "@" + "1" + "+" + "=" + "^"; }
       ;
        
LVALUEPROP : '[' A ']' LVALUEPROP  { $$.c = $2.c + "[@]" + $4.c ; }
           | '.' _ID LVALUEPROP    { $$.c = $2.c + "[@]" + $3.c; }
           | '[' A ']'             { $$.c =  $2.c; }
           | '.' _ID               { $$.c = $2.c; }
           ;

E : E '+' E { $$.c = $1.c + $3.c + "+"; }
  | E '-' E { $$.c = $1.c + $3.c + "-"; }
  | E '*' E { $$.c = $1.c + $3.c + "*"; }
  | E '/' E { $$.c = $1.c + $3.c + "/"; }
  | E '%' E { $$.c = $1.c + $3.c + "%"; }
  | F
  | RVALUE
  ;

PARAMS : A PARAM  { $$.c = $1.c + $2.c; num_params++; }
       |          { $$.c.clear(); }    
       ;

PARAM : ',' A PARAM { $$.c = $2.c + $3.c; num_params++;}
      |             { $$.c.clear();  }     
      ;

LVALUE : _ID LVALUEPROP { $$.c = $1.c + "@" + $2.c + "[@]"; }
       | _ID            { $$.c = $1.c + "@"; }
       ;

F : LVALUE
  | _NUM
  | _STRING
  | LVALUE '(' PARAMS ')' { $$.c = $3.c + to_string(num_params) + $1.c + "$"; num_params = 0; }
  | '(' A ')'             { $$ = $2; }
  | '-' F                 { $$.c.clear(); $$.c = $$.c + "0" + $2.c + $1.c; }
  | '{''}'                { $$.c.clear(); $$.c = $$.c + "{}"; }
  | '['']'                { $$.c.clear(); $$.c = $$.c + "[]"; }
  | _BOOL
  ;
        
%%

#include "lex.yy.c"

void yyerror(const char* msg){
    cout << endl << "Erro: " << msg << endl
         << "Perto de :'" << yylval.c[0] << "'" <<endl
         << "Linha: " << linha << " " 
         << "Coluna: "<< coluna<< endl;
    exit(0);
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

void verificar_var(string nome) {
  for(int i = 0; i < ts.size(); i++) {
    map<string,Simbolo> escopo = ts[i];
    if(escopo.count(nome) > 0) return;
  }
  cout << "Erro: a variável '" << nome << "' não foi declarada." << endl;
  exit(1);
}

int declarar_var(string nome) {
  map<string,Simbolo> escopo = ts.back();
  if(escopo.count(nome) > 0 && escopo[nome].tipo_decl == "let") {
    cout << "Erro: a variável '" << nome << "' já foi declarada na linha "
         << escopo[nome].linha << "." << endl;
    exit(1);
  }

  for(map<string,Simbolo> escopo: ts){
    if(escopo.count(nome) > 0 && escopo[nome].tipo_decl == "var" && tipo_decl == "var") return 0;
  }

  Simbolo v;
  v.tipo_decl = tipo_decl;
  v.linha = linha;
  ts.back()[nome] = v;
  return 1;
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ )
    if( entrada[i][0] == ':' ) 
      label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  
  for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
      saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

void imprime_codigo( vector<string> codigo ) {
  vector<string> codigo_resolvido = resolve_enderecos(codigo);
  for( int i = 0; i < codigo_resolvido.size(); i++ )
    cout << codigo_resolvido[i] << " ";
  cout << endl;
}

vector<string> tokeniza (string s){
	vector<string> result;
	string aux;
	int inicio = 0, final = s.find(" ");
  while (final > 0) {
    aux = s.substr(inicio, final - inicio);
    result = result + aux;
    inicio = final + 1;
    final = s.find(" ", inicio);
  }
  aux = s.substr(inicio, final - inicio);
  result = result + aux;
  return result;
}

string trim(const string &s, const string caracter) {
  string str4 = s.substr(s.find_first_not_of(caracter[0]));
  str4 = str4.substr(0,str4.find_last_not_of(caracter[1])+1) ;
  return str4;
}

vector<string> concatena( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

vector<string> operator+( string a, vector<string> b ) {
  vector<string> aux{ a };
  return aux + b;
}

int main(){
  yyparse();
  cout << endl;
  return 0;
}