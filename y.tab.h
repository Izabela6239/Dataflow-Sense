/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SELECT = 258,                  /* SELECT  */
    FROM = 259,                    /* FROM  */
    WHERE = 260,                   /* WHERE  */
    WORD = 261,                    /* WORD  */
    EQ = 262,                      /* EQ  */
    GT = 263,                      /* GT  */
    LT = 264,                      /* LT  */
    AND = 265,                     /* AND  */
    OR = 266,                      /* OR  */
    JOIN = 267,                    /* JOIN  */
    ON = 268,                      /* ON  */
    ORDER = 269,                   /* ORDER  */
    BY = 270,                      /* BY  */
    ASC = 271,                     /* ASC  */
    DESC = 272,                    /* DESC  */
    HAVING = 273,                  /* HAVING  */
    LIKE = 274,                    /* LIKE  */
    LIMIT = 275,                   /* LIMIT  */
    GROUP = 276,                   /* GROUP  */
    SUM = 277,                     /* SUM  */
    AVG = 278,                     /* AVG  */
    COUNT = 279,                   /* COUNT  */
    MIN = 280,                     /* MIN  */
    MAX = 281,                     /* MAX  */
    NUMBER = 282                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define SELECT 258
#define FROM 259
#define WHERE 260
#define WORD 261
#define EQ 262
#define GT 263
#define LT 264
#define AND 265
#define OR 266
#define JOIN 267
#define ON 268
#define ORDER 269
#define BY 270
#define ASC 271
#define DESC 272
#define HAVING 273
#define LIKE 274
#define LIMIT 275
#define GROUP 276
#define SUM 277
#define AVG 278
#define COUNT 279
#define MIN 280
#define MAX 281
#define NUMBER 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "sql.y"

    char* str;
    int num;

#line 126 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
