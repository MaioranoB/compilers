# Primeiro Analisador Léxico

Crie um arquivo LEX que reconheça os tokens descritos a seguir:

| **Token** | **Lexemas** | **Padrão** |
|-----------|-------------|----------  |
_ID | a b _1 ab1 $tab _5 $o a@e $@2 $_@@ | '$', letra ou '_' seguido por letra, @,dígito ou '_'. Não é permitido $@ puro(s), tem que ter pelo menos mais um caractere ou dígito.
_INT | 1 221 0 | Números inteiros 
_FLOAT | 0.1 1.028 1.2E-4 0.2e+3 1e3 | Números de ponto flutuante e em notação científica 
_FOR | for For fOr | for, _case insensitive_
_IF | if IF | if, _case insensitive_ 
_MAIG | >= | >= 
_MEIG | <= | <=
_IG | == | == 
_DIF | != | != 
_COMENTARIO | /* Um comentário \*/ <br/> /* Outro comentário */ <br/> // Comentário até o final da linha  <br/> // /\*Esse comentário anula o início <br/>/\* Esse comentário foi terminado! // */ | Uma string começa e termina com aspas. Se houver aspas dentro da string devemos usar contrabarra ou duas aspas. Uma string não pode ir além do final da linha. Podemos usar aspas simples ou aspas duplas, mas se começou com aspas simples deve terminar com aspas simples.
_STRING | "hello, world" <br/> 'hello, world' <br/> "Aspas internas com \" (contrabarra)" <br/>  "ou com "" (duas aspas)" <br/> 'd''água' "d'água" 'd\'água' | Uma string começa e termina com aspas. Se houver aspas dentro da string devemos usar contrabarra ou duas  aspas. Uma string não pode ir além do final da linha. Podemos usar aspas simples ou aspas duplas, mas se começou com aspas simples deve terminar com aspas simples.
_STRING2 | \`hello, world\` <br/> \`hello, <br/> world\` <br/> \`Hora atual: ${agora} horas!\` | Aspas invertidas. Podem se estender para além do final da linha. Nesse caso a string deve conter os espaços em branco e a quebra de linha ('\n'). É permitido dentro de string o \${ID}, que deve ser identificado (a string termina antes do "$" e recomeça após o "}". Isso deve retorna 3 tokens: _STRING, EXPR e STRING.


Identificadores (letras, '$' ou sublinhado seguido de letras, sublinhado, '@' e dígitos), números, strings entre aspas duplas, entre aspas simples e comentários. Declare uma variável '**string lexema**' e coloque nela o lexema que casou com o padrão e deve ser retornado, possivelmente com alguma alteração (por exemplo, tirar as aspas).

Assuma a seguinte declaração para os tokens:

```c
enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _EXPR };
```

A compilação será feita com o seguinte comando:

```
lex scan.lex
g++ -Wall -std=c++17 main.cc -lfl
```

OBS: Algumas distribuições do linux utilizam bibliotecas com outro nome, possivelmente: "-lf" ou "-ll".

O programa "main.cc" usado é o seguinte:

```c
#include <stdio.h>
#include <string>

using namespace std;

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _EXPR };

extern "C" int yylex();  
extern "C" FILE *yyin;

void yyerror(const char* s);  

#include "lex.yy.c"

auto p = &yyunput; // Para evitar uma warning de 'unused variable'

int main() {
  int token = 0;
  
  while( (token = yylex()) != 0 )  
    printf( "%d %s\n", token, lexema.c_str() );
  
  return 0;
}
```

## Arquivos requeridos
#### scan.lex

```
/* Coloque aqui definições regulares */

WS	[ \t\n]


%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{WS}	{ /* ignora espaços, tabs e '\n' */ } 

.       { return *yytext; 
          /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%

/* Não coloque nada aqui - a função main é automaticamente incluída na hora de avaliar e dar a nota. */
```
