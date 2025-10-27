%{
    #include "calc.tab.h"
%}

digit   [0-9]

%%

{digit}+        { yylval = atoi(yytext); return NUM; }
"\\+"           return '+';
"-"             return '-';
"\\*"           return '*';
"/"             return '/';
"\\("           return '(';
"\\)"           return ')';
[ \t\n]+        ;       /* Ignore whitespace */
.               return yytext[0];

%%

int yywrap() { return 1; }
