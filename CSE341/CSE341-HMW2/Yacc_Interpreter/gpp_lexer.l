%{ 
    /* DEFINITION PART */
#include <stdio.h>
#include<stdlib.h>


%}

COMMENT ";;".*
VAL [1-9][0-9]*|"0"
ID [a-zA-Z][a-zA-Z0-9]*
FLOAT_P [0-9]+"."[0-9]*

%% 
    /* RULES PART */

{COMMENT} { return COMMENT ;}
"not" { return KW_NOT ;}
"nil" { return KW_NIL;}
"load" { return KW_LOAD;}
"disp" { return KW_DISP;}
"and" { return KW_AND;}
"or" { return KW_OR;}
"true" { return KW_TRUE;}
"false" { return KW_FALSE;}
"list" { return KW_LIST;}
"append" { return KW_APPEND;}
"concat" { return KW_CONCAT;}
"set" { return KW_SET;}
"deffun" { return KW_DEFFUN;}
"equal" { return KW_EQUAL;}
"less" { return KW_LESS;}
"for" { return KW_FOR;}
"if" { return KW_IF;}


"+" { return OP_PLUS;}
"-" { return OP_MINUS;}
"/" { return OP_DIV;}
"*" { return OP_MULT;}
"(" { return OP_OP;}
")" { return OP_CP;}
"**" { return OP_DBLMULT;}
"," { return OP_COMMA;}
"`" {}
"'" {}

"\"" {
int count = 0;   
if(count == 0){fprintf(yyout,"OP_OC\n"); count = 1;}
else{fprintf(yyout,"OP_CC\n");count = 0;}}

[[:alpha:]][[:alnum:]]*   {strcpy(yylval.id, yytext); return ID;}
(0)|([1-9][0-9]*) {yylval.value = atoi(yytext); return VALUE;}

[0-9][0-9a-zA-Z]*	 	  	  {printf("SYNTAX_ERROR:!\n"); return 0;}

.	 {} 
^\n                     {}
%% 

yywrap(){
    return 1;
}