%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
int yyerror(const char *s);
%}

%token ID INVALID

%%
S: ID        { printf("Valid Identifier\n"); exit(0); }
 | INVALID   { printf("Invalid Identifier\n"); exit(0); }
 ;
%%

int main() {
    printf("Enter an identifier: ");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
