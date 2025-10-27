%{
    #include <stdio.h>
    #include <stdlib.h>

    int yylex(void);
    int yyerror(const char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%

S: E { printf("Result = %d\n", $1); };

E: E '+' E   { $$ = $1 + $3; }
 | E '-' E   { $$ = $1 - $3; }
 | E '*' E   { $$ = $1 * $3; }
 | E '/' E   { 
                 if ($3 == 0) { 
                     yyerror("Division by zero"); 
                     YYABORT; 
                 } 
                 $$ = $1 / $3; 
              }
 | '(' E ')' { $$ = $2; }
 | NUM       { $$ = $1; }
 ;

%%

int main()
{
    printf("Enter an expression:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
