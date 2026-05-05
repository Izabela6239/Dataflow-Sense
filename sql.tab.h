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

#ifndef YY_YY_SQL_TAB_H_INCLUDED
# define YY_YY_SQL_TAB_H_INCLUDED
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
    DISTINCT = 259,                /* DISTINCT  */
    FROM = 260,                    /* FROM  */
    WHERE = 261,                   /* WHERE  */
    AND = 262,                     /* AND  */
    OR = 263,                      /* OR  */
    NOT = 264,                     /* NOT  */
    JOIN = 265,                    /* JOIN  */
    INNER = 266,                   /* INNER  */
    LEFT = 267,                    /* LEFT  */
    RIGHT = 268,                   /* RIGHT  */
    FULL = 269,                    /* FULL  */
    OUTER = 270,                   /* OUTER  */
    CROSS = 271,                   /* CROSS  */
    ON = 272,                      /* ON  */
    ORDER = 273,                   /* ORDER  */
    BY = 274,                      /* BY  */
    ASC = 275,                     /* ASC  */
    DESC = 276,                    /* DESC  */
    HAVING = 277,                  /* HAVING  */
    LIKE = 278,                    /* LIKE  */
    IN = 279,                      /* IN  */
    BETWEEN = 280,                 /* BETWEEN  */
    IS = 281,                      /* IS  */
    NULL_T = 282,                  /* NULL_T  */
    LIMIT = 283,                   /* LIMIT  */
    OFFSET = 284,                  /* OFFSET  */
    GROUP = 285,                   /* GROUP  */
    AS = 286,                      /* AS  */
    SUM = 287,                     /* SUM  */
    AVG = 288,                     /* AVG  */
    COUNT = 289,                   /* COUNT  */
    MIN = 290,                     /* MIN  */
    MAX = 291,                     /* MAX  */
    INSERT = 292,                  /* INSERT  */
    INTO = 293,                    /* INTO  */
    VALUES = 294,                  /* VALUES  */
    UPDATE = 295,                  /* UPDATE  */
    SET = 296,                     /* SET  */
    DELETE = 297,                  /* DELETE  */
    CREATE = 298,                  /* CREATE  */
    TABLE = 299,                   /* TABLE  */
    DROP = 300,                    /* DROP  */
    ALTER = 301,                   /* ALTER  */
    ADD = 302,                     /* ADD  */
    COLUMN = 303,                  /* COLUMN  */
    PRIMARY = 304,                 /* PRIMARY  */
    KEY = 305,                     /* KEY  */
    FOREIGN = 306,                 /* FOREIGN  */
    REFERENCES = 307,              /* REFERENCES  */
    DEFAULT = 308,                 /* DEFAULT  */
    CHECK = 309,                   /* CHECK  */
    UNIQUE = 310,                  /* UNIQUE  */
    EQ = 311,                      /* EQ  */
    GT = 312,                      /* GT  */
    LT = 313,                      /* LT  */
    GE = 314,                      /* GE  */
    LE = 315,                      /* LE  */
    NE = 316,                      /* NE  */
    WORD = 317,                    /* WORD  */
    NUMBER = 318,                  /* NUMBER  */
    STRING = 319                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "sql.y"

    char* str;

#line 132 "sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SQL_TAB_H_INCLUDED  */
