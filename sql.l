%{
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%option noyywrap
%option case-insensitive

%%
"SELECT"    { return SELECT; }
"FROM"      { return FROM; }
"WHERE"     { return WHERE; }
"AND"       { return AND; }
"OR"        { return OR; }
"JOIN"      { return JOIN; }
"ON"        { return ON; }
"ORDER"     { return ORDER; }
"BY"        { return BY; }
"ASC"       { return ASC; }
"DESC"      { return DESC; }
"HAVING"    { return HAVING; }
"LIKE"      { return LIKE; }
"LIMIT"     { return LIMIT; }
"GROUP"     { return GROUP; }
"SUM"       { return SUM; }
"AVG"       { return AVG; }
"COUNT"     { return COUNT; }
"MIN"       { return MIN; }
"MAX"       { return MAX; }

"="         { return EQ; }
">"         { return GT; }
"<"         { return LT; }
","         { return ','; }
"*"         { return '*'; }
"("         { return '('; }
")"         { return ')'; }
"."         { return '.'; }

'[^']*'                 { yylval.str = strdup(yytext); return WORD; }
\"[^"]*\"               { yylval.str = strdup(yytext); return WORD; }
[a-zA-Z][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return WORD; }
[0-9]+                  { yylval.num = atoi(yytext); return NUMBER; }

[ \t]       ;
\n          { return '\n'; }
.           { return yytext[0]; }
%%