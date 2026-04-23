%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);

char* concat(char* s1, char* s2, char* s3) {
    char* res = malloc(strlen(s1) + strlen(s2) + strlen(s3) + 50);
    sprintf(res, "%s %s %s", s1, s2, s3);
    return res;
}
%}

%union {
    char* str;
    int num;
}

%token <str> SELECT FROM WHERE WORD EQ GT LT AND OR JOIN ON ORDER BY ASC DESC HAVING LIKE LIMIT GROUP
%token <str> SUM AVG COUNT MIN MAX
%token <num> NUMBER

%type <str> select_stmt lista_coloane element_coloana tabel conditie expresie join_clause order_clause 
%type <str> optional_where having_clause limit_clause identificator_complet group_by_clause functie_agregat termen_comparare

%left OR
%left AND

%%

input:    | input linie ;

linie:    '\n'
        | select_stmt '\n' { printf("\nTRADUCERE ANALITICA: %s\n\n", $1); }
        | error '\n' { yyerrok; printf("Eroare de structura SQL detectata.\n"); }
        ;

select_stmt: SELECT lista_coloane FROM tabel join_clause optional_where group_by_clause having_clause order_clause limit_clause {
                char* res = concat("Calculeaza [", $2, "] din '");
                res = concat(res, $4, "'");
                res = concat(res, $5, ""); 
                res = concat(res, $6, ""); 
                res = concat(res, $7, ""); 
                res = concat(res, $8, ""); 
                res = concat(res, $9, ""); 
                $$ = concat(res, $10, ""); 
           }
           ;

lista_coloane: element_coloana { $$ = strdup($1); }
             | lista_coloane ',' element_coloana { 
                 char* b = malloc(strlen($1)+strlen($3)+5); 
                 sprintf(b, "%s, %s", $1, $3); 
                 $$=b; 
             }
             | '*' { $$ = strdup("toate datele"); }
             ;

element_coloana: identificator_complet { $$ = $1; }
               | functie_agregat '(' identificator_complet ')' { $$ = concat($1, "pentru", $3); }
               | COUNT '(' '*' ')' { $$ = strdup("numarul total de inregistrari"); }
               | COUNT '(' identificator_complet ')' { $$ = concat("numarul de valori din", $3, ""); }
               ;

functie_agregat: SUM { $$ = strdup("Suma"); }
               | AVG { $$ = strdup("Media"); }
               | MIN { $$ = strdup("Valoarea minima"); }
               | MAX { $$ = strdup("Valoarea maxima"); }
               ;

group_by_clause: /* gol */ { $$ = strdup(""); }
               | GROUP BY identificator_complet { $$ = concat(" grupate dupa coloana", $3, ""); }
               ;

identificator_complet: WORD { $$ = strdup($1); }
                     | WORD '.' WORD { char* s = malloc(strlen($1)+strlen($3)+2); sprintf(s,"%s.%s",$1,$3); $$=s; }
                     ;

optional_where: /* gol */ { $$ = strdup(""); } 
              | WHERE conditie { $$ = concat(" unde", $2, ""); } ;

join_clause: /* gol */ { $$ = strdup(""); } 
           | JOIN tabel ON conditie { $$ = concat(" combinat cu", $2, " pe baza "); $$ = concat($$, $4, ""); } ;

having_clause: /* gol */ { $$ = strdup(""); } 
             | HAVING conditie { $$ = concat(" (dupa grupare se pastreaza doar unde", $2, ")"); } ;

order_clause: /* gol */ { $$ = strdup(""); } 
            | ORDER BY identificator_complet { $$ = concat(", sortat dupa", $3, ""); }
            | ORDER BY identificator_complet ASC { $$ = concat(", sortat crescator dupa", $3, ""); }
            | ORDER BY identificator_complet DESC { $$ = concat(", sortat descrescator dupa", $3, ""); } ;

limit_clause: /* gol */ { $$ = strdup(""); } 
            | LIMIT NUMBER { char b[50]; sprintf(b, ", limitat la %d randuri", $2); $$=strdup(b); } ;

conditie: expresie 
        | conditie AND conditie { $$ = concat($1, " SI ", $3); }
        | conditie OR conditie  { $$ = concat($1, " SAU ", $3); }
        | '(' conditie ')'      { $$ = concat("(", $2, ")"); }
        ;

expresie: termen_comparare EQ termen_comparare { $$ = concat($1, " egal cu ", $3); }
        | termen_comparare EQ NUMBER           { char b[20]; sprintf(b, "%d", $3); $$ = concat($1, " egal cu ", b); }
        | termen_comparare GT NUMBER           { char b[20]; sprintf(b, "%d", $3); $$ = concat($1, " mai mare decat ", b); }
        | termen_comparare LT NUMBER           { char b[20]; sprintf(b, "%d", $3); $$ = concat($1, " mai mic decat ", b); }
        | termen_comparare LIKE WORD           { $$ = concat($1, " seamana cu ", $3); }
        ;

termen_comparare: identificator_complet { $$ = $1; }
                | functie_agregat '(' identificator_complet ')' { $$ = concat($1, "pentru", $3); }
                | functie_agregat '(' '*' ')' { $$ = concat($1, "total", ""); }
                | COUNT '(' identificator_complet ')' { $$ = concat("numarul de", $3, ""); }
                ;
                
tabel: identificator_complet;
%%

void yyerror(const char *s) { fprintf(stderr, "Eroare de sintaxa SQL: %s\n", s); }

int main() {
    printf("DataFlow Sense (V4.2 Final) - Introduceti SQL:\n");
    yyparse();
    return 0;
}