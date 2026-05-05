%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int yylex();
void yyerror(const char *s);

/* Functie auxiliara pentru formatarea textului si alocare dinamica. 
   Ajuta la construirea frazelor complexe prin concatenarea fragmentelor de traducere. */
char* textf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    char* res = malloc(len + 1);
    if (!res) {
        fprintf(stderr, "Eroare de memorie.\n");
        exit(1);
    }

    va_start(args, fmt);
    vsnprintf(res, len + 1, fmt, args);
    va_end(args);
    return res;
}

/* Gestioneaza concatenarea a doua siruri de caractere cu un separator intre ele. 
   Verifica existenta sirurilor pentru a evita erori de tip NULL pointer. */
char* append_text(char* left, const char* separator, char* right) {
    if (left == NULL || strlen(left) == 0) {
        return right ? strdup(right) : strdup("");
    }
    if (right == NULL || strlen(right) == 0) {
        return strdup(left);
    }
    return textf("%s%s%s", left, separator, right);
}
%}

/* Uniunea defineste tipurile de date pe care le pot returna simbolurile gramaticale */
%union {
    char* str;
}

/* Definirea jetoanelor (tokens) primite de la analizorul lexical */
%token SELECT DISTINCT FROM WHERE AND OR NOT JOIN INNER LEFT RIGHT FULL OUTER CROSS ON
%token ORDER BY ASC DESC HAVING LIKE IN BETWEEN IS NULL_T LIMIT OFFSET GROUP AS
%token SUM AVG COUNT MIN MAX
%token INSERT INTO VALUES UPDATE SET DELETE
%token CREATE TABLE DROP ALTER ADD COLUMN PRIMARY KEY FOREIGN REFERENCES DEFAULT CHECK UNIQUE
%token EQ GT LT GE LE NE
%token <str> WORD NUMBER STRING

/* Definirea tipului sir de caractere pentru regulile neterminale */
%type <str> statement select_stmt insert_stmt update_stmt delete_stmt create_stmt drop_stmt alter_stmt
%type <str> select_prefix select_list select_item opt_alias expression expression_list opt_expression_list
%type <str> function_call aggregate_function table_ref join_list join_clause join_type opt_outer
%type <str> optional_where group_by_clause having_clause order_clause order_list order_item direction limit_clause
%type <str> condition comparator optional_not literal literal_list value_tuple value_tuple_list assignment assignment_list
%type <str> identifier column_list column_def column_def_list column_attrs column_attr data_type opt_column

/* Prioritati si asociativitate pentru evitarea conflictelor de parsare */
%left OR
%left AND
%right NOT
%nonassoc EQ GT LT GE LE NE LIKE IN BETWEEN IS
%left '+' '-'
%left '*' '/'

%%

/* Punctul de intrare in gramatica - proceseaza linii succesive */
input:
      | input linie
      ;

linie:
      '\n'
    | statement '\n'       { printf("\nTRADUCERE ANALITICA: %s\n\n", $1); }
    | statement ';' '\n'   { printf("\nTRADUCERE ANALITICA: %s\n\n", $1); }
    | error '\n'           { yyerrok; printf("Eroare de structura SQL detectata.\n"); }
    ;

/* Ramificarea catre tipul de comanda SQL detectat */
statement:
      select_stmt
    | insert_stmt
    | update_stmt
    | delete_stmt
    | create_stmt
    | drop_stmt
    | alter_stmt
    ;

/* Structura principala pentru interogari de tip SELECT */
select_stmt:
      SELECT select_prefix select_list FROM table_ref join_list optional_where group_by_clause having_clause order_clause limit_clause {
          $$ = textf("Selecteaza %s%s din %s%s%s%s%s%s%s",
                     $2, $3, $5, $6, $7, $8, $9, $10, $11);
      }
    ;

select_prefix:
      /* gol */ { $$ = strdup(""); }
    | DISTINCT  { $$ = strdup("valorile distincte pentru "); }
    ;

select_list:
      select_item                         { $$ = strdup($1); }
    | select_list ',' select_item         { $$ = append_text($1, ", ", $3); }
    ;

select_item:
      '*'                                 { $$ = strdup("toate coloanele"); }
    | expression opt_alias                { $$ = append_text($1, " ", $2); }
    ;

/* Alias opitional pentru coloane sau tabele (ex: AS alias_nume) */
opt_alias:
      /* gol */                           { $$ = strdup(""); }
    | AS WORD                             { $$ = textf("cu aliasul %s", $2); }
    | WORD                                { $$ = textf("cu aliasul %s", $1); }
    ;

/* Procesarea comenzilor de insertie a datelor */
insert_stmt:
      INSERT INTO identifier VALUES value_tuple {
          $$ = textf("Insereaza in tabelul %s valorile %s", $3, $5);
      }
    | INSERT INTO identifier '(' column_list ')' VALUES value_tuple_list {
          $$ = textf("Insereaza in tabelul %s, in coloanele %s, valorile %s", $3, $5, $8);
      }
    ;

/* Structura comenzilor de modificare a inregistrarilor */
update_stmt:
      UPDATE identifier SET assignment_list optional_where {
          $$ = textf("Actualizeaza tabelul %s setand %s%s", $2, $4, $5);
      }
    ;

/* Procesarea operatiilor de stergere date */
delete_stmt:
      DELETE FROM identifier optional_where {
          $$ = textf("Sterge randuri din tabelul %s%s", $3, $4);
      }
    ;

/* Definirea structurii pentru crearea tabelelor (DDL) */
create_stmt:
      CREATE TABLE identifier '(' column_def_list ')' {
          $$ = textf("Creeaza tabelul %s cu definitiile: %s", $3, $5);
      }
    ;

drop_stmt:
      DROP TABLE identifier {
          $$ = textf("Sterge tabelul %s", $3);
      }
    ;

alter_stmt:
      ALTER TABLE identifier ADD opt_column column_def {
          $$ = textf("Modifica tabelul %s adaugand coloana %s", $3, $6);
      }
    | ALTER TABLE identifier DROP opt_column identifier {
          $$ = textf("Modifica tabelul %s stergand coloana %s", $3, $6);
      }
    ;

opt_column:
      /* gol */                           { $$ = strdup(""); }
    | COLUMN                              { $$ = strdup(""); }
    ;

table_ref:
      identifier opt_alias                { $$ = append_text($1, " ", $2); }
    ;

/* Gestionarea listei de combinari (JOIN-uri) intre tabele */
join_list:
      /* gol */                           { $$ = strdup(""); }
    | join_list join_clause               { $$ = append_text($1, "", $2); }
    ;

join_clause:
      join_type JOIN table_ref ON condition {
          $$ = textf(", combinat prin %s cu %s pe baza conditiei %s", $1, $3, $5);
      }
    | CROSS JOIN table_ref {
          $$ = textf(", combinat cartezian cu %s", $3);
      }
    ;

join_type:
      /* gol */                           { $$ = strdup("JOIN"); }
    | INNER                               { $$ = strdup("INNER JOIN"); }
    | LEFT opt_outer                      { $$ = strdup("LEFT JOIN"); }
    | RIGHT opt_outer                     { $$ = strdup("RIGHT JOIN"); }
    | FULL opt_outer                      { $$ = strdup("FULL JOIN"); }
    ;

opt_outer:
      /* gol */                           { $$ = strdup(""); }
    | OUTER                               { $$ = strdup(""); }
    ;

optional_where:
      /* gol */                           { $$ = strdup(""); }
    | WHERE condition                     { $$ = textf(" unde %s", $2); }
    ;

group_by_clause:
      /* gol */                           { $$ = strdup(""); }
    | GROUP BY column_list                { $$ = textf(", grupat dupa %s", $3); }
    ;

having_clause:
      /* gol */                           { $$ = strdup(""); }
    | HAVING condition                    { $$ = textf(", pastrand grupurile unde %s", $2); }
    ;

order_clause:
      /* gol */                           { $$ = strdup(""); }
    | ORDER BY order_list                 { $$ = textf(", sortat dupa %s", $3); }
    ;

order_list:
      order_item                          { $$ = strdup($1); }
    | order_list ',' order_item           { $$ = append_text($1, ", ", $3); }
    ;

order_item:
      expression direction                { $$ = append_text($1, " ", $2); }
    ;

direction:
      /* gol */                           { $$ = strdup(""); }
    | ASC                                 { $$ = strdup("crescator"); }
    | DESC                                { $$ = strdup("descrescator"); }
    ;

limit_clause:
      /* gol */                           { $$ = strdup(""); }
    | LIMIT NUMBER                        { $$ = textf(", limitat la %s randuri", $2); }
    | LIMIT NUMBER OFFSET NUMBER          { $$ = textf(", limitat la %s randuri cu offset %s", $2, $4); }
    ;

/* Logica pentru conditii complexe (AND, OR, NOT, operatori speciali) */
condition:
      expression comparator expression    { $$ = textf("%s %s %s", $1, $2, $3); }
    | expression LIKE literal             { $$ = textf("%s seamana cu %s", $1, $3); }
    | expression IN '(' literal_list ')'  { $$ = textf("%s este in lista (%s)", $1, $4); }
    | expression BETWEEN expression AND expression {
          $$ = textf("%s este intre %s si %s", $1, $3, $5);
      }
    | expression IS optional_not NULL_T   { $$ = textf("%s este %sNULL", $1, $3); }
    | NOT condition                       { $$ = textf("NU (%s)", $2); }
    | condition AND condition             { $$ = textf("%s SI %s", $1, $3); }
    | condition OR condition              { $$ = textf("%s SAU %s", $1, $3); }
    | '(' condition ')'                   { $$ = textf("(%s)", $2); }
    ;

optional_not:
      /* gol */                           { $$ = strdup(""); }
    | NOT                                 { $$ = strdup("NOT "); }
    ;

comparator:
      EQ                                  { $$ = strdup("egal cu"); }
    | GT                                  { $$ = strdup("mai mare decat"); }
    | LT                                  { $$ = strdup("mai mic decat"); }
    | GE                                  { $$ = strdup("mai mare sau egal cu"); }
    | LE                                  { $$ = strassoc("mai mic sau egal cu"); }
    | NE                                  { $$ = strdup("diferit de"); }
    ;

assignment_list:
      assignment                          { $$ = strdup($1); }
    | assignment_list ',' assignment      { $$ = append_text($1, ", ", $3); }
    ;

assignment:
      identifier EQ expression            { $$ = textf("%s la %s", $1, $3); }
    ;

value_tuple_list:
      value_tuple                         { $$ = strdup($1); }
    | value_tuple_list ',' value_tuple    { $$ = append_text($1, "; ", $3); }
    ;

value_tuple:
      '(' literal_list ')'                { $$ = textf("(%s)", $2); }
    ;

literal_list:
      literal                             { $$ = strdup($1); }
    | literal_list ',' literal            { $$ = append_text($1, ", ", $3); }
    ;

literal:
      STRING                              { $$ = strdup($1); }
    | NUMBER                              { $$ = strdup($1); }
    | NULL_T                              { $$ = strdup("NULL"); }
    ;

expression_list:
      expression                          { $$ = strdup($1); }
    | expression_list ',' expression      { $$ = append_text($1, ", ", $3); }
    ;

opt_expression_list:
      /* gol */                           { $$ = strdup(""); }
    | expression_list                     { $$ = strdup($1); }
    ;

/* Expresii aritmetice - permite recursivitate pentru arbori adanci */
expression:
      identifier                          { $$ = strdup($1); }
    | literal                             { $$ = strdup($1); }
    | function_call                       { $$ = strdup($1); }
    | expression '+' expression           { $$ = textf("%s plus %s", $1, $3); }
    | expression '-' expression           { $$ = textf("%s minus %s", $1, $3); }
    | expression '*' expression           { $$ = textf("%s inmultit cu %s", $1, $3); }
    | expression '/' expression           { $$ = textf("%s impartit la %s", $1, $3); }
    | '(' expression ')'                  { $$ = textf("(%s)", $2); }
    ;

/* Gestionarea apelurilor de functii SQL (SUM, AVG, COUNT, etc) */
function_call:
      aggregate_function '(' expression ')' {
          $$ = textf("%s pentru %s", $1, $3);
      }
    | COUNT '(' expression ')' {
          $$ = textf("numarul de valori pentru %s", $3);
      }
    | COUNT '(' '*' ')' {
          $$ = strdup("numarul total de inregistrari");
      }
    | WORD '(' opt_expression_list ')' {
          $$ = textf("functia %s aplicata pe %s", $1, strlen($3) ? $3 : "fara argumente");
      }
    ;

aggregate_function:
      SUM                                 { $$ = strdup("suma"); }
    | AVG                                 { $$ = strdup("media"); }
    | MIN                                 { $$ = strdup("valoarea minima"); }
    | MAX                                 { $$ = strdup("valoarea maxima"); }
    ;

column_list:
      identifier                          { $$ = strdup($1); }
    | column_list ',' identifier          { $$ = append_text($1, ", ", $3); }
    ;

column_def_list:
      column_def                          { $$ = strdup($1); }
    | column_def_list ',' column_def      { $$ = append_text($1, "; ", $3); }
    ;

column_def:
      identifier data_type column_attrs   { $$ = textf("%s de tip %s%s%s", $1, $2, strlen($3) ? " " : "", $3); }
    ;

data_type:
      WORD                                { $$ = strdup($1); }
    | WORD '(' NUMBER ')'                 { $$ = textf("%s(%s)", $1, $3); }
    | WORD '(' NUMBER ',' NUMBER ')'      { $$ = textf("%s(%s,%s)", $1, $3, $5); }
    ;

column_attrs:
      /* gol */                           { $$ = strdup(""); }
    | column_attrs column_attr            { $$ = append_text($1, " ", $2); }
    ;

/* Atribute pentru coloane in CREATE TABLE */
column_attr:
      PRIMARY KEY                         { $$ = strdup("cheie primara"); }
    | FOREIGN KEY REFERENCES identifier '(' identifier ')' {
          $$ = textf("cheie straina catre %s(%s)", $4, $6);
      }
    | REFERENCES identifier '(' identifier ')' {
          $$ = textf("referinta catre %s(%s)", $2, $4);
      }
    | NOT NULL_T                          { $$ = strdup("obligatorie"); }
    | UNIQUE                              { $$ = strdup("unica"); }
    | DEFAULT literal                     { $$ = textf("cu valoare implicita %s", $2); }
    | CHECK '(' condition ')'              { $$ = textf("cu verificarea %s", $3); }
    ;

/* Identificatori - suporta formatul tabel.coloana */
identifier:
      WORD                                { $$ = strdup($1); }
    | WORD '.' WORD                       { $$ = textf("%s.%s", $1, $3); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Eroare de sintaxa SQL: %s\n", s);
}

int main() {
    printf("DataFlow Sense (V5.0 Extended SQL) - Introduceti SQL:\n");
    yyparse();
    return 0;
}