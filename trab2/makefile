all: mdp.txt
	../mdp/interpretador < mdp.txt
	
mdp.txt: saida entrada.js
	./saida.out < entrada.js > mdp.txt	

saida: lex.yy.c y.tab.c
	g++ -std=c++17 y.tab.c -o saida.out -ll
	
lex.yy.c: glc_js.lex
	lex glc_js.lex
	
y.tab.c: glc_js.y
	yacc glc_js.y
	
clean: 
	rm -f lex.yy.c y.tab.c saida.out