%{
    #include "for.tab.h"
%}

alpha   [A-Za-z]
digit   [0-9]

%%

for                       return FOR;
{digit}+                  return NUM;
{alpha}({alpha}|{digit})* return ID;
"<="                      return LE;
">="                      return GE;
"++"                      return INCR;
"--"                      return DECR;
"=="                      return EQ;
"!="                      return NE;
"||"                      return OR;
"&&"                      return AND;
"="                       return '=';
"<"                       return '<';
">"                       return '>';
"+"                       return '+';
"-"                       return '-';
"*"                       return '*';
"/"                       return '/';
"("                       return '(';
")"                       return ')';
"{"                       return '{';
"}"                       return '}';
";"                       return ';';
[ \t\n]+                  ;      /* ignore whitespace */
.                         return yytext[0];

%%

int yywrap() {
    return 1;
}
