/* A Bison parser, made by GNU Bison 3.7.6.  */

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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 57 "parser.y"
 #include<vector> 

#line 52 "parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    REAL = 259,                    /* REAL  */
    STRING = 260,                  /* STRING  */
    ID = 261,                      /* ID  */
    TRUE = 262,                    /* TRUE  */
    FALSE = 263,                   /* FALSE  */
    OR = 264,                      /* OR  */
    LOCAL = 265,                   /* LOCAL  */
    NIL = 266,                     /* NIL  */
    UMINUS = 267,                  /* UMINUS  */
    MINUSMINUS = 268,              /* MINUSMINUS  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    WHILE = 271,                   /* WHILE  */
    FUNCTION = 272,                /* FUNCTION  */
    FOR = 273,                     /* FOR  */
    RETURN = 274,                  /* RETURN  */
    BREAK = 275,                   /* BREAK  */
    CONTINUE = 276,                /* CONTINUE  */
    AND = 277,                     /* AND  */
    NOT = 278,                     /* NOT  */
    ASSIGN = 279,                  /* ASSIGN  */
    PLUS = 280,                    /* PLUS  */
    MINUS = 281,                   /* MINUS  */
    MULT = 282,                    /* MULT  */
    DIVIDE = 283,                  /* DIVIDE  */
    PERCENT = 284,                 /* PERCENT  */
    NOTEQUAL = 285,                /* NOTEQUAL  */
    PLUSPLUS = 286,                /* PLUSPLUS  */
    GREATER = 287,                 /* GREATER  */
    LESSER = 288,                  /* LESSER  */
    GREATEREQUAL = 289,            /* GREATEREQUAL  */
    LESSEREQUAL = 290,             /* LESSEREQUAL  */
    EQUAL = 291,                   /* EQUAL  */
    LCBRACK = 292,                 /* LCBRACK  */
    RCBRACK = 293,                 /* RCBRACK  */
    LBRACK = 294,                  /* LBRACK  */
    RBRACK = 295,                  /* RBRACK  */
    LPAREN = 296,                  /* LPAREN  */
    RPAREN = 297,                  /* RPAREN  */
    SEMICOLON = 298,               /* SEMICOLON  */
    COMMA = 299,                   /* COMMA  */
    COLON = 300,                   /* COLON  */
    COLONCOLON = 301,              /* COLONCOLON  */
    DOT = 302,                     /* DOT  */
    DOTDOT = 303                   /* DOTDOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "parser.y"

	int intConst;
	double realConst;
	std::string *strConst;
	struct st_entry *st_entryVal;
	struct expr *expr_p;
	struct call *callVal;
	bool boolean;
	std::vector<expr*> *exprVec;
	struct stmt_t *stmt_pt;
	std::pair<expr*, expr*> *pairVal;
	std::vector<std::pair<expr*, expr*>* > *pairVec; 
	struct for_stmt *forVal; /* doesn't need to be pointer */

#line 132 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
