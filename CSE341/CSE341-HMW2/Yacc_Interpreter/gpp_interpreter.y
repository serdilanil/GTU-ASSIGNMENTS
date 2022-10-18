%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "gpp_parser.h"

%}

%union{

    int value;
    int *values;
    char id[20];
}

%start START
 /*tokens of operators*/
%token OP_PLUS
%token OP_MINUS
%token OP_DIV
%token OP_MULT
%token OP_OP
%token OP_CP
%token OP_DBLMULT
%token OP_OC
%token OP_CC
%token OP_COMMA
 /*tokens for keywords in g++ language*/
%token KW_AND
%token KW_OR
%token KW_NOT
%token KW_EQUAL
%token KW_LESS
%token KW_NIL
%token KW_LIST
%token KW_APPEND
%token KW_CONCAT
%token KW_SET
%token KW_DEFFUN
%token KW_FOR
%token KW_IF
%token KW_EXIT
%token KW_LOAD
%token KW_DISP
%token KW_TRUE
%token KW_FALSE
%token COMMENT

%token <value> VALUE
%token <id> ID


%type <value> INPUT
%type <value> EXPI
%type <value> EXPB
%type <values> VALUES
%type <values> EXPLISTI
%type <values> ELEMENT

%%
START:  INPUT
        | START INPUT;

INPUT:
    EXPI    {printf("SYNTAX OK.  \nResult = %d\n", $1);}
    |EXPB {printf("SYNTAX OK.  \nResult = %d\n", $1);}
    |EXPLISTI {printf("SYNTAX OK. \nResult = "); print_arr($1); }
    |COMMENT{;}
    |error {printf("error");}
    ;


    EXPI:
        OP_OP OP_PLUS EXPI EXPI OP_CP  {$$=$3+$4;} /* (+ EXPI EXPI) */
        |
        OP_OP OP_MINUS EXPI EXPI OP_CP {$$=$3-$4;} /* (- EXPI EXPI) */
        |
        OP_OP OP_MULT EXPI EXPI OP_CP  {$$=$3*$4;} /* (* EXPI EXPI) */
        |
        OP_OP OP_DIV EXPI EXPI OP_CP   {$$=$3/$4;} /* (/ EXPI EXPI) */
        |
        OP_OP OP_DBLMULT EXPI EXPI OP_CP {$$ = rec_pow($3, $4);}
        |
        ID {$$ = getValue($1);}
        |
        VALUE {$$ = $1;}
        |
        OP_OP KW_SET ID EXPI OP_CP {$$ = $4; addValue($3, $4);}
        |
        OP_OP KW_IF EXPB EXPI OP_CP {$$ = (1 == $3) ? $4: 0;}
        |
        OP_OP KW_FOR EXPB EXPI OP_CP { $$ = (1 == $3) ? $4 : 0; }
        |
        OP_OP KW_IF EXPB EXPI EXPI OP_CP {$$ = (1 == $3) ? $4: $5;}
        |
        OP_OP KW_DISP EXPI OP_CP { $$ = $3; printf("Print: %d\n", $3);} 
        ;


        EXPB:
        OP_OP KW_AND EXPB EXPB OP_CP {$$ = $3 && $4;}
        |
        OP_OP KW_OR EXPB EXPB OP_CP  {$$ = $3 || $4;}
        |
        OP_OP KW_NOT EXPB OP_CP  {$$ = ! ($3);}
        |
        OP_OP KW_EQUAL EXPB EXPB OP_CP {$$ = ($3 == $4);}
        |
        OP_OP KW_EQUAL EXPI EXPI OP_CP {$$ = ($3 == $4);}
        |
        OP_OP KW_LESS EXPI EXPI OP_CP { $$ = $3 < $4; }
        |
        KW_TRUE  { $$ = 1; }
        |
        KW_FALSE   { $$ = 0; }
        |
        OP_OP KW_DISP EXPB OP_CP { $$ = $3; printf("Print: %s\n", ($3 ? "true":"false"));}
        ;

        EXPLISTI:
        OP_OP KW_CONCAT EXPLISTI EXPLISTI OP_CP {$$ = concat($3, $4);}
        |
        OP_OP KW_APPEND EXPI EXPLISTI OP_CP {$$ = appendTwoArray($4, $3);}
        |
        OP_OP KW_LIST VALUES OP_CP {$$ = $3;}
        |
        ELEMENT  {$$ = $1;}
        |
        OP_OP KW_DISP ELEMENT OP_CP { $$ = $3; printf("Print: ");  print_arr($3);}
        ;


        ELEMENT:
        OP_OP VALUES OP_CP {$$ = $2;}
        |
        OP_OP OP_CP { $$= NULL; }
        |
        KW_NIL { $$ = NULL;}
        ;


        VALUES: /* VALUES -> VALUES IntegerValue | IntegerValue */
        VALUES VALUE  {$$ = appendTwoArray($1, $2);}
        |
        VALUE {$$ = NULL; $$ = appendTwoArray($$, $1);}
        ;

%%

#include "lex.yy.c"

yyerror(char *s){
    fprintf(stderr, "%s", s);
}

int main(){
    yyparse();
    return 0;
}