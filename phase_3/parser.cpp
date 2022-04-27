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
						 CS340 - Compilers ~ Project Spring 2022
					  Computer Of Crete, Computer Science Department

							Constantine Damaskinakis - csd3755
							   Minos Stavrakakis - csd4120
							 Demetrious Grammenidis - csd3933

 */

#include <assert.h>
#include <iostream>
#include <string>
#include "symtable.h"
#include <unordered_map>

bool member_flag = false;
int yyerror(std::string message);

extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern int yylex();

/* Auxiliary var for storing each rule's id value (e.g. entry["rule8.1"] = id) returned
 * from lookup (e.g at $1) */
std::unordered_map<std::string, struct st_entry*> st_entry_tmp;
/* In alpha a funcdef can be inside a function's scope so we needed to know if we are
 * inside a function 
 */
extern std::stack<struct st_entry*> func_stack;

void print_rules(std::string str) {
	 /* std::cout << "~ entered rule :\t " << str << std::endl; */
}


#line 110 "parser.cpp"

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
# define YYERROR_VERBOSE 0
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
#line 44 "parser.y"

	int intConst;
	double realConst;
	std::string *strConst;
	struct st_entry *st_entryVal;
	bool boolean;

#line 219 "parser.cpp"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   596

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

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
       0,    88,    88,    92,    93,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     126,   127,   128,   129,   135,   141,   147,   153,   156,   166,
     167,   168,   169,   170,   173,   190,   203,   214,   220,   224,
     228,   232,   238,   239,   240,   244,   245,   248,   251,   254,
     255,   256,   259,   260,   263,   264,   267,   271,   271,   278,
     282,   283,   278,   291,   295,   327,   328,   291,   340,   341,
     342,   343,   344,   345,   348,   359,   373,   376,   377,   380,
     383,   386,   392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "DOTDOT", "$accept", "program", "stmts", "stmt", "expr", "term",
  "assignexpr", "primary", "lvalue", "member", "call", "callsuffix",
  "normcall", "methodcall", "elist", "objectdef", "indexed", "indexedelem",
  "block", "$@1", "funcdef", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "const", "idlist", "ifstmt", "whilestmt", "forstmt", "returnstmt", YY_NULLPTR
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

#define YYPACT_NINF (-160)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -160,     9,   146,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
       7,  -160,    -5,    -7,    24,    34,    25,   190,    37,    50,
     289,   289,    -5,  -160,   201,   245,  -160,    83,  -160,   334,
    -160,  -160,  -160,     4,  -160,   -31,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,    85,    -9,   -31,   289,   289,
      62,   108,   289,  -160,   356,  -160,  -160,  -160,  -160,    -9,
    -160,   289,   525,   -20,   -15,  -160,   400,    75,  -160,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,  -160,  -160,   289,  -160,   289,   289,   121,   123,
    -160,  -160,  -160,   289,   289,   124,    92,   422,   444,  -160,
    -160,     5,  -160,   102,   312,  -160,   289,  -160,    99,  -160,
      97,    28,   537,    58,    58,  -160,  -160,  -160,   549,   561,
     561,   561,   561,   549,   525,   466,   -11,  -160,   101,   488,
      39,  -160,    97,   146,   146,   138,   105,   289,  -160,   289,
     525,  -160,   289,  -160,  -160,   289,  -160,  -160,   132,  -160,
    -160,    46,  -160,   378,   510,    52,    55,   146,  -160,   152,
     138,   289,  -160,  -160,  -160,  -160,   131,  -160,    56,    82,
    -160,  -160,   146,   131,  -160,  -160
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    78,    79,    80,    44,    82,    83,
       0,    81,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,    67,    61,     0,    14,     0,     3,     0,
      29,    15,    37,    39,    47,    40,    41,    12,    13,    43,
       6,     7,     8,     9,    45,     0,    35,     0,     0,     0,
       0,     0,    61,    91,     0,    10,    11,    32,    31,    33,
       4,     0,    59,     0,     0,    64,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,    36,     0,    34,     0,    61,     0,     0,
      53,    55,    56,     0,    61,     0,     0,     0,     0,    70,
      74,     0,    92,     0,     0,    62,     0,    63,     0,    30,
      42,    28,    27,    16,    17,    18,    19,    20,    26,    21,
      23,    22,    24,    25,    38,     0,     0,    48,     0,     0,
       0,    50,     0,     0,     0,    86,     0,     0,    68,     0,
      60,    65,    61,    49,    57,    61,    51,    52,    87,    89,
      84,     0,    75,     0,     0,     0,     0,     0,    71,     0,
      86,    61,    66,    54,    58,    88,     0,    85,     0,     0,
      72,    76,     0,     0,    90,    77
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,   111,  -130,    -2,  -160,  -160,  -160,    -1,  -160,
       0,  -160,  -160,  -160,   -50,  -160,  -160,    53,  -159,  -160,
     -19,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,    13,
    -160,  -160,  -160,  -160
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    28,    62,    30,    31,    32,    33,    34,
      35,    90,    91,    92,    63,    36,    64,    65,    37,    60,
      38,    50,   135,   166,    51,   136,   160,   173,    39,   151,
      40,    41,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,     7,   101,   148,   149,    10,    67,   170,    93,     3,
      94,    46,    47,    44,   175,    54,    95,    83,    57,    58,
     105,    59,    47,    66,   106,   107,    96,   165,    84,   108,
      86,   144,    87,   106,    48,    85,    45,   126,    88,    89,
     -73,    27,   174,    86,   130,    87,    97,    98,   137,   106,
      70,    88,    89,    71,    72,    73,    74,    75,    76,   104,
      77,    78,    79,    80,    81,    49,    52,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      55,   147,   124,   106,   125,    73,    74,    75,   158,    68,
     159,   129,   155,    56,   163,   156,   106,   164,   171,   106,
     159,    29,    15,    99,   140,     4,     5,     6,     7,     8,
       9,   169,    10,    11,   100,    12,    13,   110,    14,    15,
      16,    17,    18,    19,   172,    20,   106,   127,    21,   128,
     131,    29,    29,    22,   132,   153,    61,   154,   142,    23,
     138,    24,   145,    25,   150,    26,   152,   157,    27,     4,
       5,     6,     7,     8,     9,    29,    10,    11,   167,    12,
      13,   141,    14,    15,    16,    17,    18,    19,    23,    20,
      29,   103,    21,   168,     0,     0,     0,    22,     0,     0,
       0,     0,     0,    23,     0,    24,     0,    25,     0,    26,
       0,     0,    27,     4,     5,     6,     7,     8,     9,     0,
      10,    11,     0,    12,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    20,    12,     0,    21,     0,     0,     0,
       0,    22,     0,     0,    20,     0,     0,    21,     0,    24,
       0,    25,    22,    53,     0,     0,    27,     0,    61,     0,
      24,     0,    25,     0,     0,     0,     0,    27,     4,     5,
       6,     7,     8,     9,     0,    10,    11,     0,    12,     0,
       0,     0,    15,     0,     0,     0,     0,     0,    20,     0,
       0,    21,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,    24,     0,    25,     0,     0,     0,
       0,    27,     4,     5,     6,     7,     8,     9,     0,    10,
      11,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,    21,     0,     0,     0,     0,
      22,    69,     0,     0,     0,     0,     0,     0,    24,     0,
      25,     0,     0,     0,    70,    27,     0,    71,    72,    73,
      74,    75,    76,    69,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,    70,   139,     0,    71,
      72,    73,    74,    75,    76,    69,    77,    78,    79,    80,
      81,     0,     0,     0,     0,     0,     0,    82,    70,     0,
       0,    71,    72,    73,    74,    75,    76,    69,    77,    78,
      79,    80,    81,     0,     0,     0,     0,     0,     0,   102,
      70,     0,     0,    71,    72,    73,    74,    75,    76,    69,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,   161,    70,     0,     0,    71,    72,    73,    74,    75,
      76,    69,    77,    78,    79,    80,    81,     0,     0,     0,
       0,     0,   109,     0,    70,     0,     0,    71,    72,    73,
      74,    75,    76,    69,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,   133,     0,    70,     0,     0,    71,
      72,    73,    74,    75,    76,    69,    77,    78,    79,    80,
      81,     0,     0,     0,     0,     0,   134,     0,    70,     0,
       0,    71,    72,    73,    74,    75,    76,    69,    77,    78,
      79,    80,    81,     0,     0,     0,   143,     0,     0,     0,
      70,     0,     0,    71,    72,    73,    74,    75,    76,    69,
      77,    78,    79,    80,    81,     0,     0,     0,   146,     0,
       0,     0,    70,     0,    69,    71,    72,    73,    74,    75,
      76,     0,    77,    78,    79,    80,    81,    70,   162,     0,
      71,    72,    73,    74,    75,    76,     0,    77,    78,    79,
      80,    81,    71,    72,    73,    74,    75,    76,     0,    77,
      78,    79,    80,    81,    71,    72,    73,    74,    75,   -74,
       0,    77,    78,    79,    80,   -74,    71,    72,    73,    74,
      75,     0,     0,   -74,   -74,   -74,   -74
};

static const yytype_int16 yycheck[] =
{
       2,     6,    52,   133,   134,    10,    25,   166,    39,     0,
      41,    12,    12,     6,   173,    17,    47,    13,    20,    21,
      40,    22,    22,    25,    44,    40,    45,   157,    24,    44,
      39,    42,    41,    44,    41,    31,    41,    87,    47,    48,
       6,    46,   172,    39,    94,    41,    48,    49,    43,    44,
      22,    47,    48,    25,    26,    27,    28,    29,    30,    61,
      32,    33,    34,    35,    36,    41,    41,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      43,    42,    84,    44,    86,    27,    28,    29,    42,     6,
      44,    93,   142,    43,    42,   145,    44,    42,    42,    44,
      44,   103,    17,    41,   106,     3,     4,     5,     6,     7,
       8,   161,    10,    11,     6,    13,    14,    42,    16,    17,
      18,    19,    20,    21,    42,    23,    44,     6,    26,     6,
       6,   133,   134,    31,    42,   137,    37,   139,    41,    37,
      38,    39,    41,    41,     6,    43,    41,    15,    46,     3,
       4,     5,     6,     7,     8,   157,    10,    11,     6,    13,
      14,   108,    16,    17,    18,    19,    20,    21,    37,    23,
     172,    60,    26,   160,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    39,    -1,    41,    -1,    43,
      -1,    -1,    46,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    23,    13,    -1,    26,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    23,    -1,    -1,    26,    -1,    39,
      -1,    41,    31,    43,    -1,    -1,    46,    -1,    37,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    46,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    46,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      31,     9,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    -1,    -1,    -1,    22,    46,    -1,    25,    26,    27,
      28,    29,    30,     9,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    45,    -1,    25,
      26,    27,    28,    29,    30,     9,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    22,    -1,
      -1,    25,    26,    27,    28,    29,    30,     9,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      22,    -1,    -1,    25,    26,    27,    28,    29,    30,     9,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    22,    -1,    -1,    25,    26,    27,    28,    29,
      30,     9,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    22,    -1,    -1,    25,    26,    27,
      28,    29,    30,     9,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    22,    -1,    -1,    25,
      26,    27,    28,    29,    30,     9,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    22,    -1,
      -1,    25,    26,    27,    28,    29,    30,     9,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      22,    -1,    -1,    25,    26,    27,    28,    29,    30,     9,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    22,    -1,     9,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    22,    38,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    50,    51,     0,     3,     4,     5,     6,     7,     8,
      10,    11,    13,    14,    16,    17,    18,    19,    20,    21,
      23,    26,    31,    37,    39,    41,    43,    46,    52,    53,
      54,    55,    56,    57,    58,    59,    64,    67,    69,    77,
      79,    80,    81,    82,     6,    41,    57,    59,    41,    41,
      70,    73,    41,    43,    53,    43,    43,    53,    53,    57,
      68,    37,    53,    63,    65,    66,    53,    69,     6,     9,
      22,    25,    26,    27,    28,    29,    30,    32,    33,    34,
      35,    36,    43,    13,    24,    31,    39,    41,    47,    48,
      60,    61,    62,    39,    41,    47,    69,    53,    53,    41,
       6,    63,    43,    51,    53,    40,    44,    40,    44,    42,
      42,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    63,     6,     6,    53,
      63,     6,    42,    42,    42,    71,    74,    43,    38,    45,
      53,    66,    41,    40,    42,    41,    40,    42,    52,    52,
       6,    78,    41,    53,    53,    63,    63,    15,    42,    44,
      75,    43,    38,    42,    42,    52,    72,     6,    78,    63,
      67,    42,    42,    76,    52,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    56,
      56,    56,    56,    56,    57,    57,    57,    57,    58,    58,
      58,    58,    59,    59,    59,    60,    60,    61,    62,    63,
      63,    63,    64,    64,    65,    65,    66,    68,    67,    70,
      71,    72,    69,    73,    74,    75,    76,    69,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    80,
      81,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     3,     4,
       3,     4,     4,     2,     6,     1,     1,     3,     5,     1,
       3,     0,     3,     3,     1,     3,     5,     0,     4,     0,
       0,     0,     8,     0,     0,     0,     0,    10,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     5,     7,     5,
       9,     2,     3
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
#line 88 "parser.y"
                                                                {std::cout << "Finished reading statements\n";}
#line 1602 "parser.cpp"
    break;

  case 3:
#line 92 "parser.y"
                                                        {print_rules("2.1 stmts -> stmts stmt");}
#line 1608 "parser.cpp"
    break;

  case 4:
#line 93 "parser.y"
                                                                                {print_rules("2.2 stmts -> ε");}
#line 1614 "parser.cpp"
    break;

  case 5:
#line 96 "parser.y"
                                                        {print_rules("3.1 stmt -> expr ;");}
#line 1620 "parser.cpp"
    break;

  case 6:
#line 97 "parser.y"
                                                                        {print_rules("3.2 stmt -> ifstmt");}
#line 1626 "parser.cpp"
    break;

  case 7:
#line 98 "parser.y"
                                                                        {print_rules("3.3 stmt -> whilestmt");}
#line 1632 "parser.cpp"
    break;

  case 8:
#line 99 "parser.y"
                                                                        {print_rules("3.4 stmt -> forstmt");}
#line 1638 "parser.cpp"
    break;

  case 9:
#line 100 "parser.y"
                                                                {print_rules("3.5 stmt -> returnstmt");}
#line 1644 "parser.cpp"
    break;

  case 10:
#line 101 "parser.y"
                                                                {print_rules("3.6 stmt -> BREAK ;");}
#line 1650 "parser.cpp"
    break;

  case 11:
#line 102 "parser.y"
                                                        {print_rules("3.7 stmt -> CONTINUE ;");}
#line 1656 "parser.cpp"
    break;

  case 12:
#line 103 "parser.y"
                                                                        {print_rules("3.8 stmt -> block");}
#line 1662 "parser.cpp"
    break;

  case 13:
#line 104 "parser.y"
                                                                        {print_rules("3.9 stmt -> funcdef");}
#line 1668 "parser.cpp"
    break;

  case 14:
#line 105 "parser.y"
                                                                        {print_rules("3.10 stmt -> ;");}
#line 1674 "parser.cpp"
    break;

  case 15:
#line 109 "parser.y"
                                                        {print_rules("4.1 expr -> assignexpr");}
#line 1680 "parser.cpp"
    break;

  case 16:
#line 110 "parser.y"
                                                                {print_rules("4.2 expr -> expr + expr");}
#line 1686 "parser.cpp"
    break;

  case 17:
#line 111 "parser.y"
                                                                {print_rules("4.3 expr -> expr - expr");}
#line 1692 "parser.cpp"
    break;

  case 18:
#line 112 "parser.y"
                                                                {print_rules("4.4 expr -> expr * expr");}
#line 1698 "parser.cpp"
    break;

  case 19:
#line 113 "parser.y"
                                                                {print_rules("4.5 expr -> expr / expr");}
#line 1704 "parser.cpp"
    break;

  case 20:
#line 114 "parser.y"
                                                                {print_rules("4.6 expr -> expr \% expr");}
#line 1710 "parser.cpp"
    break;

  case 21:
#line 115 "parser.y"
                                                                {print_rules("4.7 expr -> expr > expr");}
#line 1716 "parser.cpp"
    break;

  case 22:
#line 116 "parser.y"
                                                        {print_rules("4.8 expr -> expr >= expr");}
#line 1722 "parser.cpp"
    break;

  case 23:
#line 117 "parser.y"
                                                                {print_rules("4.9 expr -> expr < expr");}
#line 1728 "parser.cpp"
    break;

  case 24:
#line 118 "parser.y"
                                                        {print_rules("4.10 expr -> expr <= expr");}
#line 1734 "parser.cpp"
    break;

  case 25:
#line 119 "parser.y"
                                                                {print_rules("4.11 expr -> expr == expr");}
#line 1740 "parser.cpp"
    break;

  case 26:
#line 120 "parser.y"
                                                        {print_rules("4.12 expr -> expr != expr");}
#line 1746 "parser.cpp"
    break;

  case 27:
#line 121 "parser.y"
                                                                {print_rules("4.13 expr -> expr AND expr");}
#line 1752 "parser.cpp"
    break;

  case 28:
#line 122 "parser.y"
                                                                {print_rules("4.14 expr -> expr OR expr");}
#line 1758 "parser.cpp"
    break;

  case 29:
#line 123 "parser.y"
                                                                        {print_rules("4.15 expr -> term");}
#line 1764 "parser.cpp"
    break;

  case 30:
#line 126 "parser.y"
                                                {print_rules("5.1 term -> ( expr )");}
#line 1770 "parser.cpp"
    break;

  case 31:
#line 127 "parser.y"
                                                        {print_rules("5.2 term -> - expr");}
#line 1776 "parser.cpp"
    break;

  case 32:
#line 128 "parser.y"
                                                                        {print_rules("5.3 term -> NOT expr");}
#line 1782 "parser.cpp"
    break;

  case 33:
#line 129 "parser.y"
                                                                {
											print_rules("5.4 term -> ++ lvalue");
											if((yyvsp[0].st_entryVal)->type == USER_FUNC || (yyvsp[0].st_entryVal)->type == LIB_FUNC){
												yyerror("functions are constant, their value cannot be changed");
											}
										}
#line 1793 "parser.cpp"
    break;

  case 34:
#line 135 "parser.y"
                                                                {
											print_rules("5.5 term -> lvalue ++");
											if((yyvsp[-1].st_entryVal)->type == USER_FUNC || (yyvsp[-1].st_entryVal)->type == LIB_FUNC){
												yyerror("functions are constant, their value cannot be changed");
											}
										}
#line 1804 "parser.cpp"
    break;

  case 35:
#line 141 "parser.y"
                                                                {
											print_rules("5.6 term -> -- lvalue");
											if((yyvsp[0].st_entryVal)->type == USER_FUNC || (yyvsp[0].st_entryVal)->type == LIB_FUNC){
												yyerror("functions are constant, their value cannot be changed");
											}
										}
#line 1815 "parser.cpp"
    break;

  case 36:
#line 147 "parser.y"
                                                                {
											print_rules("5.7 term ->  lvalue --");
											if((yyvsp[-1].st_entryVal)->type == USER_FUNC || (yyvsp[-1].st_entryVal)->type == LIB_FUNC){
												yyerror("functions are constant, their value cannot be changed");
											}
										}
#line 1826 "parser.cpp"
    break;

  case 37:
#line 153 "parser.y"
                                                                        {print_rules("5.8 term -> primary");}
#line 1832 "parser.cpp"
    break;

  case 38:
#line 156 "parser.y"
                                                {
											print_rules("6.1 assignexpr -> lvalue = expr");
		   							 		if(!member_flag && (yyvsp[-2].st_entryVal) && ((yyvsp[-2].st_entryVal)->type==LIB_FUNC || (yyvsp[-2].st_entryVal)->type==USER_FUNC) ) 
												 yyerror("invalid assignment (lvalue is a function)");
											if(member_flag)
												member_flag = false;
										}
#line 1844 "parser.cpp"
    break;

  case 39:
#line 166 "parser.y"
                                                                {print_rules("7.1 primary -> lvalue");}
#line 1850 "parser.cpp"
    break;

  case 40:
#line 167 "parser.y"
                                                                        {print_rules("7.2 primary -> call");}
#line 1856 "parser.cpp"
    break;

  case 41:
#line 168 "parser.y"
                                                                        {print_rules("7.3 primary -> objectdef");}
#line 1862 "parser.cpp"
    break;

  case 42:
#line 169 "parser.y"
                                                        {print_rules("7.4 primary -> ( funcdef )");}
#line 1868 "parser.cpp"
    break;

  case 43:
#line 170 "parser.y"
                                                                        {print_rules("7.5 primary -> const");}
#line 1874 "parser.cpp"
    break;

  case 44:
#line 173 "parser.y"
                                                                {
											print_rules("8.1 lvalue -> ID");
											st_entry_tmp["r8"] = st_lookup(*(yyvsp[0].strConst));
											if(!st_entry_tmp["r8"]){
												(yyval.st_entryVal) = st_insert(*(yyvsp[0].strConst), (st_get_scope() == 0) ? GLOBAL_VAR : LOCAL_VAR);
											}
											else if( (st_entry_tmp["r8"]->scope != 0) && st_entry_tmp["r8"]->type != USER_FUNC
													&& !func_stack.empty() && 
													(st_entry_tmp["r8"]->scope <= func_stack.top()->scope) ){
												yyerror("Cannot access local var \'"+*(yyvsp[0].strConst)+"\' inside function \'"
												+func_stack.top()->name + "\'");
												(yyval.st_entryVal) = NULL;
											}
											else{
												(yyval.st_entryVal) = st_entry_tmp["r8"];
											}
										}
#line 1896 "parser.cpp"
    break;

  case 45:
#line 190 "parser.y"
                                                                        {
											print_rules("8.2 lvalue -> local ID");
											st_entry_tmp["r8"] = st_lookup(*(yyvsp[0].strConst));
											if(st_entry_tmp["r8"] && (st_entry_tmp["r8"]->scope == st_get_scope()) ){
												(yyval.st_entryVal) = st_entry_tmp["r8"];
											}
											else if(st_entry_tmp["r8"] && st_entry_tmp["r8"]->type == LIB_FUNC){
												yyerror("variable \'" + *(yyvsp[0].strConst) + "\' shadows lib function");
											}
											else{
												(yyval.st_entryVal) = st_insert(*(yyvsp[0].strConst), (st_get_scope() == 0) ? GLOBAL_VAR : LOCAL_VAR);
											}
										}
#line 1914 "parser.cpp"
    break;

  case 46:
#line 203 "parser.y"
                                                                {
											print_rules("8.3 lvalue -> ::ID");
											st_entry_tmp["r8"] = st_lookup(*(yyvsp[0].strConst), 0);
											if(!st_entry_tmp["r8"]){
												yyerror("No global variable "+*(yyvsp[0].strConst)+" exists.");
												(yyval.st_entryVal) = NULL;
											}
											else {
												(yyval.st_entryVal) = st_entry_tmp["r8"];
											}
										}
#line 1930 "parser.cpp"
    break;

  case 47:
#line 214 "parser.y"
                                                                        {
											print_rules("8.4 lvalue -> member");

										}
#line 1939 "parser.cpp"
    break;

  case 48:
#line 220 "parser.y"
                                                        {
											print_rules("9.1 member -> lvalue . ID");
											member_flag = true;
										}
#line 1948 "parser.cpp"
    break;

  case 49:
#line 224 "parser.y"
                                                        {
											print_rules("9.2 member -> lvalue [ expr ]");
											member_flag = true;
										}
#line 1957 "parser.cpp"
    break;

  case 50:
#line 228 "parser.y"
                                                                {
											print_rules("9.3 member -> call . ID");
											member_flag = true;
										}
#line 1966 "parser.cpp"
    break;

  case 51:
#line 232 "parser.y"
                                                        {
											print_rules("9.4 member -> call [ expr ]");
											member_flag = true;
										}
#line 1975 "parser.cpp"
    break;

  case 52:
#line 238 "parser.y"
                                                {print_rules("10.1 member -> call ( elist )");}
#line 1981 "parser.cpp"
    break;

  case 53:
#line 239 "parser.y"
                                                                {print_rules("10.2 member -> lvalue callsuffix");}
#line 1987 "parser.cpp"
    break;

  case 54:
#line 241 "parser.y"
                                                                                {print_rules("10.3 member -> ( funcdef ) ( elist )");}
#line 1993 "parser.cpp"
    break;

  case 55:
#line 244 "parser.y"
                                                                {print_rules("11.1 member -> normcall");}
#line 1999 "parser.cpp"
    break;

  case 56:
#line 245 "parser.y"
                                                                {print_rules("11.2 member -> methodcall");}
#line 2005 "parser.cpp"
    break;

  case 57:
#line 248 "parser.y"
                                                {print_rules("12.1 normcall -> ( elist )");}
#line 2011 "parser.cpp"
    break;

  case 58:
#line 251 "parser.y"
                                               {print_rules("13.1 methodcall -> .. ID ( elist )");}
#line 2017 "parser.cpp"
    break;

  case 59:
#line 254 "parser.y"
                                                                {print_rules("14.1 elist -> expr");}
#line 2023 "parser.cpp"
    break;

  case 60:
#line 255 "parser.y"
                                                                {print_rules("14.2 elist -> elist , expr");}
#line 2029 "parser.cpp"
    break;

  case 61:
#line 256 "parser.y"
                                                                                {print_rules("14.3 elist -> ε");}
#line 2035 "parser.cpp"
    break;

  case 62:
#line 259 "parser.y"
                                                {print_rules("15.1 objectdef -> [ elist ]");}
#line 2041 "parser.cpp"
    break;

  case 63:
#line 260 "parser.y"
                                                        {print_rules("15.2 objectdef -> [ indexed ]");}
#line 2047 "parser.cpp"
    break;

  case 64:
#line 263 "parser.y"
                                                        {print_rules("16.1 indexed -> indexedelem");}
#line 2053 "parser.cpp"
    break;

  case 65:
#line 264 "parser.y"
                                                        {print_rules("16.2 indexed ->  indexed , indexedelem");}
#line 2059 "parser.cpp"
    break;

  case 66:
#line 268 "parser.y"
                                                                        {print_rules("17.1 indexedelem -> { expr : expr }");}
#line 2065 "parser.cpp"
    break;

  case 67:
#line 271 "parser.y"
                                                                { 	print_rules("18.1 block -> { stmts }");
											st_increase_scope();}
#line 2072 "parser.cpp"
    break;

  case 68:
#line 273 "parser.y"
                                                                {
											st_hide(st_get_scope()); st_decrease_scope();
										}
#line 2080 "parser.cpp"
    break;

  case 69:
#line 278 "parser.y"
                                                                {	print_rules("19.1 funcdef -> function ( idlist ) block");
											st_entry_tmp["r19"] = st_insert(st_godfather(), USER_FUNC);
											func_stack.push(st_entry_tmp["r19"]);
										}
#line 2089 "parser.cpp"
    break;

  case 70:
#line 282 "parser.y"
                                                                        {st_increase_scope();}
#line 2095 "parser.cpp"
    break;

  case 71:
#line 283 "parser.y"
                                                                {
				  							
				  							offload_arglist(st_entry_tmp["r19"]);
											st_decrease_scope();
										}
#line 2105 "parser.cpp"
    break;

  case 72:
#line 288 "parser.y"
                                                                        {
											func_stack.pop();
										}
#line 2113 "parser.cpp"
    break;

  case 73:
#line 291 "parser.y"
                                                                        {	
											print_rules("19.2 funcdef -> function ID ( idlist ) block");
											
										}
#line 2122 "parser.cpp"
    break;

  case 74:
#line 295 "parser.y"
                                                                        {	
											st_entry_tmp["r19"] = st_lookup(*(yyvsp[0].strConst));
											if((!st_entry_tmp["r19"]) ||
												( (st_entry_tmp["r19"]->scope < st_get_scope())
												&& (st_entry_tmp["r19"]->type != LIB_FUNC) ) )
											{
												st_entry_tmp["r19"] = st_insert(*(yyvsp[0].strConst), USER_FUNC);
												func_stack.push(st_entry_tmp["r19"]);// push to func stack mono an einai valid
											}
											else
											{
												if(st_entry_tmp["r19"]->type == USER_FUNC)// kseroume oti einai locally defined
													yyerror("redefinition of user function defined in line "
													+ std::to_string(st_entry_tmp["r19"]->line));
												else if(st_entry_tmp["r19"]->type == LIB_FUNC){
													yyerror("function definition shadows lib function");
												}
												else if(st_entry_tmp["r19"]->type == LOCAL_VAR
														|| st_entry_tmp["r19"]->type == FORMAL_ARG
														|| st_entry_tmp["r19"]->type == GLOBAL_VAR){
													yyerror("variable \""+ *(yyvsp[0].strConst) + "\" already defined in line "
													+std::to_string(st_entry_tmp["r19"]->line));
												}
												else{	/* Exei vre8ei to active token, den einai user i lib func,
														 den einai active variable  */
													yyerror("UNHANDLED CASE ?\nonoma: " + st_entry_tmp["r19"]->name +
													" typos: " + std::to_string(st_entry_tmp["r19"]->type) + 
													" grammh: " + std::to_string(st_entry_tmp["r19"]->line));
												}
												st_entry_tmp["r19"] = NULL;
											}
										}
#line 2159 "parser.cpp"
    break;

  case 75:
#line 327 "parser.y"
                                                                        {	st_increase_scope();		}
#line 2165 "parser.cpp"
    break;

  case 76:
#line 328 "parser.y"
                                                                {
				  							if(st_entry_tmp["r19"]){
												offload_arglist(st_entry_tmp["r19"]);
											}
											st_decrease_scope();
										}
#line 2176 "parser.cpp"
    break;

  case 77:
#line 334 "parser.y"
                                                                        {
											if(st_entry_tmp["r19"])
												func_stack.pop();
										}
#line 2185 "parser.cpp"
    break;

  case 78:
#line 340 "parser.y"
                                                                {print_rules("20.1 const -> INTEGER");}
#line 2191 "parser.cpp"
    break;

  case 79:
#line 341 "parser.y"
                                                                        {print_rules("20.2 const -> REAL");}
#line 2197 "parser.cpp"
    break;

  case 80:
#line 342 "parser.y"
                                                                        {print_rules("20.3 const -> STRING");}
#line 2203 "parser.cpp"
    break;

  case 81:
#line 343 "parser.y"
                                                                        {print_rules("20.4 const -> NIL");}
#line 2209 "parser.cpp"
    break;

  case 82:
#line 344 "parser.y"
                                                                        {print_rules("20.5 const -> TRUE");}
#line 2215 "parser.cpp"
    break;

  case 83:
#line 345 "parser.y"
                                                                        {print_rules("20.6 const -> FALSE");}
#line 2221 "parser.cpp"
    break;

  case 84:
#line 348 "parser.y"
                                                                {
											print_rules("22.1 idlist -> ID");
											st_entry_tmp["r21"] = st_lookup(*(yyvsp[0].strConst), 0);
											if(st_entry_tmp["r21"] && st_entry_tmp["r21"]->type ==  LIB_FUNC){
												yyerror("formal argument " + *(yyvsp[0].strConst) + " shadows lib func");
											}
											else{
												st_entry_tmp["r21"] = st_insert(*(yyvsp[0].strConst), FORMAL_ARG);
												load_2_arglist(st_entry_tmp["r21"]);
											}
										}
#line 2237 "parser.cpp"
    break;

  case 85:
#line 359 "parser.y"
                                                                {
											print_rules("22.2 idlist -> idlist , ID");
											st_entry_tmp["r21"] = st_lookup(*(yyvsp[0].strConst));
											if(st_entry_tmp["r21"] && (st_entry_tmp["r21"]->type == FORMAL_ARG)){ // conflict
												yyerror("Argument "+ *(yyvsp[0].strConst) +" already exists.");
											}
											else if(st_entry_tmp["r21"] && st_entry_tmp["r21"]->type == LIB_FUNC){
												yyerror("formal argument " + *(yyvsp[0].strConst) + " shadows lib func");
											}
											else{
												st_entry_tmp["r21"] = st_insert(*(yyvsp[0].strConst), FORMAL_ARG);
												load_2_arglist(st_entry_tmp["r21"]);
											}										
										}
#line 2256 "parser.cpp"
    break;

  case 87:
#line 376 "parser.y"
                                            {print_rules("23.1 ifstmt -> if ( expr ) stmt");}
#line 2262 "parser.cpp"
    break;

  case 88:
#line 377 "parser.y"
                                                              {print_rules("23.2 ifstmt -> if ( expr ) stmt else stmt");}
#line 2268 "parser.cpp"
    break;

  case 89:
#line 380 "parser.y"
                                               {print_rules("24.1 whilestmt -> while ( expr ) stmt");}
#line 2274 "parser.cpp"
    break;

  case 90:
#line 383 "parser.y"
                                                                              {print_rules("25.1 forstmt -> for ( elist ; expr ; elist ) stmt");}
#line 2280 "parser.cpp"
    break;

  case 91:
#line 386 "parser.y"
                                                        {
											print_rules("26.1 returnstmt -> return ;");
											if (func_stack.empty()){
												yyerror("Use of 'return' while not in a function\n");
											}
										}
#line 2291 "parser.cpp"
    break;

  case 92:
#line 392 "parser.y"
                                                        {
											print_rules("26.2 returnstmt -> return expr ;");
											if (func_stack.empty()){
												yyerror("Use of 'return' while not in a function\n");
											}
										}
#line 2302 "parser.cpp"
    break;


#line 2306 "parser.cpp"

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
#line 400 "parser.y"


extern void validate_comments();
			
int yyerror(std:: string err){
	std::cout << "\033[31m" << "ERROR " << "\033[37m" <<
	"in line " << yylineno << " : " << err << "\n";
	return 1;
}

int main(int argc, char** argv) {
	std::cout << "\033[37m";
    if (argc > 1) {
		if (!(yyin = fopen(argv[1], "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
	} else {
		yyin = stdin;
	}
	st_initialize();
    while( yyparse() != 0);
	validate_comments();
	st_print_table();

    return 0;
}
