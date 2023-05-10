all: saida entrada.txt
	./saida.out < entrada.txt

saida: lex.yy.c 
	g++ -Wall -std=c++17 main.cc -o saida.out -ll
	
lex.yy.c: scan.lex 
	lex scan.lex

clean: 
	rm -f lex.yy.c saida.out