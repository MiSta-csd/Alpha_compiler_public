/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


/* 
						  Computer Science Department
					CS340 - Compilers ~ Project Spring 2022
					   Constantine Damaskinakis - csd3755
						  Minoas Stavrakakis - csd4120
						Demetrious Grammenidis - csd3933

 */
#include <assert.h>
#include <iostream>
#include <string>
#include <cstring>
#include "symtable.h"
#include "quads.h"
#include "actions.h"
#include "scoping.h"
#include "avm_structures.h"
#include <unistd.h>
#include <unordered_map>


int yyerror(std::string message);
bool hasError = false;

extern std::vector<quad> quad_vec;
/* extern std::stack<int> loop_stack; */
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern int yylex();
extern unsigned tmp_var_count;
extern void generate();

union values emptyval;

/* Auxiliary var for storing each rule's id value (e.g. entry["rule8.1"] = id) returned
 * from lookup (e.g at $1) */
std::unordered_map<std::string, struct st_entry*> st_entry_tmp;

/* In alpha a funcdef can be inside a function's scope so we needed to know if we are
 * inside a function 
 */
extern std::stack<struct st_entry*> func_stack;

static int loopcounter = 0;

void print_rules(std::string str) {
	 /* std::cout << "~ entered rule :\t " << str << std::endl; */
}


#line 124 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 58 "parser.y"
 #include<vector> 

#line 170 "parser.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    REAL = 259,
    STRING = 260,
    ID = 261,
    TRUE = 262,
    FALSE = 263,
    OR = 264,
    LOCAL = 265,
    NIL = 266,
    UMINUS = 267,
    MINUSMINUS = 268,
    IF = 269,
    ELSE = 270,
    WHILE = 271,
    FUNCTION = 272,
    FOR = 273,
    RETURN = 274,
    BREAK = 275,
    CONTINUE = 276,
    AND = 277,
    NOT = 278,
    ASSIGN = 279,
    PLUS = 280,
    MINUS = 281,
    MULT = 282,
    DIVIDE = 283,
    PERCENT = 284,
    NOTEQUAL = 285,
    PLUSPLUS = 286,
    GREATER = 287,
    LESSER = 288,
    GREATEREQUAL = 289,
    LESSEREQUAL = 290,
    EQUAL = 291,
    LCBRACK = 292,
    RCBRACK = 293,
    LBRACK = 294,
    RBRACK = 295,
    LPAREN = 296,
    RPAREN = 297,
    SEMICOLON = 298,
    COMMA = 299,
    COLON = 300,
    COLONCOLON = 301,
    DOT = 302,
    DOTDOT = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 59 "parser.y"

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

#line 245 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   141,   141,   142,   146,   163,   167,   177,   180,   183,
     186,   192,   203,   214,   217,   220,   227,   230,   235,   240,
     245,   250,   255,   264,   273,   282,   291,   296,   301,   301,
     314,   314,   326,   331,   338,   342,   352,   369,   388,   408,
     427,   447,   452,   478,   483,   487,   491,   497,   503,   518,
     535,   547,   553,   558,   571,   575,   580,   589,   593,   604,
     613,   616,   621,   629,   636,   643,   649,   655,   671,   689,
     697,   705,   717,   717,   727,   732,   763,   770,   790,   796,
     803,   823,   826,   829,   832,   835,   838,   843,   857,   874,
     881,   900,   907,   914,   932,   934,   948,   964,   980,   999,
    1006,  1016
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "REAL", "STRING", "ID",
  "TRUE", "FALSE", "OR", "LOCAL", "NIL", "UMINUS", "MINUSMINUS", "IF",
  "ELSE", "WHILE", "FUNCTION", "FOR", "RETURN", "BREAK", "CONTINUE", "AND",
  "NOT", "ASSIGN", "PLUS", "MINUS", "MULT", "DIVIDE", "PERCENT",
  "NOTEQUAL", "PLUSPLUS", "GREATER", "LESSER", "GREATEREQUAL",
  "LESSEREQUAL", "EQUAL", "LCBRACK", "RCBRACK", "LBRACK", "RBRACK",
  "LPAREN", "RPAREN", "SEMICOLON", "COMMA", "COLON", "COLONCOLON", "DOT",
  "DOTDOT", "$accept", "program", "stmts", "stmt", "expr", "$@1", "$@2",
  "M", "term", "assignexpr", "primary", "lvalue", "tableitem", "member",
  "call", "callsuffix", "normcall", "methodcall", "elist", "objectdef",
  "indexed", "indexedelem", "block", "$@3", "funcname", "funcprefix",
  "funcargs", "funcbody", "funcdef", "const", "idlist", "ifprefix",
  "elseprefix", "ifstmt", "whilestart", "whilecond", "whilestmt",
  "forprefix", "forstmt", "N", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,  -163,  -163,  -163,  -163,  -163,  -163,     5,  -163,     3,
     -27,  -163,    11,   -16,   196,     0,    18,   295,   295,     3,
      51,   207,   251,  -163,    93,    74,    16,  -163,   318,  -163,
    -163,  -163,   239,  -163,  -163,    47,  -163,  -163,    71,  -163,
    -163,    16,  -163,    72,  -163,  -163,  -163,  -163,  -163,   109,
      36,    47,   295,  -163,  -163,   295,  -163,   340,  -163,  -163,
    -163,  -163,    36,  -163,    16,   295,   509,   -34,     8,  -163,
     384,    85,  -163,  -163,  -163,  -163,  -163,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,  -163,  -163,
     295,  -163,   295,   295,   127,   134,  -163,  -163,  -163,   295,
     135,  -163,   139,   111,   131,   295,    16,   295,   107,   406,
      66,  -163,   152,    89,  -163,   295,  -163,   114,  -163,   112,
    -163,  -163,    68,    68,  -163,  -163,  -163,   536,   103,   103,
     103,   103,   536,   509,   450,    38,  -163,   120,   472,  -163,
    -163,    48,  -163,  -163,  -163,    16,   428,  -163,    58,   112,
    -163,  -163,  -163,   295,   509,  -163,   295,   295,   295,  -163,
    -163,   295,  -163,  -163,   146,  -163,  -163,  -163,   295,   494,
      62,   524,   548,    63,  -163,    16,   362,  -163,  -163,  -163,
    -163,  -163,  -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    81,    82,    83,    48,    85,    86,     0,    84,     0,
       0,    94,    76,     0,     0,     0,     0,     0,     0,     0,
      72,    66,     0,    15,     0,     0,     2,     5,     0,    32,
      16,    41,    43,    54,    51,    44,    45,    13,     0,    14,
      47,     0,     7,     0,     8,    99,     9,    10,    49,     0,
      39,     0,     0,    75,    77,    66,   100,     0,    11,    12,
      36,    35,    37,    74,     0,     0,    64,     0,     0,    69,
       0,     0,    50,     1,     4,    30,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,    40,
       0,    38,     0,    66,     0,     0,    58,    60,    61,     0,
       0,    57,    89,     0,    92,     0,     0,    66,     0,     0,
       0,   101,     0,     0,    67,     0,    68,     0,    34,    46,
      33,    33,    17,    18,    19,    20,    21,    27,    22,    24,
      23,    25,    26,    42,     0,     0,    52,     0,     0,    55,
      87,     0,    79,    80,    91,     0,     0,    96,     0,     0,
      90,    33,    73,     0,    65,    70,    66,     0,     0,    53,
      62,    66,    56,    78,     0,    93,    95,    99,     0,     0,
       0,    31,    29,     0,    88,     0,     0,    71,    59,    63,
      99,    97,    98
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,   100,   -25,   -14,  -163,  -163,  -106,  -163,  -163,
    -163,    37,  -163,  -163,    41,  -163,   -23,  -163,   -53,  -163,
    -163,    50,    73,  -163,  -163,  -163,  -163,  -163,     9,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -162,
    -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,   121,   120,   157,    29,    30,
      31,    32,    33,    34,    35,    96,    97,    98,    67,    36,
      68,    69,    37,    64,    54,    38,   103,   143,    39,    40,
     141,    41,   145,    42,    43,   106,    44,    45,    46,   107,
      47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    74,   110,    60,    61,   175,   114,    66,    70,     4,
     115,    48,   101,     7,    52,   158,   104,    53,   182,     1,
       2,     3,     4,     5,     6,    55,     7,     8,   101,     9,
      10,    71,    11,    12,    13,    14,    15,    16,   109,    17,
     135,    66,    18,    58,    49,   168,    50,    19,   116,    24,
      51,   113,   117,    20,   148,    21,    62,    22,   108,    23,
      51,    59,    24,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    73,    92,   133,    93,   134,    66,
     160,   147,   115,    94,    95,   138,    99,    74,    93,    63,
     163,   146,   164,    66,   100,    79,    80,    81,    75,    72,
     167,   154,   115,   170,   178,   179,   115,   115,   173,   151,
     115,    76,   102,   105,    77,    78,    79,    80,    81,    82,
     165,    83,    84,    85,    86,    87,    12,   119,    77,    78,
      79,    80,    81,   136,   153,    -1,    -1,    -1,    -1,   169,
     137,   139,    66,   171,   172,   140,   144,    66,    20,   149,
     180,    65,   174,   156,   176,     1,     2,     3,     4,     5,
       6,   161,     7,     8,   112,     9,    10,   155,    11,    12,
      13,    14,    15,    16,     0,    17,   142,     0,    18,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,    20,
     152,    21,     0,    22,     0,    23,     0,     0,    24,     1,
       2,     3,     4,     5,     6,     0,     7,     8,     0,     9,
       1,     2,     3,     4,     5,     6,     0,     7,     8,    17,
       9,     0,    18,     0,     0,     0,     0,    19,     0,     0,
      17,     0,     0,    18,     0,    21,     0,    22,    19,    56,
       0,     0,    24,     0,    65,     0,    21,     0,    22,     0,
       0,     0,    89,    24,     1,     2,     3,     4,     5,     6,
       0,     7,     8,    90,     9,     0,     0,     0,    12,     0,
      91,     0,     0,     0,    17,     0,     0,    18,    92,     0,
      93,     0,    19,     0,     0,     0,    94,    95,     0,     0,
      21,     0,    22,     0,     0,     0,     0,    24,     1,     2,
       3,     4,     5,     6,     0,     7,     8,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,    18,     0,     0,     0,     0,    19,    75,     0,     0,
       0,     0,     0,     0,    21,     0,    22,     0,     0,     0,
      76,    24,     0,    77,    78,    79,    80,    81,    82,    75,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,    88,    76,     0,     0,    77,    78,    79,    80,    81,
      82,    75,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,     0,   111,    76,     0,     0,    77,    78,    79,
      80,    81,    82,    75,    83,    84,    85,    86,    87,     0,
       0,     0,     0,     0,     0,   181,    76,     0,     0,    77,
      78,    79,    80,    81,    82,    75,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,   118,     0,    76,     0,
       0,    77,    78,    79,    80,    81,    82,    75,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,   150,     0,
      76,     0,     0,    77,    78,    79,    80,    81,    82,    75,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
     166,     0,    76,     0,     0,    77,    78,    79,    80,    81,
      82,    75,    83,    84,    85,    86,    87,     0,     0,     0,
     159,     0,     0,     0,    76,     0,     0,    77,    78,    79,
      80,    81,    82,    75,    83,    84,    85,    86,    87,     0,
       0,     0,   162,     0,     0,     0,    76,     0,    75,    77,
      78,    79,    80,    81,    82,     0,    83,    84,    85,    86,
      87,    76,   177,     0,    77,    78,    79,    80,    81,    82,
       0,    83,    84,    85,    86,    87,    76,     0,     0,    77,
      78,    79,    80,    81,    82,     0,    83,    84,    85,    86,
      87,    77,    78,    79,    80,    81,    -1,     0,    83,    84,
      85,    86,    -1,    77,    78,    79,    80,    81,    82,     0,
      83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      14,    26,    55,    17,    18,   167,    40,    21,    22,     6,
      44,     6,    35,    10,    41,   121,    41,     6,   180,     3,
       4,     5,     6,     7,     8,    41,    10,    11,    51,    13,
      14,    22,    16,    17,    18,    19,    20,    21,    52,    23,
      93,    55,    26,    43,    41,   151,     9,    31,    40,    46,
       9,    65,    44,    37,   107,    39,    19,    41,    49,    43,
      19,    43,    46,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,    39,    90,    41,    92,    93,
      42,   106,    44,    47,    48,    99,    39,   112,    41,    38,
      42,   105,    44,   107,    47,    27,    28,    29,     9,     6,
      42,   115,    44,   156,    42,    42,    44,    44,   161,    43,
      44,    22,    41,    41,    25,    26,    27,    28,    29,    30,
     145,    32,    33,    34,    35,    36,    17,    42,    25,    26,
      27,    28,    29,     6,    45,    32,    33,    34,    35,   153,
       6,     6,   156,   157,   158,     6,    15,   161,    37,    42,
     175,    37,     6,    41,   168,     3,     4,     5,     6,     7,
       8,    41,    10,    11,    64,    13,    14,   117,    16,    17,
      18,    19,    20,    21,    -1,    23,   103,    -1,    26,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    -1,    41,    -1,    43,    -1,    -1,    46,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    13,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    23,
      13,    -1,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      23,    -1,    -1,    26,    -1,    39,    -1,    41,    31,    43,
      -1,    -1,    46,    -1,    37,    -1,    39,    -1,    41,    -1,
      -1,    -1,    13,    46,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    24,    13,    -1,    -1,    -1,    17,    -1,
      31,    -1,    -1,    -1,    23,    -1,    -1,    26,    39,    -1,
      41,    -1,    31,    -1,    -1,    -1,    47,    48,    -1,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    46,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    31,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    41,    -1,    -1,    -1,
      22,    46,    -1,    25,    26,    27,    28,    29,    30,     9,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    22,    -1,    -1,    25,    26,    27,    28,    29,
      30,     9,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    22,    -1,    -1,    25,    26,    27,
      28,    29,    30,     9,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    22,    -1,    -1,    25,
      26,    27,    28,    29,    30,     9,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    22,    -1,
      -1,    25,    26,    27,    28,    29,    30,     9,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      22,    -1,    -1,    25,    26,    27,    28,    29,    30,     9,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    22,    -1,    -1,    25,    26,    27,    28,    29,
      30,     9,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    22,    -1,    -1,    25,    26,    27,
      28,    29,    30,     9,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    22,    -1,     9,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    22,    38,    -1,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    22,    -1,    -1,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    13,
      14,    16,    17,    18,    19,    20,    21,    23,    26,    31,
      37,    39,    41,    43,    46,    50,    51,    52,    53,    57,
      58,    59,    60,    61,    62,    63,    68,    71,    74,    77,
      78,    80,    82,    83,    85,    86,    87,    89,     6,    41,
      60,    63,    41,     6,    73,    41,    43,    53,    43,    43,
      53,    53,    60,    38,    72,    37,    53,    67,    69,    70,
      53,    77,     6,     0,    52,     9,    22,    25,    26,    27,
      28,    29,    30,    32,    33,    34,    35,    36,    43,    13,
      24,    31,    39,    41,    47,    48,    64,    65,    66,    39,
      47,    65,    41,    75,    52,    41,    84,    88,    77,    53,
      67,    43,    51,    53,    40,    44,    40,    44,    42,    42,
      55,    54,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    67,     6,     6,    53,     6,
       6,    79,    71,    76,    15,    81,    53,    52,    67,    42,
      42,    43,    38,    45,    53,    70,    41,    56,    56,    40,
      42,    41,    40,    42,    44,    52,    42,    42,    56,    53,
      67,    53,    53,    67,     6,    88,    53,    38,    42,    42,
      52,    43,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    53,
      55,    53,    53,    56,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    59,    59,    59,    59,    59,    60,    60,
      60,    60,    61,    61,    62,    62,    62,    63,    63,    63,
      64,    64,    65,    66,    67,    67,    67,    68,    68,    69,
      69,    70,    72,    71,    71,    73,    73,    74,    75,    76,
      77,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      80,    81,    82,    82,    83,    84,    85,    86,    87,    88,
      89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     0,     5,
       0,     5,     1,     0,     3,     2,     2,     2,     2,     2,
       2,     1,     3,     1,     1,     1,     3,     1,     1,     2,
       2,     1,     3,     4,     1,     3,     4,     2,     2,     6,
       1,     1,     3,     5,     1,     3,     0,     3,     3,     1,
       3,     5,     0,     4,     2,     1,     0,     2,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       4,     1,     2,     4,     1,     3,     3,     7,     7,     0,
       2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 141 "parser.y"
                                                                {	/* std::cout << "Finished reading statements\n"; */}
#line 1636 "parser.cpp"
    break;

  case 4:
#line 146 "parser.y"
                                                        {	
											print_rules("2.1 stmts -> stmts stmt");
											if(!hasError) {
												if(!(yyvsp[-1].stmt_pt) && !(yyvsp[0].stmt_pt))
													(yyval.stmt_pt) = NULL;
												else if(!(yyvsp[-1].stmt_pt)) {
													(yyval.stmt_pt) = (yyvsp[0].stmt_pt);
												}else if(!(yyvsp[0].stmt_pt))
													(yyval.stmt_pt) = (yyvsp[-1].stmt_pt);
												else {
													(yyval.stmt_pt) = new stmt_t();
													(yyval.stmt_pt)->breakList = mergelist((yyvsp[-1].stmt_pt)->breakList, (yyvsp[0].stmt_pt)->breakList);
													(yyval.stmt_pt)->contList = mergelist((yyvsp[-1].stmt_pt)->contList,  (yyvsp[0].stmt_pt)->contList);
													(yyval.stmt_pt)->retList = mergelist((yyvsp[-1].stmt_pt)->retList, (yyvsp[0].stmt_pt)->retList);
												}
											}
										}
#line 1658 "parser.cpp"
    break;

  case 5:
#line 163 "parser.y"
                                                                        {	print_rules("2.2 stmts -> ε");	(yyval.stmt_pt) = (yyvsp[0].stmt_pt);}
#line 1664 "parser.cpp"
    break;

  case 6:
#line 167 "parser.y"
                                                        {	print_rules("3.1 stmt -> expr ;");
											resettemp();
											if((yyvsp[-1].expr_p) && (yyvsp[-1].expr_p)->type == BOOLEXPR_E) {
												backpatch((yyvsp[-1].expr_p)->truelist, get_next_quad());
        										backpatch((yyvsp[-1].expr_p)->falselist, get_next_quad() + 2);
												emit_branch_assign_quads((yyvsp[-1].expr_p));
												(yyval.stmt_pt) = new stmt_t();// new stmt_t calls make_stmt
											}else
												(yyval.stmt_pt) = NULL;
	  									}
#line 1679 "parser.cpp"
    break;

  case 7:
#line 177 "parser.y"
                                                                        {	print_rules("3.2 stmt -> ifstmt");
											(yyval.stmt_pt) = (yyvsp[0].stmt_pt);
										}
#line 1687 "parser.cpp"
    break;

  case 8:
#line 180 "parser.y"
                                                                        {	print_rules("3.3 stmt -> whilestmt");
											(yyval.stmt_pt) = (yyvsp[0].stmt_pt);
										}
#line 1695 "parser.cpp"
    break;

  case 9:
#line 183 "parser.y"
                                                                        {	print_rules("3.4 stmt -> forstmt");
											(yyval.stmt_pt) = (yyvsp[0].stmt_pt);
										}
#line 1703 "parser.cpp"
    break;

  case 10:
#line 186 "parser.y"
                                                                {	print_rules("3.5 stmt -> returnstmt");
											if(!hasError) {
												(yyval.stmt_pt) = new stmt_t();
												(yyval.stmt_pt)->retList = newlist((yyvsp[0].intConst));
											}
										}
#line 1714 "parser.cpp"
    break;

  case 11:
#line 192 "parser.y"
                                                                {	print_rules("3.6 stmt -> BREAK ;");			
											if(!loopcounter) {
											/* if(loop_stack.empty()) { */
												yyerror("break stmt outside loop has no use");
												(yyval.stmt_pt) = NULL;
											}else {// we are in loop for sure
												(yyval.stmt_pt) = new stmt_t();
												(yyval.stmt_pt)->breakList = get_current_quad();// newlist(get_next_quad();
												emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
											}
										}
#line 1730 "parser.cpp"
    break;

  case 12:
#line 203 "parser.y"
                                                        {	print_rules("3.7 stmt -> CONTINUE ;");
											if(!loopcounter) {
											/* if(loop_stack.empty()) { */
												yyerror("continue stmt outside loop has no use");
												(yyval.stmt_pt) = NULL;
											}else {// we are in loop for sure
												(yyval.stmt_pt) = new stmt_t();
												(yyval.stmt_pt)->contList = newlist(get_current_quad());
												emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
											}
										}
#line 1746 "parser.cpp"
    break;

  case 13:
#line 214 "parser.y"
                                                                        {	print_rules("3.8 stmt -> block");
											(yyval.stmt_pt) = (yyvsp[0].stmt_pt);
										}
#line 1754 "parser.cpp"
    break;

  case 14:
#line 217 "parser.y"
                                                                        {	print_rules("3.9 stmt -> funcdef");
											(yyval.stmt_pt) = new stmt_t();
										}
#line 1762 "parser.cpp"
    break;

  case 15:
#line 220 "parser.y"
                                                                        {	print_rules("3.10 stmt -> ;");	(yyval.stmt_pt) = NULL;
											// $$ = new stmt_t();
											(yyval.stmt_pt) = NULL;
										}
#line 1771 "parser.cpp"
    break;

  case 16:
#line 227 "parser.y"
                                                        {	print_rules("4.1 expr -> assignexpr");
	  										(yyval.expr_p) = (yyvsp[0].expr_p);
	  									}
#line 1779 "parser.cpp"
    break;

  case 17:
#line 230 "parser.y"
                                                                {	print_rules("4.2 expr -> expr + expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												(yyval.expr_p) = expr_action_expr((yyvsp[-2].expr_p), ADD_OP, (yyvsp[0].expr_p), exp_type_to_string((yyvsp[-2].expr_p)) + " + " + exp_type_to_string((yyvsp[0].expr_p)));
											}
										}
#line 1789 "parser.cpp"
    break;

  case 18:
#line 235 "parser.y"
                                                                {	print_rules("4.3 expr -> expr - expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												(yyval.expr_p) = expr_action_expr((yyvsp[-2].expr_p), SUB_OP, (yyvsp[0].expr_p), exp_type_to_string((yyvsp[-2].expr_p)) + " - " + exp_type_to_string((yyvsp[0].expr_p)));
											}
										}
#line 1799 "parser.cpp"
    break;

  case 19:
#line 240 "parser.y"
                                                                {	print_rules("4.4 expr -> expr * expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												(yyval.expr_p) = expr_action_expr((yyvsp[-2].expr_p), MUL_OP, (yyvsp[0].expr_p), exp_type_to_string((yyvsp[-2].expr_p)) + " * " + exp_type_to_string((yyvsp[0].expr_p)));
											}
										}
#line 1809 "parser.cpp"
    break;

  case 20:
#line 245 "parser.y"
                                                                {	print_rules("4.5 expr -> expr / expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												(yyval.expr_p) = expr_action_expr((yyvsp[-2].expr_p), DIV_OP, (yyvsp[0].expr_p), exp_type_to_string((yyvsp[-2].expr_p)) + " / " + exp_type_to_string((yyvsp[0].expr_p)));
											}
										}
#line 1819 "parser.cpp"
    break;

  case 21:
#line 250 "parser.y"
                                                                {	print_rules("4.6 expr -> expr \% expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												(yyval.expr_p) = expr_action_expr((yyvsp[-2].expr_p), MOD_OP, (yyvsp[0].expr_p), exp_type_to_string((yyvsp[-2].expr_p)) + " % " + exp_type_to_string((yyvsp[0].expr_p)));
											}
										}
#line 1829 "parser.cpp"
    break;

  case 22:
#line 255 "parser.y"
                                                                {	print_rules("4.7 expr -> expr > expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												bool is_arith = check_arith((yyvsp[-2].expr_p), "expr greater expr. Invalid use of comparison operator on non arithmetic type expression")
												&& check_arith((yyvsp[0].expr_p), "expr greater expr. Invalid use of comparison operator on non arithmetic type expression");
												if(is_arith) {
													(yyval.expr_p) = expr_compare_expr((yyvsp[-2].expr_p), IF_GREATER_OP, (yyvsp[0].expr_p));
												}
											}
										}
#line 1843 "parser.cpp"
    break;

  case 23:
#line 264 "parser.y"
                                                        {	print_rules("4.8 expr -> expr >= expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												bool is_arith = check_arith((yyvsp[-2].expr_p), "expr greaterequal expr. Invalid use of comparison operator on non arithmetic type expression")
												&& check_arith((yyvsp[0].expr_p), "expr greaterequal expr. Invalid use of comparison operator on non arithmetic type expression");
												if(is_arith) {
													(yyval.expr_p) = expr_compare_expr((yyvsp[-2].expr_p), IF_GREATER_OP, (yyvsp[0].expr_p));
												}
											}
										}
#line 1857 "parser.cpp"
    break;

  case 24:
#line 273 "parser.y"
                                                                {	print_rules("4.9 expr -> expr < expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												bool is_arith = check_arith((yyvsp[-2].expr_p), "expr lesser expr. Invalid use of comparison operator on non arithmetic type expression")
												&& check_arith((yyvsp[0].expr_p), "expr lesser expr. Invalid use of comparison operator on non arithmetic type expression");
												if(is_arith) {
													(yyval.expr_p) = expr_compare_expr((yyvsp[-2].expr_p), IF_LESS_OP, (yyvsp[0].expr_p));
												}
											}
										}
#line 1871 "parser.cpp"
    break;

  case 25:
#line 282 "parser.y"
                                                        {	print_rules("4.10 expr -> expr <= expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												bool is_arith = check_arith((yyvsp[-2].expr_p), "expr lessereq expr. Invalid use of comparison operator on non arithmetic type expression")
												&& check_arith((yyvsp[0].expr_p), "expr lessereq expr. Invalid use of comparison operator on non arithmetic type expression");
												if(is_arith) {
													(yyval.expr_p) = expr_compare_expr((yyvsp[-2].expr_p), IF_LESSEQ_OP, (yyvsp[0].expr_p));
												}
											}
										}
#line 1885 "parser.cpp"
    break;

  case 26:
#line 291 "parser.y"
                                                                {	print_rules("4.11 expr -> expr == expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												(yyval.expr_p) = expr_compare_expr((yyvsp[-2].expr_p), IF_EQ_OP, (yyvsp[0].expr_p));
											}
										}
#line 1895 "parser.cpp"
    break;

  case 27:
#line 296 "parser.y"
                                                        {	print_rules("4.12 expr -> expr != expr");
											if((yyvsp[-2].expr_p) && (yyvsp[0].expr_p)) {
												(yyval.expr_p) = expr_compare_expr((yyvsp[-2].expr_p), IF_NOTEQ_OP, (yyvsp[0].expr_p));
											}
										}
#line 1905 "parser.cpp"
    break;

  case 28:
#line 301 "parser.y"
                                   {(yyvsp[-1].expr_p) = true_test((yyvsp[-1].expr_p));}
#line 1911 "parser.cpp"
    break;

  case 29:
#line 302 "parser.y"
                                                                                {	print_rules("4.13 expr -> expr AND expr");
											if((yyvsp[-4].expr_p) && (yyvsp[0].expr_p)) {
												expr *expr2 = true_test((yyvsp[0].expr_p));
												backpatch((yyvsp[-4].expr_p)->truelist, (yyvsp[-1].intConst));
												union values val;// ginetai apotimhsh ths logikhs ekfrashs amesws kai apo8 sto BOOLEX quad
												val.boolConst = (yyvsp[-4].expr_p)->value.boolConst && expr2->value.boolConst;

												(yyval.expr_p) = new expr(BOOLEXPR_E, newtemp(), NULL, val);
												(yyval.expr_p)->truelist = expr2->truelist;
												(yyval.expr_p)->falselist = merge((yyvsp[-4].expr_p)->falselist, expr2->falselist);
											}
										}
#line 1928 "parser.cpp"
    break;

  case 30:
#line 314 "parser.y"
                                  {(yyvsp[-1].expr_p) = true_test((yyvsp[-1].expr_p));}
#line 1934 "parser.cpp"
    break;

  case 31:
#line 315 "parser.y"
                                                                                {	print_rules("4.14 expr -> expr OR expr");
											if((yyvsp[-4].expr_p) && (yyvsp[0].expr_p)) {
												expr *expr2 = true_test((yyvsp[0].expr_p));
												backpatch((yyvsp[-4].expr_p)->falselist, (yyvsp[-1].intConst));
												union values val;// ginetai apotimhsh ths logikhs ekfrashs amesws kai apo8 sto BOOLEX quad
												val.boolConst = (yyvsp[-4].expr_p)->value.boolConst || expr2->value.boolConst;
												(yyval.expr_p) = new expr(BOOLEXPR_E, newtemp(), NULL, val);
												(yyval.expr_p)->falselist = expr2->falselist;
												(yyval.expr_p)->truelist = merge((yyvsp[-4].expr_p)->truelist, expr2->truelist);
											}
										}
#line 1950 "parser.cpp"
    break;

  case 32:
#line 326 "parser.y"
                                                                        {	print_rules("4.15 expr -> term");
											(yyval.expr_p) = (yyvsp[0].expr_p);
										}
#line 1958 "parser.cpp"
    break;

  case 33:
#line 331 "parser.y"
                                                                                {	
											print_rules("4+ M -> ε");
											(yyval.intConst) = get_next_quad();
										}
#line 1967 "parser.cpp"
    break;

  case 34:
#line 338 "parser.y"
                                                {	
											print_rules("5.1 term -> ( expr )");
											(yyval.expr_p) = (yyvsp[-1].expr_p);
	  									}
#line 1976 "parser.cpp"
    break;

  case 35:
#line 342 "parser.y"
                                                        {	
											print_rules("5.2 term -> - expr");
											if((yyvsp[0].expr_p)) {
												check_arith((yyvsp[0].expr_p), "MINUS expr \%UMINUS");
												(yyval.expr_p) = newexpr(ARITHEXPR_E);
												(yyval.expr_p)->sym = (istempexpr((yyvsp[0].expr_p))) ? (yyvsp[0].expr_p)->sym : newtemp();
												emit(UMINUS_OP, (yyval.expr_p), (yyvsp[0].expr_p), NULL, get_next_quad(), yylineno);
											}
										}
#line 1990 "parser.cpp"
    break;

  case 36:
#line 352 "parser.y"
                                                                        {	
											print_rules("5.3 term -> NOT expr");
											if((yyvsp[0].expr_p)) {
												(yyval.expr_p) = true_test((yyvsp[0].expr_p));
												std::vector<unsigned> *tmp = (yyval.expr_p)->truelist;
												(yyval.expr_p)->truelist = (yyval.expr_p)->falselist;
												(yyval.expr_p)->falselist = tmp;
												(yyval.expr_p)->type = BOOLEXPR_E;// if not boolexpr it won't be patched
												/* if($$->type != BOOLEXPR_E) { */
												/* 	backpatch($$->truelist, get_next_quad()); */
												/* 	backpatch($$->falselist, get_next_quad() + 2); */
												/* 	expr *e = newexpr(VAR_E); */
												/* 	e->sym = newtemp(); */
												/* 	emit_branch_assign_quads(e); */
												/* } */
											}
										}
#line 2012 "parser.cpp"
    break;

  case 37:
#line 369 "parser.y"
                                                                {
											print_rules("5.4 term -> ++ lvalue");
											if((yyvsp[0].expr_p) && (yyvsp[0].expr_p)->sym->type == USER_FUNC || (yyvsp[0].expr_p)->sym->type == LIB_FUNC){
												yyerror("invalid assignment (lvalue is a function)");
											}
											if((yyvsp[0].expr_p)) {
												if((yyvsp[0].expr_p)->type == TABLEITEM_E) {
													(yyval.expr_p) = emit_iftableitem((yyvsp[0].expr_p));
													emit(ADD_OP, (yyval.expr_p), newexpr_constint(1), (yyval.expr_p), get_next_quad(), yylineno);
													emit(TABLESETELEM_OP, (yyvsp[0].expr_p), (yyvsp[0].expr_p)->index, (yyval.expr_p), get_next_quad(), yylineno);
												}
												else {
													emit(ADD_OP, (yyvsp[0].expr_p), newexpr_constint(1), (yyvsp[0].expr_p), get_next_quad(), yylineno);
													(yyval.expr_p) = newexpr(ARITHEXPR_E);
													(yyval.expr_p)->sym = newtemp();
													emit(ASSIGN_OP, (yyval.expr_p), (yyvsp[0].expr_p), NULL, get_next_quad(), yylineno);
												}
											}
										}
#line 2036 "parser.cpp"
    break;

  case 38:
#line 388 "parser.y"
                                                                {
											print_rules("5.5 term -> lvalue ++");
											if((yyvsp[-1].expr_p) && (yyvsp[-1].expr_p)->sym->type == USER_FUNC || (yyvsp[-1].expr_p)->sym->type == LIB_FUNC){
												yyerror("invalid assignment (lvalue is a function)");
											}
											if ((yyvsp[-1].expr_p)) {
												(yyval.expr_p) = newexpr(VAR_E);
												(yyval.expr_p)->sym = newtemp();
												if((yyvsp[-1].expr_p)->type == TABLEITEM_E) {
													expr *val = emit_iftableitem((yyvsp[-1].expr_p));
													emit(ASSIGN_OP, (yyval.expr_p), val, NULL, get_next_quad(), yylineno);
													emit(ADD_OP, val, newexpr_constint(1), val, get_next_quad(), yylineno);
													emit(TABLESETELEM_OP, (yyvsp[-1].expr_p), (yyvsp[-1].expr_p)->index, val, get_next_quad(), yylineno);
												}
												else {
													emit(ASSIGN_OP, (yyval.expr_p), (yyvsp[-1].expr_p), NULL, get_next_quad(), yylineno);
													emit(ADD_OP, (yyvsp[-1].expr_p), newexpr_constint(1), (yyvsp[-1].expr_p), get_next_quad(), yylineno);
												}
											}
										}
#line 2061 "parser.cpp"
    break;

  case 39:
#line 408 "parser.y"
                                                                {
											print_rules("5.6 term -> -- lvalue");
											if((yyvsp[0].expr_p) && (yyvsp[0].expr_p)->sym->type == USER_FUNC || (yyvsp[0].expr_p)->sym->type == LIB_FUNC){
												yyerror("invalid assignment (lvalue is a function)");
											}
											if((yyvsp[0].expr_p)) {
												if((yyvsp[0].expr_p)->type == TABLEITEM_E) {
													(yyval.expr_p) = emit_iftableitem((yyvsp[0].expr_p));
													emit(SUB_OP, (yyval.expr_p), newexpr_constint(1), (yyval.expr_p), get_next_quad(), yylineno);
													emit(TABLESETELEM_OP, (yyvsp[0].expr_p), (yyvsp[0].expr_p)->index, (yyval.expr_p), get_next_quad(), yylineno);
												}
												else {
													emit(SUB_OP, (yyvsp[0].expr_p), newexpr_constint(1), (yyvsp[0].expr_p), get_next_quad(), yylineno);
													(yyval.expr_p) = newexpr(ARITHEXPR_E);
													(yyval.expr_p)->sym = newtemp();
													emit(ASSIGN_OP, (yyval.expr_p), (yyvsp[0].expr_p), NULL, get_next_quad(), yylineno);
												}
											}
										}
#line 2085 "parser.cpp"
    break;

  case 40:
#line 427 "parser.y"
                                                                {
											print_rules("5.7 term ->  lvalue --");
											if((yyvsp[-1].expr_p) && (yyvsp[-1].expr_p)->sym->type == USER_FUNC || (yyvsp[-1].expr_p)->sym->type == LIB_FUNC){
												yyerror("invalid assignment (lvalue is a function)");
											}
											if((yyvsp[-1].expr_p)) {
												(yyval.expr_p) = newexpr(VAR_E);
												(yyval.expr_p)->sym = newtemp();
												if((yyvsp[-1].expr_p)->type == TABLEITEM_E) {
													expr *val = emit_iftableitem((yyvsp[-1].expr_p));
													emit(ASSIGN_OP, (yyval.expr_p), val, NULL, get_next_quad(), yylineno);
													emit(SUB_OP, val, newexpr_constint(1), val, get_next_quad(), yylineno);
													emit(TABLESETELEM_OP, (yyvsp[-1].expr_p), (yyvsp[-1].expr_p)->index, val, get_next_quad(), yylineno);
												}
												else {
													emit(ASSIGN_OP, (yyval.expr_p), (yyvsp[-1].expr_p), NULL, get_next_quad(), yylineno);
													emit(SUB_OP, (yyvsp[-1].expr_p), newexpr_constint(1), (yyvsp[-1].expr_p), get_next_quad(), yylineno);
												}
											}
										}
#line 2110 "parser.cpp"
    break;

  case 41:
#line 447 "parser.y"
                                                                        {	print_rules("5.8 term -> primary");
											(yyval.expr_p) = (yyvsp[0].expr_p);
										}
#line 2118 "parser.cpp"
    break;

  case 42:
#line 452 "parser.y"
                                                {	print_rules("6.1 assignexpr -> lvalue = expr");
		   							 		if((yyvsp[-2].expr_p) && (yyvsp[-2].expr_p)->sym && ((yyvsp[-2].expr_p)->sym->type==LIB_FUNC || (yyvsp[-2].expr_p)->sym->type==USER_FUNC) ) {
												yyerror("invalid assignment (lvalue is a function)");
											}else {
												if((yyvsp[-2].expr_p) && (yyvsp[-2].expr_p)->type == TABLEITEM_E) {
													emit(TABLESETELEM_OP, (yyvsp[-2].expr_p), (yyvsp[-2].expr_p)->index, (yyvsp[0].expr_p), get_next_quad(), yylineno);
													(yyval.expr_p) = emit_iftableitem((yyvsp[-2].expr_p));
                                        			(yyval.expr_p)->type = VAR_E;
												}
												else {
													if((yyvsp[0].expr_p) && (yyvsp[-2].expr_p)) {
														if((yyvsp[0].expr_p)->type == BOOLEXPR_E) {									
															backpatch((yyvsp[0].expr_p)->truelist, get_next_quad());
															backpatch((yyvsp[0].expr_p)->falselist, get_next_quad() + 2);
															emit_branch_assign_quads((yyvsp[0].expr_p));
														}
														emit(ASSIGN_OP, (yyvsp[-2].expr_p), (yyvsp[0].expr_p), NULL, get_next_quad(), yylineno);
														(yyval.expr_p) = new expr(VAR_E, newtemp(), (yyvsp[0].expr_p), (yyvsp[0].expr_p)->value);
														emit(ASSIGN_OP, (yyval.expr_p), (yyvsp[-2].expr_p), NULL, get_next_quad(), yylineno);
													}
												}
											}
										}
#line 2146 "parser.cpp"
    break;

  case 43:
#line 478 "parser.y"
                                                                {	
											print_rules("7.1 primary -> lvalue");
											if((yyvsp[0].expr_p))						
												(yyval.expr_p) = emit_iftableitem((yyvsp[0].expr_p));
										}
#line 2156 "parser.cpp"
    break;

  case 44:
#line 483 "parser.y"
                                                                        {	
											print_rules("7.2 primary -> call");
											(yyval.expr_p) = (yyvsp[0].expr_p);
										}
#line 2165 "parser.cpp"
    break;

  case 45:
#line 487 "parser.y"
                                                                        {	
											print_rules("7.3 primary -> objectdef");
											(yyval.expr_p) = (yyvsp[0].expr_p);
										}
#line 2174 "parser.cpp"
    break;

  case 46:
#line 491 "parser.y"
                                                        {	
											print_rules("7.4 primary -> ( funcdef )");
											expr *e = newexpr(PROGRAMFUNC_E);
											e->sym = (yyvsp[-1].st_entryVal);
											(yyval.expr_p) = e;
										}
#line 2185 "parser.cpp"
    break;

  case 47:
#line 497 "parser.y"
                                                                        {	
											print_rules("7.5 primary -> const");
											(yyval.expr_p) = (yyvsp[0].expr_p);
										}
#line 2194 "parser.cpp"
    break;

  case 48:
#line 503 "parser.y"
                                                                {	print_rules("8.1 lvalue -> ID");
											st_entry_tmp["r8"] = st_lookup(*(yyvsp[0].strConst));
											if(!st_entry_tmp["r8"]) {
												(yyval.expr_p) = lvalue_expr (st_insert(*(yyvsp[0].strConst), (st_get_scope() == 0) ? GLOBAL_VAR : LOCAL_VAR));
											}else if( (st_entry_tmp["r8"]->type == LOCAL_VAR || (st_entry_tmp["r8"]->type == FORMAL_ARG
												&& st_entry_tmp["r8"]->scope != st_get_scope()))
													&& !func_stack.empty() && 
													(st_entry_tmp["r8"]->scope <= func_stack.top()->scope) ){
												yyerror("Cannot access local var \'"+*(yyvsp[0].strConst)+"\' inside function \'"
												+func_stack.top()->name + "\'");
												(yyval.expr_p) = NULL;
											}else {
												(yyval.expr_p) = lvalue_expr (st_entry_tmp["r8"]);
											}
										}
#line 2214 "parser.cpp"
    break;

  case 49:
#line 518 "parser.y"
                                                                        {
											print_rules("8.2 lvalue -> local ID");
											st_entry_tmp["r8"] = st_lookup(*(yyvsp[0].strConst));
											if(st_entry_tmp["r8"] && (st_entry_tmp["r8"]->scope == st_get_scope()) ){
												(yyval.expr_p) = lvalue_expr (st_entry_tmp["r8"]);
											}
											else if(st_entry_tmp["r8"] && st_entry_tmp["r8"]->type == LIB_FUNC){
												yyerror("variable \'" + *(yyvsp[0].strConst) + "\' shadows lib function");
												(yyval.expr_p) = NULL;
											}
											else{
												(yyval.expr_p) = lvalue_expr (st_insert(*(yyvsp[0].strConst), (st_get_scope() == 0) ? GLOBAL_VAR : LOCAL_VAR));
												// if(!func_stack.empty()) {
												// 	++func_stack.top()->totalLocals;													
												// }
											}
										}
#line 2236 "parser.cpp"
    break;

  case 50:
#line 535 "parser.y"
                                                                {
											print_rules("8.3 lvalue -> ::ID");
											st_entry_tmp["r8"] = st_lookup(*(yyvsp[0].strConst), 0);
											if(!st_entry_tmp["r8"]){
												yyerror("No global variable "+*(yyvsp[0].strConst)+" exists.");
												(yyval.expr_p) = NULL;
												// assert(st_entry_tmp["r8"]);
											}
											else {
												(yyval.expr_p) = lvalue_expr (st_entry_tmp["r8"]);
											}
										}
#line 2253 "parser.cpp"
    break;

  case 51:
#line 547 "parser.y"
                                                                        {
											print_rules("8.4 lvalue -> member");
											(yyval.expr_p) = (yyvsp[0].expr_p);
										}
#line 2262 "parser.cpp"
    break;

  case 52:
#line 553 "parser.y"
                                                        {
											print_rules("8+.1 tableitem -> lvalue . ID");
											if((yyvsp[-2].expr_p))
												(yyval.expr_p) = member_item((yyvsp[-2].expr_p), (yyvsp[0].strConst));
										}
#line 2272 "parser.cpp"
    break;

  case 53:
#line 558 "parser.y"
                                                        {
											print_rules("8+.2 tableitem -> lvalue [ expr ]");
											if((yyvsp[-3].expr_p) && (yyvsp[-1].expr_p)) {
												expr *e = handle_bool_e((yyvsp[-1].expr_p));
												(yyvsp[-3].expr_p) = emit_iftableitem((yyvsp[-3].expr_p));
												(yyval.expr_p) = newexpr(TABLEITEM_E);
												(yyval.expr_p)->sym = (yyvsp[-3].expr_p)->sym;
												(yyval.expr_p)->index = e;
											}
										}
#line 2287 "parser.cpp"
    break;

  case 54:
#line 571 "parser.y"
                                                                {
											print_rules("9.1 member -> tableitem");
											(yyval.expr_p) = (yyvsp[0].expr_p);
										}
#line 2296 "parser.cpp"
    break;

  case 55:
#line 575 "parser.y"
                                                                {
											print_rules("9.2 member -> call . ID");
											if((yyvsp[-2].expr_p))
												(yyval.expr_p) = member_item((yyvsp[-2].expr_p),(yyvsp[0].strConst));
										}
#line 2306 "parser.cpp"
    break;

  case 56:
#line 580 "parser.y"
                                                        {
											print_rules("9.3 member -> call [ expr ]");
											if((yyvsp[-1].expr_p)) {
												expr *e = handle_bool_e((yyvsp[-1].expr_p));
												(yyval.expr_p) = e;
											}
										}
#line 2318 "parser.cpp"
    break;

  case 57:
#line 589 "parser.y"
                                                        {	print_rules("10.1 member -> call ( elist )");
											if((yyvsp[-1].expr_p) && (yyvsp[0].callVal))
												(yyval.expr_p) = make_call((yyvsp[-1].expr_p), (yyvsp[0].callVal)->elist);
										}
#line 2327 "parser.cpp"
    break;

  case 58:
#line 593 "parser.y"
                                                                {	print_rules("10.2 member -> lvalue callsuffix");
											if((yyvsp[-1].expr_p) && (yyvsp[0].callVal)) {
												(yyvsp[-1].expr_p) = emit_iftableitem((yyvsp[-1].expr_p));
												if ((yyvsp[0].callVal)->method){
													expr* t = (yyvsp[-1].expr_p);
													(yyvsp[-1].expr_p) = emit_iftableitem(member_item(t, (yyvsp[0].callVal)->name));
													(yyvsp[0].callVal)->elist->insert((yyvsp[0].callVal)->elist->begin(),t); //v.insert(v.begin(), 6);
												}
												(yyval.expr_p) = make_call((yyvsp[-1].expr_p), (yyvsp[0].callVal)->elist);
											}
										}
#line 2343 "parser.cpp"
    break;

  case 59:
#line 605 "parser.y"
                                                                                {
											print_rules("10.3 member -> ( funcdef ) ( elist )");
											expr* func = newexpr(PROGRAMFUNC_E);
											func->sym = (yyvsp[-4].st_entryVal);
											(yyval.expr_p) = make_call(func, (yyvsp[-1].exprVec));
										}
#line 2354 "parser.cpp"
    break;

  case 60:
#line 613 "parser.y"
                                                                {	print_rules("11.1 member -> normcall");
											(yyval.callVal) = (yyvsp[0].callVal);
										}
#line 2362 "parser.cpp"
    break;

  case 61:
#line 616 "parser.y"
                                                                {	print_rules("11.2 member -> methodcall");
											(yyval.callVal) = (yyvsp[0].callVal);
										}
#line 2370 "parser.cpp"
    break;

  case 62:
#line 621 "parser.y"
                                                {	print_rules("12.1 normcall -> ( elist )");
											(yyval.callVal) = new call(NULL, 0, (yyvsp[-1].exprVec));
									    }
#line 2378 "parser.cpp"
    break;

  case 63:
#line 630 "parser.y"
                                                                                {
											print_rules("13.1 methodcall -> . . id ( elist )");
											(yyval.callVal) = new call((yyvsp[-3].strConst), 1, (yyvsp[-1].exprVec));
									    }
#line 2387 "parser.cpp"
    break;

  case 64:
#line 636 "parser.y"
                                                                {
											print_rules("14.1 elist -> expr");
											(yyval.exprVec) = new std::vector<expr*>;
											if((yyvsp[0].expr_p)) {
												(yyval.exprVec)->push_back(handle_bool_e((yyvsp[0].expr_p)));
											}
										}
#line 2399 "parser.cpp"
    break;

  case 65:
#line 643 "parser.y"
                                                                {	
											print_rules("14.2 elist -> elist , expr");
											assert((yyvsp[-2].exprVec));
											if((yyvsp[0].expr_p))
												(yyvsp[-2].exprVec)->push_back(handle_bool_e((yyvsp[0].expr_p)));
										}
#line 2410 "parser.cpp"
    break;

  case 66:
#line 649 "parser.y"
                                                                                {	
											print_rules("14.3 elist -> ε");
											(yyval.exprVec) = new std::vector<expr*>;
										}
#line 2419 "parser.cpp"
    break;

  case 67:
#line 655 "parser.y"
                                                {	
											print_rules("15.1 objectdef -> [ elist ]");
											expr* t = newexpr(NEWTABLE_E);
											t->sym = newtemp();
											emit(TABLECREATE_OP, t, NULL, NULL, get_next_quad(), yylineno);

											for(int i=0; i < ((yyvsp[-1].exprVec)->size()); ++i){
												emit(
													TABLESETELEM_OP, 
													t, 
													newexpr_constint(i), 
													(*(yyvsp[-1].exprVec))[i], 
													get_next_quad(), yylineno);
											}
											(yyval.expr_p) = t;
										}
#line 2440 "parser.cpp"
    break;

  case 68:
#line 671 "parser.y"
                                                        {	
											print_rules("15.2 objectdef -> [ indexed ]");
											expr* t = newexpr(NEWTABLE_E);
											t->sym = newtemp();
											emit(TABLECREATE_OP, t, NULL, NULL, get_next_quad(), yylineno);

											for(int i=0; i < ((yyvsp[-1].pairVec)->size()); ++i){
												emit(
													TABLESETELEM_OP, 
													t, 
													(*(yyvsp[-1].pairVec))[i]->first, 
													(*(yyvsp[-1].pairVec))[i]->second, 
													get_next_quad(), yylineno);
											}
											(yyval.expr_p) = t;
										}
#line 2461 "parser.cpp"
    break;

  case 69:
#line 689 "parser.y"
                                                        {	
											print_rules("16.1 indexed -> indexedelem");
											std::vector<std::pair<expr*, 
											expr*>* >* v = new std::vector<std::pair<expr*, 
											expr*>* >();
											v->push_back((yyvsp[0].pairVal));	/*  pair, not *pair  */
											(yyval.pairVec) = v;
										}
#line 2474 "parser.cpp"
    break;

  case 70:
#line 697 "parser.y"
                                                        {	
											print_rules("16.2 indexed ->  indexed , indexedelem");
											assert((yyvsp[-2].pairVec));
											(yyvsp[-2].pairVec)->push_back((yyvsp[0].pairVal));
											(yyval.pairVec) = (yyvsp[-2].pairVec);  /* Praying that it calls deep copy ctor */
										}
#line 2485 "parser.cpp"
    break;

  case 71:
#line 706 "parser.y"
                                                                        {	
				  							print_rules("17.1 indexedelem -> { expr : expr }");
											std::pair<expr*,expr*>* p = new std::pair<expr*,expr*>;
											if((yyvsp[-3].expr_p) && (yyvsp[-1].expr_p)) {
												p->first = handle_bool_e((yyvsp[-3].expr_p));
												p->second = handle_bool_e((yyvsp[-1].expr_p));
											}
											(yyval.pairVal) = p;	  
										}
#line 2499 "parser.cpp"
    break;

  case 72:
#line 717 "parser.y"
                                                                { 	print_rules("18.1 block -> { stmts }");
											st_increase_scope();
										}
#line 2507 "parser.cpp"
    break;

  case 73:
#line 720 "parser.y"
                                                                {
											if(!hasError)
												st_hide(st_get_scope());
											st_decrease_scope();
											
											(yyval.stmt_pt) = (yyvsp[-1].stmt_pt);
										}
#line 2519 "parser.cpp"
    break;

  case 74:
#line 727 "parser.y"
                                                                {	print_rules("18.2 block -> { }");
											(yyval.stmt_pt) = new stmt_t();
										}
#line 2527 "parser.cpp"
    break;

  case 75:
#line 732 "parser.y"
                                                                {
											(yyval.strConst) = (yyvsp[0].strConst);
											st_entry_tmp["r19"] = st_lookup(*(yyval.strConst));
											if((!st_entry_tmp["r19"]) ||
													( (st_entry_tmp["r19"]->scope < st_get_scope())
													&& (st_entry_tmp["r19"]->type != LIB_FUNC) ) ) {
												st_entry_tmp["r19"] = st_insert(*(yyval.strConst), USER_FUNC);
											}
											else {
												if(st_entry_tmp["r19"]->type == USER_FUNC) {// kseroume oti einai locally defined
													yyerror("redefinition of user function defined in line "
													+ std::to_string(st_entry_tmp["r19"]->line));
													/* $$ = NULL; */
												}
												else if(st_entry_tmp["r19"]->type == LIB_FUNC){
													yyerror("function definition shadows lib function");
													/* $$ = NULL; */
												}
												else if(st_entry_tmp["r19"]->type == LOCAL_VAR
														|| st_entry_tmp["r19"]->type == FORMAL_ARG
														|| st_entry_tmp["r19"]->type == GLOBAL_VAR){
													yyerror("variable \""+ *(yyval.strConst) + "\" already defined in line "
													+std::to_string(st_entry_tmp["r19"]->line));
													/* $$ = NULL; */
												}
												else {
													assert(0);
												}
												st_entry_tmp["r19"] = NULL;
											}
										}
#line 2563 "parser.cpp"
    break;

  case 76:
#line 763 "parser.y"
                                                                                {
											(yyval.strConst) = new std::string();
											*(yyval.strConst) = st_godfather();
											st_insert(*(yyval.strConst), USER_FUNC);
										}
#line 2573 "parser.cpp"
    break;

  case 77:
#line 770 "parser.y"
                                                {
											print_rules("19.1 funcdef -> function ( idlist ) block");
											if((yyvsp[0].strConst)) {
												(yyval.st_entryVal) = st_lookup(*(yyvsp[0].strConst));
												assert((yyval.st_entryVal));
												(yyval.st_entryVal)->totalLocals = 0;
												(yyval.st_entryVal)->iaddress = get_current_quad();
												st_entry_tmp["r19"] = (yyval.st_entryVal);
												func_stack.push((yyval.st_entryVal));
												expr *tmp_expr;
												emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
												tmp_expr = new expr(PROGRAMFUNC_E, (yyval.st_entryVal), NULL, emptyval);
												pushscopeoffsetstack();
												emit(FUNCSTART_OP, tmp_expr, NULL, NULL, get_next_quad(), yylineno);
												st_increase_scope();
												enterscopespace();												
											}
										}
#line 2596 "parser.cpp"
    break;

  case 78:
#line 790 "parser.y"
                                                {
											(yyval.intConst) = (yyvsp[-1].intConst);
											st_decrease_scope();
											enterscopespace();	
                                		}
#line 2606 "parser.cpp"
    break;

  case 79:
#line 796 "parser.y"
                                                                {
											if((yyvsp[0].stmt_pt) && !hasError) {
												(yyval.intConst) = (yyvsp[0].stmt_pt)->retList;
											}
											exitscopespace();
										}
#line 2617 "parser.cpp"
    break;

  case 80:
#line 804 "parser.y"
                                                                                {	
											if(!hasError) {
												(yyvsp[-2].st_entryVal)->totalLocals = getTotalLocals();
												(yyvsp[-2].st_entryVal)->totalArgs = getTotalArgs();
												exitscopespace();
												popscopeoffsetstack();
												patchlist((yyvsp[0].intConst), get_next_quad());
												(yyval.st_entryVal) = (yyvsp[-2].st_entryVal);
												expr *tmp_expr;
												tmp_expr = new expr(PROGRAMFUNC_E, (yyvsp[-2].st_entryVal), NULL, emptyval);
												emit(FUNCEND_OP, tmp_expr, NULL, NULL, get_next_quad(), yylineno);
												if(st_entry_tmp["r19"]) {
													func_stack.pop();
												}
												patchlabel((yyvsp[-2].st_entryVal)->iaddress, get_next_quad());
											}
										}
#line 2639 "parser.cpp"
    break;

  case 81:
#line 823 "parser.y"
                                                                {	print_rules("20.1 const -> INTEGER");
											(yyval.expr_p) = newexpr_constint((yyvsp[0].intConst));
										}
#line 2647 "parser.cpp"
    break;

  case 82:
#line 826 "parser.y"
                                                                        {	print_rules("20.2 const -> REAL");
											(yyval.expr_p) = newexpr_constdouble((yyvsp[0].realConst));
										}
#line 2655 "parser.cpp"
    break;

  case 83:
#line 829 "parser.y"
                                                                        {	print_rules("20.3 const -> STRING");
											(yyval.expr_p) = newexpr_conststring((yyvsp[0].strConst));
										}
#line 2663 "parser.cpp"
    break;

  case 84:
#line 832 "parser.y"
                                                                        {	print_rules("20.4 const -> NIL");
											(yyval.expr_p) = newexpr(NIL_E);
										}
#line 2671 "parser.cpp"
    break;

  case 85:
#line 835 "parser.y"
                                                                        {	print_rules("20.5 const -> TRUE");
											(yyval.expr_p) = newexpr_constbool(true);
										}
#line 2679 "parser.cpp"
    break;

  case 86:
#line 838 "parser.y"
                                                                        {	print_rules("20.6 const -> FALSE");
											(yyval.expr_p) = newexpr_constbool(false);
										}
#line 2687 "parser.cpp"
    break;

  case 87:
#line 843 "parser.y"
                                                                {
											print_rules("22.1 idlist -> ID");
											st_entry_tmp["r21"] = st_lookup(*(yyvsp[0].strConst), 0);
											if(st_entry_tmp["r21"] && st_entry_tmp["r21"]->type ==  LIB_FUNC){
												yyerror("formal argument " + *(yyvsp[0].strConst) + " shadows lib func");
											}
											else {
												st_entry_tmp["r21"] = st_insert(*(yyvsp[0].strConst), FORMAL_ARG);
												// ++st_entry_tmp["r21"]->totalArgs;
												incformalArgOffset();
											}
											
											// $$ = poop
										}
#line 2706 "parser.cpp"
    break;

  case 88:
#line 857 "parser.y"
                                                                {
											print_rules("21.2 idlist -> idlist , ID");
											st_entry_tmp["r21"] = st_lookup(*(yyvsp[0].strConst));
											if(st_entry_tmp["r21"] && (st_entry_tmp["r21"]->type == FORMAL_ARG)
													&& st_entry_tmp["r21"]->scope == st_get_scope()){ // conflict
												yyerror("Argument "+ *(yyvsp[0].strConst) +" already exists.");
											}
											else if(st_entry_tmp["r21"] && st_entry_tmp["r21"]->type == LIB_FUNC){
												yyerror("formal argument " + *(yyvsp[0].strConst) + " shadows lib func");
											}
											else{
												st_entry_tmp["r21"] = st_insert(*(yyvsp[0].strConst), FORMAL_ARG);
												// ++st_entry_tmp["r21"]->totalArgs;
												incformalArgOffset();
											}
											// $$ = poop
										}
#line 2728 "parser.cpp"
    break;

  case 89:
#line 874 "parser.y"
                                                                                {
											print_rules("21.3 empty id_list");
											// $$ = poop
										}
#line 2737 "parser.cpp"
    break;

  case 90:
#line 881 "parser.y"
                                                {
											print_rules("23.1 ifprefix -> if ( expr )");
											if((yyvsp[-1].expr_p)) {
												(yyvsp[-1].expr_p) = true_test((yyvsp[-1].expr_p));
												if((yyvsp[-1].expr_p)->type == BOOLEXPR_E) {
													backpatch((yyvsp[-1].expr_p)->truelist, get_next_quad());
													backpatch((yyvsp[-1].expr_p)->falselist, get_next_quad() + 2);
													(yyvsp[-1].expr_p) = emit_branch_assign_quads((yyvsp[-1].expr_p));
													emit(IF_EQ_OP, NULL, (yyvsp[-1].expr_p), newexpr_constbool(true), get_next_quad() + 2, yylineno);
													emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
												}
												(yyvsp[-1].expr_p)->falselist = new std::vector<unsigned>();
												(yyvsp[-1].expr_p)->falselist->push_back(get_current_quad()-1);// pushback the jump so i can backpatch
												(yyval.expr_p) = (yyvsp[-1].expr_p);
											}else
												(yyval.expr_p) = NULL;
										}
#line 2759 "parser.cpp"
    break;

  case 91:
#line 900 "parser.y"
                                                                {
											print_rules("23.2 elseprefix -> else");
											(yyval.intConst) = get_current_quad();
											emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
										}
#line 2769 "parser.cpp"
    break;

  case 92:
#line 907 "parser.y"
                                                        {
											print_rules("23.3 ifstmt -> ifprefix stmt");
											if((yyvsp[-1].expr_p)) {
												backpatch((yyvsp[-1].expr_p)->falselist, get_next_quad());
											}
											(yyval.stmt_pt) = (yyvsp[0].stmt_pt);
										}
#line 2781 "parser.cpp"
    break;

  case 93:
#line 915 "parser.y"
                                                                                {
											print_rules("23.4 ifstmt -> ifstmt -> ifprefix stmt elseprefix stmt");
											if((yyvsp[-3].expr_p) && (yyvsp[-2].stmt_pt) && (yyvsp[0].stmt_pt)){
												backpatch((yyvsp[-3].expr_p)->falselist, (yyvsp[-1].intConst)+2);
												patchlabel((yyvsp[-1].intConst), get_next_quad());
												(yyvsp[-2].stmt_pt)->breakList = mergelist((yyvsp[-2].stmt_pt)->breakList, (yyvsp[0].stmt_pt)->breakList);
												(yyvsp[-2].stmt_pt)->contList = mergelist((yyvsp[-2].stmt_pt)->contList,  (yyvsp[0].stmt_pt)->contList);
												(yyvsp[-2].stmt_pt)->retList = mergelist((yyvsp[-2].stmt_pt)->retList, (yyvsp[0].stmt_pt)->retList);
												(yyval.stmt_pt) = (yyvsp[-2].stmt_pt);
											}else {
												(yyval.stmt_pt)=NULL;
											}
											
										}
#line 2800 "parser.cpp"
    break;

  case 94:
#line 932 "parser.y"
                                                                {	++loopcounter;	(yyval.intConst) = get_next_quad();}
#line 2806 "parser.cpp"
    break;

  case 95:
#line 934 "parser.y"
                                                {
											if((yyvsp[-1].expr_p)) {
												(yyvsp[-1].expr_p) = true_test((yyvsp[-1].expr_p));
												if((yyvsp[-1].expr_p)->type == BOOLEXPR_E) {
													(yyvsp[-1].expr_p) = handle_bool_e((yyvsp[-1].expr_p));
													emit(IF_EQ_OP, NULL, (yyvsp[-1].expr_p), newexpr_constbool(true), get_next_quad()+2, yylineno);
													(yyval.intConst) = get_current_quad();
													emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
												}else // case i have while(true) ...
													(yyval.intConst) = get_current_quad()-1;
												/* loop_stack.push(st_get_scope()); */
											}
										}
#line 2824 "parser.cpp"
    break;

  case 96:
#line 949 "parser.y"
                                                                                {
											print_rules("24.1 whilestmt -> while ( expr ) stmt");
											if((yyvsp[0].stmt_pt)) {
												patchlist((yyvsp[0].stmt_pt)->breakList, get_next_quad()+1);
												patchlist((yyvsp[0].stmt_pt)->contList, (yyvsp[-2].intConst));
												(yyval.stmt_pt) = (yyvsp[0].stmt_pt);
											}else
												(yyval.stmt_pt) = new stmt_t();
											emit(JUMP_OP, NULL, NULL, NULL, (yyvsp[-2].intConst), yylineno);
											patchlabel((yyvsp[-1].intConst), get_next_quad());
											/* loop_stack.pop(); */
											--loopcounter;
										}
#line 2842 "parser.cpp"
    break;

  case 97:
#line 965 "parser.y"
                                                                                {
											print_rules("25.0 forprefix -> for ( elist ; expr ;");
											++loopcounter;
											/* loop_stack.push(st_get_scope()); */
											if((yyvsp[-1].expr_p)) {
												(yyval.forVal) = new for_stmt();
												(yyval.forVal)->test = (yyvsp[-2].intConst);
												expr* e = handle_bool_e((yyvsp[-1].expr_p));
												(yyval.forVal)->enter = get_current_quad();
												emit(IF_EQ_OP, NULL, e, newexpr_constbool(true), 0, yylineno);
											}else
												(yyval.forVal) = NULL;
										}
#line 2860 "parser.cpp"
    break;

  case 98:
#line 981 "parser.y"
                                                                                {
		 									print_rules("25.1 forstmt -> for ( elist ; expr ; elist ) stmt");
											patchlabel((yyvsp[-6].forVal)->enter, (yyvsp[-2].intConst)+2);
											patchlabel((yyvsp[-5].intConst), get_next_quad());
											patchlabel((yyvsp[-2].intConst), (yyvsp[-6].forVal)->test);
											patchlabel((yyvsp[0].intConst), (yyvsp[-5].intConst) + 2);
											if((yyvsp[-1].stmt_pt)){
												patchlist((yyvsp[-1].stmt_pt)->breakList, get_next_quad());
												patchlist((yyvsp[-1].stmt_pt)->contList, (yyvsp[-5].intConst) + 1);
												(yyval.stmt_pt) = (yyvsp[-1].stmt_pt);
											}else{
												(yyval.stmt_pt) = NULL;
											}
											--loopcounter;
											/* loop_stack.pop(); */
										}
#line 2881 "parser.cpp"
    break;

  case 99:
#line 999 "parser.y"
                                                                                {
											(yyval.intConst) = get_current_quad();
                							emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
										}
#line 2890 "parser.cpp"
    break;

  case 100:
#line 1006 "parser.y"
                                                        {
											print_rules("26.1 returnstmt -> return ;");
											if (func_stack.empty()){
												yyerror("Use of 'return' while not in a function");
											}else {
												emit(RET_OP, NULL, NULL, NULL, get_next_quad(), yylineno);
												(yyval.intConst) = get_current_quad();// TODO check
												emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
											}
										}
#line 2905 "parser.cpp"
    break;

  case 101:
#line 1016 "parser.y"
                                                        {
											print_rules("26.2 returnstmt -> return expr ;");
											if (func_stack.empty()){
												yyerror("Use of 'return' while not in a function");
											}else {
												emit(RET_OP, NULL, NULL, (yyvsp[-1].expr_p), get_next_quad(), yylineno);
												(yyval.intConst) = get_current_quad();// TODO check
												emit(JUMP_OP, NULL, NULL, NULL, 0, yylineno);
												if((yyvsp[-1].expr_p) && (yyvsp[-1].expr_p)->type == BOOLEXPR_E) {
													backpatch((yyvsp[-1].expr_p)->truelist, get_next_quad());
													backpatch((yyvsp[-1].expr_p)->falselist, get_next_quad() + 2);
													emit_branch_assign_quads((yyvsp[-1].expr_p));
												}
											}
										}
#line 2925 "parser.cpp"
    break;


#line 2929 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1033 "parser.y"


extern void validate_comments();

int yyerror(std:: string err) {
	std::cout << "\033[31m" << "ERROR " << "\033[37m" <<
	"in line " << yylineno << " : " << err << "\n";
	hasError = true;
	/* std::cout << "One or more errors on compilation, aborting... \n"; */
	/* exit(1); */
	return 1;
}


int main(int argc, char** argv) {
	std::cout << "\033[37m";// output is colored white
	std::string outname = "alpha.abc";
	int opt, num_files;
	FILE **files = NULL;

	while((opt = getopt(argc, argv, "o:i")) != -1){
		switch(opt){
			case 'i':
				outname = "";
				break;
			case 'o':
				outname = optarg;
				break;
			case '?':
				std::cout << "\033[33mTerminating\n";
			default:
				return 1;
		}
	}
	num_files = argc - optind;
	
	if(!num_files) {
		yyin = stdin;
	}
	else {
		files = (FILE**) malloc(num_files*sizeof(FILE*));
		for(int i = 0; optind < argc; ++optind, ++i) {
			if ( (files[i] = fopen(argv[optind], "r")) == NULL) {
				std::cout << argv[0] << ": Incorrect filename specified -- " << argv[optind] << std::endl;
				std::cout << "\033[33mTerminating\n";
				return 1;
			}
		}
	}
	validate_comments();
	st_initialize();
	if(num_files) {
		for ( int i = 0; i < num_files; ++i) {
			yyin = files[i];
			yyparse();
			if (hasError) {
				std::cout << argv[0] << ": One or more errors on compilation, aborting... \n";
				return 1;
			}
			fclose(files[i]);
		}
		st_print_table();
		generate();
		FILE *outf;
		if(outname != "") {
			outf = fopen(outname.c_str(), "w");
		}else {
			outf = stdout;
		}
		generate_binary_readable(outname);
		generate_binary(outf);
		/* print_quads(); */
		print_instructions();// for debug
	}else {
		yyparse();
		if (!hasError) {
			st_print_table();
			generate();
			FILE *outf;
			if(outname != "") {
				outf = fopen(outname.c_str(), "w");
			}else {
				outf = stdout;
			}
			generate_binary_readable(outname);
			generate_binary(outf);
			print_quads();
			print_instructions();
			/* avm_table* mytesttable;
			avm_memcell* tempcell;
			tempcell->type = STRING_M;
			tempcell->data.strVal = new std::string("Bab");
			avm_memcell* tempcell2;
			tempcell->type = STRING_M;
			tempcell->data.strVal = new std::string("Mpamphs");
			avm_tablesetelem(mytesttable, tempcell, tempcell2);
			libfunc_objectmemberkeys(*mytesttable); */
					
		} else {
			std::cout << "One or more errors on compilation, aborting... \n";
			return 1;
		}
	}
    return 0;
}
