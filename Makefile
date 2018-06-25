all: carriera_universitaria.tab.c lex.yy.c symbol_table.c
	gcc -o carriera_universitaria carriera_universitaria.tab.c lex.yy.c symbol_table.c

carriera_universitaria.tab.c: carriera_universitaria.y 
	bison -d carriera_universitaria.y

lex.yy.c: carriera_universitaria.fl
	flex carriera_universitaria.fl 
