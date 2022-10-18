%{ 
    /* DEFINITION PART */
#include <stdio.h>
#include<stdlib.h>

%}

COMMENT ";;".*
VAL [1-9][0-9]*|"0"
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
FLOAT_P [0-9]+"."[0-9]*

%% 
    /* RULES PART */

{COMMENT} {fprintf(yyout, "COMMENT\n");}
not {fprintf(yyout,"KW_NOT\n");}
nil {fprintf(yyout,"KW_NIL\n");}
load {fprintf(yyout,"KW_LOAD\n");}
disp {fprintf(yyout,"KW_DISP\n");}
and {fprintf(yyout,"KW_AND\n");}
or {fprintf(yyout,"KW_OR\n");}
true {fprintf(yyout,"KW_TRUE\n");}
false {fprintf(yyout,"KW_FALSE\n");}
list {fprintf(yyout,"KW_LIST\n");}
append {fprintf(yyout,"KW_APPEND\n");}
concat {fprintf(yyout,"KW_CONCAT\n");}
set {fprintf(yyout,"KW_SET\n");}
deffun {fprintf(yyout,"KW_DEFFUN\n");}
equal {fprintf(yyout,"KW_EQUAL\n");}
less {fprintf(yyout,"KW_LESS\n");}
for {fprintf(yyout,"KW_FOR\n");}
if {fprintf(yyout,"KW_IF\n");}


"+" {fprintf(yyout,"OP_PLUS\n");}
"-" {fprintf(yyout,"OP_MINUS\n");}
"/" {fprintf(yyout,"OP_DIV\n");}
"*" {fprintf(yyout,"OP_MULT\n");}
"(" {fprintf(yyout,"OP_OP\n");}
")" {fprintf(yyout,"OP_CP\n");}
"**" {fprintf(yyout,"OP_DBLMULT\n");}
"," {fprintf(yyout,"OP_COMMA\n");}
"`" {}
"'" {}

"\"" {
int count = 0;   
if(count == 0){fprintf(yyout,"OP_OC\n"); count = 1;}
else{fprintf(yyout,"OP_CC\n");count = 0;}}


{VAL}|{FLOAT_P} {fprintf(yyout,"VALUE\n");}
{IDENTIFIER} {fprintf(yyout,"IDENTIFIER\n");}

[0-9][0-9a-zA-Z]* {fprintf(yyout,"ERROR\n");}

.	 {fprintf(yyout,"ERROR\n");} 
^\n                     {exit(1);}
%% 

yywrap(){} 

int main(int argc, char **argv){

   extern FILE* yyin;
   yyin = fopen("input.txt","r");
   yylex();
   return 0;
}
