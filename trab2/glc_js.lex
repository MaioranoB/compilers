%{ 
// Código em C++

int token( int tk ) {
	yylval.linha = linha;
	yylval.coluna = coluna;
	coluna += strlen( yytext );
	yylval.c.clear();
	yylval.c.push_back( yytext );
	return tk;
}

%}

/* Definições regulares */

D		[0-9]
L		[A-Za-z_]

INT		{D}+
NUM		{INT}("."{INT})?([Ee]("+"|"-")?{INT})?
ID		{L}({L}|{D})*

STRING1     ([\"](([\"][\"])|(\\\")|[^\n"])*[\"])|([\'](([\'][\'])|(\\\')|[^\n'])*[\'])
STRING2     ([`]([^`])*[`])
STRING      {STRING1}|{STRING2}
BOOL		true|false

%%

" "        { coluna++; }
"\t"       { coluna += 4; }
"\n"       { linha++; coluna = 1; }

">="	    { return token(_MAIG); }
"<="	    { return token(_MEIG); }
"=="	    { return token(_IG); }
"!="	    { return token(_DIF); }
"++"	    { return token(_PLUSPLUS); }
"+="	    { return token(_PLUSEQUAL); }
"..."	    { return token(_DOTDOTDOT); }

"let"	    { return token(_LET); }
"var"	    { return token(_VAR); }
"const"		{ return token(_CONST); }

"if"	    { return token(_IF); }
"else"	    { return token(_ELSE); }
"for"	    { return token(_FOR); }
"while"	    { return token(_WHILE); }
"do"    	{ return token(_DO); }
"switch"	{ return token(_SWITCH); }
"case"	    { return token(_CASE); }
"break"	    { return token(_BREAK); }
"default" 	{ return token(_DEFAULT); }
"function"	{ return token(_FUNCTION); }
"return"	{ return token(_RETURN); }

"asm{".*"}"  {  string lexema = trim(yytext + 3, "{}"); 
                yylval.c = tokeniza(lexema);
                coluna += strlen(yytext);
                return _ASM; }

{STRING} 	{ return token(_STRING); }
{BOOL} 		{ return token(_BOOL); }
{NUM}   	{ return token(_NUM); }
{ID}		{ return token(_ID); }

.       	{ return token(*yytext); }

%%