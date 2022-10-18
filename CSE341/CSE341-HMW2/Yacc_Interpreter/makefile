target:test
	
test:
	lex gpp_lexer.l && yacc -d gpp_interpreter.y &&  gcc -o output y.tab.c && ./output
	