%{ 
// Código em C++

string lexema;

string removeQuotes(string text) {
    return text.substr(1, text.length() - 2);
}

string checkEXPR(string text) {
    int size = text.length();
    int startEXPR = -1;
    int endEXPR = -1;
    int sizeEXPR = 0;

    for (int i = 0; i < size; i++) {
        if (text[i] == '$' && text[i+1] == '{') {
            startEXPR = i;
            break;
        }
    }
    
    // se nao achou começo da EXPR, retorna lexema original
    if (startEXPR == -1) return text;

    for (int i = startEXPR + 2; i < size; i++) {
        sizeEXPR ++;
        if (text[i] == '}') {
            endEXPR = i;
            break;
        }
    }

    printf( "%d %s\n", _STRING2, text.substr(0, startEXPR).c_str() );
    printf( "%d %s\n", _EXPR, text.substr(startEXPR+2, sizeEXPR-1).c_str() );
    
    return text.substr(startEXPR+2+sizeEXPR, size);
}

%}

/* Definições regulares */

WS	        [ \t\n]
D	        [0-9]
L	        [A-Za-z_]

INT	        {D}+
FLOAT       {INT}("."{INT})?([Ee]("+"|"-")?{INT})?
FOR	        ([Ff][Oo][Rr])
IF	        ([Ii][Ff])

ID          ({L}|"$")({L}|{D}|"@")*
IDINVALIDO  ("@"|"@"({ID}|"@")*|"$@"|{ID}"$"|{D}({ID}|"@")*)

COMENTARIO ([/][*]([*][^/]|([/][^/])|[^/])*[*][/])|([/][/][^\n]*)
STRING      ([\"](([\"][\"])|(\\\")|[^\n"])*[\"])|([\'](([\'][\'])|(\\\')|[^\n'])*[\'])
STRING2     ([`]([^`])*[`])

%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{WS}	        { /* ignora espaços, tabs e '\n' */ }
{INT}	        { lexema = yytext; return _INT; }
{FLOAT}     	{ lexema = yytext; return _FLOAT; }
{FOR}	        { lexema = yytext; return _FOR; }
{IF}	        { lexema = yytext; return _IF; }
{COMENTARIO}    { lexema = yytext; return _COMENTARIO; }
{STRING} 	    { lexema = removeQuotes(yytext); return _STRING;}
{STRING2} 	    { lexema = checkEXPR(removeQuotes(yytext)) ; return _STRING2; }
{IDINVALIDO}	{ lexema = yytext; printf( "Erro: Identificador inválido: %s\n", yytext ); }
{ID}	        { lexema = yytext; return _ID; }

">="	        { lexema = yytext; return _MAIG; }
"<="	        { lexema = yytext; return _MEIG; }
"=="	        { lexema = yytext; return _IG; }
"!="	        { lexema = yytext; return _DIF; }

                /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */
.               { lexema = yytext; return *yytext; }

%%

/* Não coloque nada aqui - a função main é automaticamente incluída na hora de avaliar e dar a nota. */
