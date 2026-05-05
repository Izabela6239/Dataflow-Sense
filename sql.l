%{
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
%}

/* Previne erorile de compilare daca nu este definita functia yywrap */
%option noyywrap
/* SQL nu este case-sensitive pentru cuvinte cheie */
%option case-insensitive

/* Macro-uri pentru definirea pattern-urilor comune */
DIGIT       [0-9]
ID_START    [a-zA-Z_]
ID_CHAR     [a-zA-Z0-9_]*

%%
/* Ignora comentariile de tip linie (--) */
"--"[^\n]*                  ;
/* Ignora comentariile de tip bloc (/* ... */) */
"/*"([^*]|\*+[^*/])*\*+"/"  ;

/* Cuvinte cheie DQL */
"SELECT"      { return SELECT; }
"DISTINCT"    { return DISTINCT; }
"FROM"        { return FROM; }
"WHERE"       { return WHERE; }
"AND"         { return AND; }
"OR"          { return OR; }
"NOT"         { return NOT; }
"JOIN"        { return JOIN; }
"INNER"       { return INNER; }
"LEFT"        { return LEFT; }
"RIGHT"       { return RIGHT; }
"FULL"        { return FULL; }
"OUTER"       { return OUTER; }
"CROSS"       { return CROSS; }
"ON"          { return ON; }
"ORDER"       { return ORDER; }
"BY"          { return BY; }
"ASC"         { return ASC; }
"DESC"        { return DESC; }
"HAVING"      { return HAVING; }
"LIKE"        { return LIKE; }
"IN"          { return IN; }
"BETWEEN"     { return BETWEEN; }
"IS"          { return IS; }
"NULL"        { return NULL_T; }
"LIMIT"       { return LIMIT; }
"OFFSET"      { return OFFSET; }
"GROUP"       { return GROUP; }
"AS"          { return AS; }
"SUM"         { return SUM; }
"AVG"         { return AVG; }
"COUNT"       { return COUNT; }
"MIN"         { return MIN; }
"MAX"         { return MAX; }

/* Cuvinte cheie DML */
"INSERT"      { return INSERT; }
"INTO"        { return INTO; }
"VALUES"      { return VALUES; }
"UPDATE"      { return UPDATE; }
"SET"         { return SET; }
"DELETE"      { return DELETE; }

/* Cuvinte cheie DDL */
"CREATE"      { return CREATE; }
"TABLE"       { return TABLE; }
"DROP"        { return DROP; }
"ALTER"       { return ALTER; }
"ADD"         { return ADD; }
"COLUMN"      { return COLUMN; }
"PRIMARY"     { return PRIMARY; }
"KEY"         { return KEY; }
"FOREIGN"     { return FOREIGN; }
"REFERENCES"  { return REFERENCES; }
"DEFAULT"     { return DEFAULT; }
"CHECK"       { return CHECK; }
"UNIQUE"      { return UNIQUE; }

/* Operatori relationali */
">="          { return GE; }
"<="          { return LE; }
"<>"          { return NE; }
"!="          { return NE; }
"="           { return EQ; }
">"           { return GT; }
"<"           { return LT; }

/* Operatori aritmetici si semne de punctuatie */
"+"           { return '+'; }
"-"           { return '-'; }
"/"           { return '/'; }
","           { return ','; }
";"           { return ';'; }
"*"           { return '*'; }
"("           { return '('; }
")"           { return ')'; }
"."           { return '.'; }

/* Recunoasterea sirurilor de caractere cu apostrof sau ghilimele */
'([^']|'')*'               { yylval.str = strdup(yytext); return STRING; }
\"([^"]|\"\")*\"           { yylval.str = strdup(yytext); return STRING; }

/* Recunoasterea numerelor (intregi si zecimale) */
{DIGIT}+("."{DIGIT}+)?     { yylval.str = strdup(yytext); return NUMBER; }

/* Recunoasterea identificatorilor (nume de tabele, coloane) */
{ID_START}{ID_CHAR}       { yylval.str = strdup(yytext); return WORD; }

/* Ignora spatiile albe, tab-urile si carriage return */
[ \t\r]+     ;
/* Returneaza caracterul de linie noua pentru a marca sfarsitul unei comenzi */
\n            { return '\n'; }
/* Orice alt caracter necunoscut este returnat ca atare */
.             { return yytext[0]; }
%%