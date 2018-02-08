/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 17 "sql_old.y" /* yacc.c:339  */

package sqlparser

func setParseTree(yylex interface{}, stmt Statement) {
  yylex.(*Tokenizer).ParseTree = stmt
}

func setAllowComments(yylex interface{}, allow bool) {
  yylex.(*Tokenizer).AllowComments = allow
}

func setDDL(yylex interface{}, ddl *DDL) {
  yylex.(*Tokenizer).partialDDL = ddl
}

func incNesting(yylex interface{}) bool {
  yylex.(*Tokenizer).nesting++
  if yylex.(*Tokenizer).nesting == 200 {
    return true
  }
  return false
}

func decNesting(yylex interface{}) {
  yylex.(*Tokenizer).nesting--
}

// forceEOF forces the lexer to end prematurely. Not all SQL statements
// are supported by the Parser, thus calling forceEOF will make the lexer
// return EOF early.
func forceEOF(yylex interface{}) {
  yylex.(*Tokenizer).ForceEOF = true
}


#line 102 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    LEX_ERROR = 258,
    UNION = 259,
    SELECT = 260,
    INSERT = 261,
    UPDATE = 262,
    DELETE = 263,
    FROM = 264,
    WHERE = 265,
    GROUP = 266,
    HAVING = 267,
    ORDER = 268,
    BY = 269,
    LIMIT = 270,
    OFFSET = 271,
    FOR = 272,
    ALL = 273,
    DISTINCT = 274,
    AS = 275,
    EXISTS = 276,
    ASC = 277,
    DESC = 278,
    INTO = 279,
    DUPLICATE = 280,
    KEY = 281,
    DEFAULT = 282,
    SET = 283,
    LOCK = 284,
    VALUES = 285,
    LAST_INSERT_ID = 286,
    NEXT = 287,
    VALUE = 288,
    SHARE = 289,
    MODE = 290,
    SQL_NO_CACHE = 291,
    SQL_CACHE = 292,
    JOIN = 293,
    STRAIGHT_JOIN = 294,
    LEFT = 295,
    RIGHT = 296,
    INNER = 297,
    OUTER = 298,
    CROSS = 299,
    NATURAL = 300,
    USE = 301,
    FORCE = 302,
    ON = 303,
    USING = 304,
    ID = 305,
    HEX = 306,
    STRING = 307,
    INTEGRAL = 308,
    FLOAT = 309,
    HEXNUM = 310,
    VALUE_ARG = 311,
    LIST_ARG = 312,
    COMMENT = 313,
    COMMENT_KEYWORD = 314,
    BIT_LITERAL = 315,
    NULL = 316,
    TRUE = 317,
    FALSE = 318,
    OR = 319,
    AND = 320,
    NOT = 321,
    BETWEEN = 322,
    CASE = 323,
    WHEN = 324,
    THEN = 325,
    ELSE = 326,
    END = 327,
    LE = 328,
    GE = 329,
    NE = 330,
    NULL_SAFE_EQUAL = 331,
    IS = 332,
    LIKE = 333,
    REGEXP = 334,
    IN = 335,
    SHIFT_LEFT = 336,
    SHIFT_RIGHT = 337,
    DIV = 338,
    MOD = 339,
    UNARY = 340,
    COLLATE = 341,
    BINARY = 342,
    UNDERSCORE_BINARY = 343,
    INTERVAL = 344,
    JSON_EXTRACT_OP = 345,
    JSON_UNQUOTE_EXTRACT_OP = 346,
    CREATE = 347,
    ALTER = 348,
    DROP = 349,
    RENAME = 350,
    ANALYZE = 351,
    TABLE = 352,
    INDEX = 353,
    VIEW = 354,
    TO = 355,
    IGNORE = 356,
    IF = 357,
    UNIQUE = 358,
    PRIMARY = 359,
    SHOW = 360,
    DESCRIBE = 361,
    EXPLAIN = 362,
    DATE = 363,
    ESCAPE = 364,
    REPAIR = 365,
    OPTIMIZE = 366,
    TRUNCATE = 367,
    MAXVALUE = 368,
    PARTITION = 369,
    REORGANIZE = 370,
    LESS = 371,
    THAN = 372,
    BIT = 373,
    TINYINT = 374,
    SMALLINT = 375,
    MEDIUMINT = 376,
    INT = 377,
    INTEGER = 378,
    BIGINT = 379,
    INTNUM = 380,
    REAL = 381,
    DOUBLE = 382,
    FLOAT_TYPE = 383,
    DECIMAL = 384,
    NUMERIC = 385,
    TIME = 386,
    TIMESTAMP = 387,
    DATETIME = 388,
    YEAR = 389,
    CHAR = 390,
    VARCHAR = 391,
    BOOL = 392,
    CHARACTER = 393,
    VARBINARY = 394,
    NCHAR = 395,
    TEXT = 396,
    TINYTEXT = 397,
    MEDIUMTEXT = 398,
    LONGTEXT = 399,
    BLOB = 400,
    TINYBLOB = 401,
    MEDIUMBLOB = 402,
    LONGBLOB = 403,
    JSON = 404,
    ENUM = 405,
    NULLX = 406,
    AUTO_INCREMENT = 407,
    APPROXNUM = 408,
    SIGNED = 409,
    UNSIGNED = 410,
    ZEROFILL = 411,
    DATABASES = 412,
    TABLES = 413,
    VITESS_KEYSPACES = 414,
    VITESS_SHARDS = 415,
    VSCHEMA_TABLES = 416,
    NAMES = 417,
    CHARSET = 418,
    CURRENT_TIMESTAMP = 419,
    DATABASE = 420,
    CURRENT_DATE = 421,
    CURRENT_TIME = 422,
    LOCALTIME = 423,
    LOCALTIMESTAMP = 424,
    UTC_DATE = 425,
    UTC_TIME = 426,
    UTC_TIMESTAMP = 427,
    REPLACE = 428,
    CONVERT = 429,
    CAST = 430,
    GROUP_CONCAT = 431,
    SEPARATOR = 432,
    MATCH = 433,
    AGAINST = 434,
    BOOLEAN = 435,
    LANGUAGE = 436,
    WITH = 437,
    QUERY = 438,
    EXPANSION = 439,
    UNUSED = 440
  };
#endif
/* Tokens.  */
#define LEX_ERROR 258
#define UNION 259
#define SELECT 260
#define INSERT 261
#define UPDATE 262
#define DELETE 263
#define FROM 264
#define WHERE 265
#define GROUP 266
#define HAVING 267
#define ORDER 268
#define BY 269
#define LIMIT 270
#define OFFSET 271
#define FOR 272
#define ALL 273
#define DISTINCT 274
#define AS 275
#define EXISTS 276
#define ASC 277
#define DESC 278
#define INTO 279
#define DUPLICATE 280
#define KEY 281
#define DEFAULT 282
#define SET 283
#define LOCK 284
#define VALUES 285
#define LAST_INSERT_ID 286
#define NEXT 287
#define VALUE 288
#define SHARE 289
#define MODE 290
#define SQL_NO_CACHE 291
#define SQL_CACHE 292
#define JOIN 293
#define STRAIGHT_JOIN 294
#define LEFT 295
#define RIGHT 296
#define INNER 297
#define OUTER 298
#define CROSS 299
#define NATURAL 300
#define USE 301
#define FORCE 302
#define ON 303
#define USING 304
#define ID 305
#define HEX 306
#define STRING 307
#define INTEGRAL 308
#define FLOAT 309
#define HEXNUM 310
#define VALUE_ARG 311
#define LIST_ARG 312
#define COMMENT 313
#define COMMENT_KEYWORD 314
#define BIT_LITERAL 315
#define NULL 316
#define TRUE 317
#define FALSE 318
#define OR 319
#define AND 320
#define NOT 321
#define BETWEEN 322
#define CASE 323
#define WHEN 324
#define THEN 325
#define ELSE 326
#define END 327
#define LE 328
#define GE 329
#define NE 330
#define NULL_SAFE_EQUAL 331
#define IS 332
#define LIKE 333
#define REGEXP 334
#define IN 335
#define SHIFT_LEFT 336
#define SHIFT_RIGHT 337
#define DIV 338
#define MOD 339
#define UNARY 340
#define COLLATE 341
#define BINARY 342
#define UNDERSCORE_BINARY 343
#define INTERVAL 344
#define JSON_EXTRACT_OP 345
#define JSON_UNQUOTE_EXTRACT_OP 346
#define CREATE 347
#define ALTER 348
#define DROP 349
#define RENAME 350
#define ANALYZE 351
#define TABLE 352
#define INDEX 353
#define VIEW 354
#define TO 355
#define IGNORE 356
#define IF 357
#define UNIQUE 358
#define PRIMARY 359
#define SHOW 360
#define DESCRIBE 361
#define EXPLAIN 362
#define DATE 363
#define ESCAPE 364
#define REPAIR 365
#define OPTIMIZE 366
#define TRUNCATE 367
#define MAXVALUE 368
#define PARTITION 369
#define REORGANIZE 370
#define LESS 371
#define THAN 372
#define BIT 373
#define TINYINT 374
#define SMALLINT 375
#define MEDIUMINT 376
#define INT 377
#define INTEGER 378
#define BIGINT 379
#define INTNUM 380
#define REAL 381
#define DOUBLE 382
#define FLOAT_TYPE 383
#define DECIMAL 384
#define NUMERIC 385
#define TIME 386
#define TIMESTAMP 387
#define DATETIME 388
#define YEAR 389
#define CHAR 390
#define VARCHAR 391
#define BOOL 392
#define CHARACTER 393
#define VARBINARY 394
#define NCHAR 395
#define TEXT 396
#define TINYTEXT 397
#define MEDIUMTEXT 398
#define LONGTEXT 399
#define BLOB 400
#define TINYBLOB 401
#define MEDIUMBLOB 402
#define LONGBLOB 403
#define JSON 404
#define ENUM 405
#define NULLX 406
#define AUTO_INCREMENT 407
#define APPROXNUM 408
#define SIGNED 409
#define UNSIGNED 410
#define ZEROFILL 411
#define DATABASES 412
#define TABLES 413
#define VITESS_KEYSPACES 414
#define VITESS_SHARDS 415
#define VSCHEMA_TABLES 416
#define NAMES 417
#define CHARSET 418
#define CURRENT_TIMESTAMP 419
#define DATABASE 420
#define CURRENT_DATE 421
#define CURRENT_TIME 422
#define LOCALTIME 423
#define LOCALTIMESTAMP 424
#define UTC_DATE 425
#define UTC_TIME 426
#define UTC_TIMESTAMP 427
#define REPLACE 428
#define CONVERT 429
#define CAST 430
#define GROUP_CONCAT 431
#define SEPARATOR 432
#define MATCH 433
#define AGAINST 434
#define BOOLEAN 435
#define LANGUAGE 436
#define WITH 437
#define QUERY 438
#define EXPANSION 439
#define UNUSED 440

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 53 "sql_old.y" /* yacc.c:355  */

  empty         struct{}
  statement     Statement
  selStmt       SelectStatement
  ddl           *DDL
  ins           *Insert
  byt           byte
  bytes         []byte
  bytes2        [][]byte
  str           string
  strs          []string
  selectExprs   SelectExprs
  selectExpr    SelectExpr
  columns       Columns
  colName       *ColName
  tableExprs    TableExprs
  tableExpr     TableExpr
  joinCondition JoinCondition
  tableName     TableName
  tableNames    TableNames
  indexHints    *IndexHints
  expr          Expr
  exprs         Exprs
  boolVal       BoolVal
  colTuple      ColTuple
  values        Values
  valTuple      ValTuple
  subquery      *Subquery
  whens         []*When
  when          *When
  orderBy       OrderBy
  order         *Order
  limit         *Limit
  updateExprs   UpdateExprs
  updateExpr    *UpdateExpr
  colIdent      ColIdent
  colIdents     []ColIdent
  tableIdent    TableIdent
  convertType   *ConvertType
  aliasedTableName *AliasedTableExpr
  TableSpec  *TableSpec
  columnType    ColumnType
  colKeyOpt     ColumnKeyOption
  optVal        *SQLVal
  LengthScaleOption LengthScaleOption
  columnDefinition *ColumnDefinition
  indexDefinition *IndexDefinition
  indexInfo     *IndexInfo
  indexColumn   *IndexColumn
  indexColumns  []*IndexColumn
  partDefs      []*PartitionDefinition
  partDef       *PartitionDefinition
  partSpec      *PartitionSpec

#line 564 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 581 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  227
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7792

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  204
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  159
/* YYNRULES -- Number of rules.  */
#define YYNRULES  627
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1020

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   440

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,     2,     2,    97,    89,     2,
      50,    52,    94,    92,    51,    93,   106,    95,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   203,
      78,    77,    79,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    99,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    88,     2,   100,     2,     2,     2,
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
      45,    46,    47,    48,    49,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    71,    72,    73,    74,    75,    76,    80,    81,
      82,    83,    84,    85,    86,    87,    90,    91,    96,    98,
     101,   102,   103,   104,   105,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   274,   274,   280,   281,   284,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   303,
     311,   315,   322,   328,   332,   338,   342,   349,   360,   372,
     376,   382,   388,   392,   398,   399,   402,   406,   412,   416,
     422,   423,   424,   427,   431,   437,   442,   447,   451,   457,
     464,   471,   476,   480,   486,   497,   503,   504,   507,   512,
     518,   522,   526,   530,   534,   538,   542,   548,   554,   560,
     566,   572,   580,   584,   588,   592,   596,   602,   606,   610,
     614,   618,   622,   626,   630,   634,   638,   642,   646,   650,
     654,   660,   665,   671,   674,   680,   683,   692,   695,   701,
     710,   713,   719,   722,   729,   732,   736,   742,   745,   749,
     753,   757,   761,   767,   770,   776,   779,   785,   788,   792,
     798,   801,   807,   810,   814,   818,   822,   828,   831,   837,
     843,   847,   851,   855,   861,   865,   871,   875,   881,   887,
     890,   894,   902,   906,   910,   916,   920,   924,   930,   934,
     939,   944,   948,   954,   960,   964,   970,   974,   980,   986,
     994,   999,  1009,  1013,  1018,  1024,  1028,  1037,  1048,  1054,
    1058,  1064,  1068,  1072,  1076,  1080,  1086,  1086,  1096,  1099,
    1105,  1109,  1113,  1119,  1122,  1126,  1132,  1135,  1141,  1144,
    1150,  1153,  1159,  1163,  1169,  1173,  1177,  1181,  1187,  1190,
    1194,  1200,  1201,  1207,  1210,  1216,  1220,  1226,  1227,  1230,
    1234,  1238,  1244,  1250,  1254,  1267,  1271,  1275,  1279,  1285,
    1287,  1291,  1293,  1297,  1299,  1303,  1304,  1308,  1311,  1315,
    1321,  1322,  1328,  1332,  1336,  1342,  1348,  1352,  1356,  1360,
    1366,  1370,  1380,  1384,  1390,  1394,  1400,  1403,  1407,  1411,
    1417,  1421,  1427,  1430,  1436,  1440,  1444,  1448,  1452,  1456,
    1460,  1467,  1470,  1476,  1480,  1486,  1490,  1494,  1498,  1502,
    1506,  1510,  1514,  1518,  1522,  1528,  1532,  1536,  1540,  1544,
    1548,  1554,  1558,  1562,  1566,  1570,  1574,  1578,  1584,  1587,
    1593,  1597,  1601,  1607,  1613,  1617,  1623,  1627,  1631,  1635,
    1639,  1643,  1647,  1651,  1655,  1659,  1663,  1667,  1671,  1675,
    1679,  1683,  1687,  1691,  1695,  1699,  1703,  1707,  1711,  1719,
    1733,  1737,  1741,  1749,  1750,  1751,  1752,  1759,  1763,  1767,
    1777,  1781,  1785,  1789,  1793,  1797,  1801,  1805,  1809,  1819,
    1823,  1827,  1831,  1836,  1841,  1846,  1851,  1856,  1858,  1865,
    1869,  1873,  1877,  1884,  1887,  1891,  1895,  1899,  1905,  1909,
    1915,  1919,  1923,  1927,  1931,  1935,  1941,  1945,  1949,  1953,
    1957,  1961,  1965,  1971,  1974,  1980,  1983,  1989,  1993,  1999,
    2005,  2008,  2014,  2018,  2022,  2028,  2032,  2036,  2040,  2044,
    2048,  2052,  2056,  2062,  2071,  2075,  2081,  2084,  2090,  2093,
    2099,  2102,  2108,  2112,  2118,  2124,  2127,  2131,  2137,  2140,
    2144,  2148,  2154,  2157,  2161,  2174,  2178,  2182,  2187,  2191,
    2195,  2202,  2206,  2210,  2214,  2220,  2223,  2229,  2233,  2239,
    2243,  2249,  2255,  2265,  2269,  2275,  2281,  2282,  2285,  2286,
    2290,  2291,  2295,  2296,  2300,  2302,  2304,  2306,  2308,  2310,
    2312,  2314,  2316,  2318,  2320,  2324,  2325,  2327,  2331,  2333,
    2337,  2338,  2340,  2344,  2345,  2349,  2353,  2359,  2360,  2366,
    2370,  2376,  2377,  2392,  2393,  2394,  2395,  2396,  2397,  2398,
    2399,  2400,  2401,  2402,  2403,  2404,  2405,  2406,  2407,  2408,
    2409,  2410,  2411,  2412,  2413,  2414,  2415,  2416,  2417,  2418,
    2419,  2420,  2421,  2422,  2423,  2424,  2425,  2426,  2427,  2428,
    2429,  2430,  2431,  2432,  2433,  2434,  2435,  2436,  2437,  2438,
    2439,  2440,  2441,  2442,  2443,  2444,  2445,  2446,  2447,  2448,
    2449,  2450,  2451,  2452,  2453,  2454,  2455,  2456,  2457,  2458,
    2459,  2460,  2461,  2462,  2463,  2464,  2465,  2466,  2467,  2468,
    2469,  2470,  2471,  2472,  2473,  2474,  2475,  2476,  2477,  2478,
    2479,  2489,  2490,  2491,  2492,  2493,  2494,  2495,  2496,  2497,
    2498,  2499,  2500,  2501,  2502,  2503,  2504,  2505,  2506,  2507,
    2508,  2509,  2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,
    2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,  2526,  2527,
    2528,  2529,  2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,
    2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,
    2548,  2549,  2552,  2561,  2567,  2572,  2575,  2579
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEX_ERROR", "UNION", "SELECT", "INSERT",
  "UPDATE", "DELETE", "FROM", "WHERE", "GROUP", "HAVING", "ORDER", "BY",
  "LIMIT", "OFFSET", "FOR", "ALL", "DISTINCT", "AS", "EXISTS", "ASC",
  "DESC", "INTO", "DUPLICATE", "KEY", "DEFAULT", "SET", "LOCK", "VALUES",
  "LAST_INSERT_ID", "NEXT", "VALUE", "SHARE", "MODE", "SQL_NO_CACHE",
  "SQL_CACHE", "JOIN", "STRAIGHT_JOIN", "LEFT", "RIGHT", "INNER", "OUTER",
  "CROSS", "NATURAL", "USE", "FORCE", "ON", "USING", "'('", "','", "')'",
  "ID", "HEX", "STRING", "INTEGRAL", "FLOAT", "HEXNUM", "VALUE_ARG",
  "LIST_ARG", "COMMENT", "COMMENT_KEYWORD", "BIT_LITERAL", "NULL", "TRUE",
  "FALSE", "OR", "AND", "NOT", "'!'", "BETWEEN", "CASE", "WHEN", "THEN",
  "ELSE", "END", "'='", "'<'", "'>'", "LE", "GE", "NE", "NULL_SAFE_EQUAL",
  "IS", "LIKE", "REGEXP", "IN", "'|'", "'&'", "SHIFT_LEFT", "SHIFT_RIGHT",
  "'+'", "'-'", "'*'", "'/'", "DIV", "'%'", "MOD", "'^'", "'~'", "UNARY",
  "COLLATE", "BINARY", "UNDERSCORE_BINARY", "INTERVAL", "'.'",
  "JSON_EXTRACT_OP", "JSON_UNQUOTE_EXTRACT_OP", "CREATE", "ALTER", "DROP",
  "RENAME", "ANALYZE", "TABLE", "INDEX", "VIEW", "TO", "IGNORE", "IF",
  "UNIQUE", "PRIMARY", "SHOW", "DESCRIBE", "EXPLAIN", "DATE", "ESCAPE",
  "REPAIR", "OPTIMIZE", "TRUNCATE", "MAXVALUE", "PARTITION", "REORGANIZE",
  "LESS", "THAN", "BIT", "TINYINT", "SMALLINT", "MEDIUMINT", "INT",
  "INTEGER", "BIGINT", "INTNUM", "REAL", "DOUBLE", "FLOAT_TYPE", "DECIMAL",
  "NUMERIC", "TIME", "TIMESTAMP", "DATETIME", "YEAR", "CHAR", "VARCHAR",
  "BOOL", "CHARACTER", "VARBINARY", "NCHAR", "TEXT", "TINYTEXT",
  "MEDIUMTEXT", "LONGTEXT", "BLOB", "TINYBLOB", "MEDIUMBLOB", "LONGBLOB",
  "JSON", "ENUM", "NULLX", "AUTO_INCREMENT", "APPROXNUM", "SIGNED",
  "UNSIGNED", "ZEROFILL", "DATABASES", "TABLES", "VITESS_KEYSPACES",
  "VITESS_SHARDS", "VSCHEMA_TABLES", "NAMES", "CHARSET",
  "CURRENT_TIMESTAMP", "DATABASE", "CURRENT_DATE", "CURRENT_TIME",
  "LOCALTIME", "LOCALTIMESTAMP", "UTC_DATE", "UTC_TIME", "UTC_TIMESTAMP",
  "REPLACE", "CONVERT", "CAST", "GROUP_CONCAT", "SEPARATOR", "MATCH",
  "AGAINST", "BOOLEAN", "LANGUAGE", "WITH", "QUERY", "EXPANSION", "UNUSED",
  "';'", "$accept", "any_command", "semicolon_opt", "command",
  "select_statement", "base_select", "union_lhs", "union_rhs",
  "insert_statement", "insert_or_replace", "update_statement",
  "delete_statement", "from_or_using", "table_name_list", "set_statement",
  "charset_or_character_set", "charset_value", "create_statement",
  "create_table_prefix", "table_spec", "table_column_list",
  "column_definition", "column_type", "numeric_type", "int_type",
  "decimal_type", "time_type", "char_type", "enum_values", "length_opt",
  "float_length_opt", "decimal_length_opt", "unsigned_opt",
  "zero_fill_opt", "null_opt", "column_default_opt", "on_update_opt",
  "auto_increment_opt", "charset_opt", "collate_opt", "column_key_opt",
  "column_comment_opt", "index_definition", "index_info", "index_or_key",
  "index_column_list", "index_column", "table_option_list", "table_option",
  "table_opt_value", "alter_statement", "partition_operation",
  "partition_definitions", "partition_definition", "rename_statement",
  "drop_statement", "truncate_statement", "analyze_statement",
  "show_statement_type", "show_statement", "use_statement",
  "other_statement", "comment_opt", "$@1", "comment_list", "union_op",
  "cache_opt", "distinct_opt", "straight_join_opt",
  "select_expression_list_opt", "select_expression_list",
  "select_expression", "as_ci_opt", "col_alias", "from_opt",
  "table_references", "table_reference", "table_factor",
  "aliased_table_name", "using_column_list", "join_table",
  "join_condition", "join_condition_opt", "on_expression_opt", "as_opt",
  "as_opt_id", "table_alias", "inner_join", "straight_join", "outer_join",
  "natural_join", "into_table_name", "table_name", "index_hint_list",
  "index_list", "where_expression_opt", "expression", "default_opt",
  "boolean_value", "condition", "is_suffix", "compare", "like_escape_opt",
  "col_tuple", "subquery", "expression_list", "value_expression",
  "function_call_generic", "function_call_keyword",
  "function_call_nonkeyword", "func_datetime_precision_opt",
  "function_call_conflict", "match_option", "charset", "convert_type",
  "expression_opt", "separator_opt", "when_expression_list",
  "when_expression", "else_expression_opt", "column_name", "value",
  "num_val", "group_by_opt", "having_opt", "order_by_opt", "order_list",
  "order", "asc_desc_opt", "limit_opt", "lock_opt", "insert_data",
  "ins_column_list", "on_dup_opt", "tuple_list", "tuple_or_empty",
  "row_tuple", "tuple_expression", "update_list", "update_expression",
  "for_from", "exists_opt", "not_exists_opt", "ignore_opt",
  "non_rename_operation", "to_opt", "index_opt", "constraint_opt",
  "using_opt", "sql_id", "reserved_sql_id", "table_id",
  "reserved_table_id", "reserved_keyword", "non_reserved_keyword", "openb",
  "closeb", "force_eof", "ddl_force_eof", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      40,    44,    41,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
      33,   322,   323,   324,   325,   326,   327,    61,    60,    62,
     328,   329,   330,   331,   332,   333,   334,   335,   124,    38,
     336,   337,    43,    45,    42,    47,   338,    37,   339,    94,
     126,   340,   341,   342,   343,   344,    46,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,    59
};
# endif

#define YYPACT_NINF -625

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-625)))

#define YYTABLE_NINF -591

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     770,  -625,  -625,  -625,  -625,  -625,  -625,  7116,  -625,  5838,
     -58,   199,    -1,    31,  2916,  -625,  -625,  -625,  -625,  6326,
    -625,   128,   -31,   154,   188,   206,  -625,  -625,  -625,  -625,
    -625,  -625,   153,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,    46,   234,  -625,  6484,  4226,  -625,  7274,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,    24,    98,  7116,  -625,   114,  -625,  -625,
    7116,  -625,   124,   126,   194,   126,  7116,  7116,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  7116,  -625,   155,  -625,  -625,  -625,
     237,   262,   280,    66,   163,   238,  -625,   243,  -625,  -625,
      27,   240,   116,   355,  -625,  -625,  -625,  6010,   296,  3889,
    7116,   111,  -625,   226,   316,    47,    74,  2120,   259,   295,
    -625,  -625,   246,   252,   256,   329,  7116,  2319,   323,  2319,
    7116,   386,  7116,   361,  7116,   297,  -625,  -625,  -625,  3115,
    4974,  4974,    32,  -625,  -625,  -625,  -625,   188,    46,  6642,
    1185,   268,  -625,  -625,  -625,  -625,  6168,   409,  -625,  7432,
    6484,  -625,  -625,    19,   197,   387,   412,   219,  6484,  6484,
    6484,  6484,  6800,  -625,    21,  -625,  -625,  -625,  7116,   243,
     273,  3889,   445,  -625,  -625,  7116,  6484,  -625,  -625,  -625,
    -625,  -625,  -625,  4974,  7432,  3314,  7116,   451,  -625,  -625,
    -625,  -625,   425,  -625,    37,  -625,  -625,  7116,  2319,  7116,
    -625,  -625,  -625,   426,   426,   426,   426,   426,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  4974,  5330,
    4974,  5330,  5330,   426,  5330,  5330,  5330,  5330,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   152,  -625,  -625,  -625,  1284,  -625,  -625,
    -625,  -625,   235,  -625,   424,  -625,  -625,  -625,   426,   374,
    3700,   174,   474,   395,  -625,   234,   262,   243,  7116,    64,
    -625,   434,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
     440,   440,   440,   441,   441,   434,   434,   434,  -625,   434,
     434,   434,   337,   337,   337,   337,  -625,  -625,  -625,  -625,
    -625,   443,   179,   322,   434,  -625,  -625,  -625,    17,  1921,
     466,   467,   217,  -625,  -625,  4600,    42,   355,  -625,   462,
    -625,   463,  -625,  -625,  -625,  -625,   301,   456,   289,  -625,
    -625,   390,   391,   392,  -625,  -625,  -625,  -625,   243,  4974,
     188,  -625,    44,  -625,    97,  -625,  -625,   403,   406,  2319,
    -625,  7590,   460,  -625,  -625,  -625,  -625,  -625,  -625,    12,
    -625,   383,  -625,  -625,  -625,  -625,  -625,  -625,  2319,  -625,
    -625,  -625,    46,  -625,   464,  7590,  4600,  4600,   431,   414,
      97,   446,   414,   414,  4600,   414,   414,   414,  5508,  4600,
    -625,   243,  4600,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    4600,  4974,  4974,   502,  4600,  -625,  -625,  4974,  4974,   218,
    -625,   145,  5330,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    5330,  5330,     6,  5330,  5330,  5330,  5330,  5330,  5330,  5330,
    5330,  5330,  5330,  5330,  5330,    99,  5330,   307,   307,  4974,
    4413,  3314,    97,   308,  3700,  4974,  4974,  -625,   489,   502,
      32,  -625,  -625,  7432,   426,   154,   479,  4067,   473,  -625,
     475,  -625,  -625,  -625,   476,  -625,  -625,  -625,  -625,  -625,
     337,   337,  -625,   505,   428,   428,   428,   428,   480,  -625,
     477,   510,  -625,   376,  -625,  -625,  -625,    10,   513,  -625,
    -625,   497,   491,  -625,  -625,   499,  1722,  -625,  -625,  -625,
    -625,  -625,  -625,  7116,  -625,   122,  -625,  5680,   450,   188,
    -625,  -625,  4974,   501,  -625,  -625,  4974,  -625,  -625,   426,
     426,   426,   553,    97,   262,  -625,  3513,  -625,  -625,  7116,
    -625,  -625,  -625,  -625,  7116,  -625,  7590,  -625,  -625,   243,
     243,   353,   353,  4974,   103,  -625,   353,  -625,   353,  -625,
     243,   511,   353,   195,   115,  4600,   353,    72,   431,  -625,
    -625,  -625,   275,  -625,  5330,  5330,  5330,     6,   643,   549,
     923,  -625,  -625,  -625,  -625,   948,   494,   343,   343,   363,
     363,   166,   166,   166,   166,   166,   414,  -625,  -625,  -625,
     923,  -625,  -625,  -625,  4600,   243,   426,  4974,  -625,    97,
      97,   517,  -625,   245,   512,  -625,  -625,  4787,   536,  -625,
     243,   364,   459,   514,   518,   366,   428,   428,   -14,   515,
    -625,  -625,  -625,  -625,  -625,   369,  -625,   -22,   523,  -625,
    -625,  -625,   519,  -625,  7590,  -625,  1921,  1921,  -625,  -625,
    6484,  4600,   445,  6958,  -625,  -625,  -625,  -625,  2518,   262,
      97,  7590,    97,  7590,  7590,  7590,  -625,  -625,  2319,  -625,
    -625,   551,  -625,  -625,  -625,  -625,   121,  4974,  -625,   500,
    -625,  -625,  -625,  -625,    99,    52,    52,    75,   413,  -625,
    -625,  -625,   847,   549,   923,  -625,  5330,  5330,  -625,   353,
    -625,  4600,    97,  -625,  -625,   426,  -625,   547,   553,  7590,
      35,  7590,  -625,   554,   555,  -625,  -625,  -625,  -625,  -625,
    -625,   524,  -625,  -625,  -625,  -625,  -625,  -625,   605,   444,
    -625,   371,  -625,   434,  1722,  -625,   563,  -625,   604,  -625,
    -625,   516,  -625,   377,  -625,   379,  -625,   379,   379,  -625,
     426,  4974,    97,  -625,   243,   434,  -625,   441,   434,   434,
     434,   434,  -625,   478,   483,   243,   243,   422,   426,  5330,
    -625,   923,   923,  -625,   243,  -625,   610,   520,   426,   154,
      46,  -625,   568,   572,  -625,   447,  -625,    22,  7590,  -625,
    -625,   611,   615,  2717,  7590,  -625,  7590,  -625,  -625,  -625,
     498,    97,  -625,  -625,  -625,  -625,  -625,   -25,  -625,  -625,
    -625,  -625,  -625,   576,   243,  5330,   923,  -625,  7432,  7590,
     512,   243,  -625,  -625,  -625,  -625,   606,   607,   573,  -625,
    4974,  4974,  -625,  -625,  -625,  -625,  7590,   402,  -625,  -625,
    -625,  -625,  -625,    13,   295,  -625,   553,  -625,  -625,   594,
    -625,   599,    97,   622,   498,  -625,   -18,   453,   243,  -625,
     521,  -625,   457,   621,   458,  -625,   526,   623,  -625,  -625,
     426,   465,  5152,   461,   243,   -15,   471,  -625,  -625,  -625
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   176,    29,   176,   176,   624,   176,   170,   622,   460,
     442,     0,     0,     0,     0,   624,   624,   624,   624,     0,
      30,     0,     3,     5,   400,     0,     6,   176,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
      18,     0,   183,   178,     0,     0,   171,     0,   593,   574,
     582,   601,   589,   469,   569,   615,   596,   570,   600,   594,
     595,   599,   583,   605,   563,   609,   603,   587,   578,   579,
     562,   598,   573,   577,   572,   592,   606,   607,   571,   620,
     566,   614,   565,   567,   613,   591,   604,   610,   588,   585,
     564,   608,   586,   584,   580,   575,   602,   611,   621,   616,
     617,   618,   590,   568,   561,   581,   619,   597,   576,   612,
     169,   470,   465,     0,   440,   615,   461,     0,   462,   466,
       0,   443,     0,   438,     0,   438,     0,     0,   550,   540,
     513,   552,   491,   505,   560,   506,   507,   534,   479,   521,
     503,   494,   474,   500,   475,   492,   515,   518,   490,   542,
     524,   558,   529,   517,   544,   519,   539,   512,   535,   484,
     528,   553,   504,   532,   554,   165,   531,   549,   502,   533,
     473,   530,   477,   480,   559,   547,   497,   498,   516,   520,
     536,   510,   495,   527,   481,   478,   514,   483,   496,   537,
     545,   511,   548,   509,   508,   551,   543,   493,   501,   499,
     526,   476,   489,   546,   487,   488,   485,   486,   522,   523,
     555,   556,   557,   538,   482,   541,   525,   624,   166,   167,
     172,   173,   174,   175,     0,   163,   244,     1,     4,     2,
       0,   408,   180,     0,   442,     0,    45,    23,   184,   185,
     186,   177,     0,   205,   207,   209,   208,   227,   225,     0,
       0,     0,    36,   465,   567,    42,    40,     0,     0,    39,
     433,   382,     0,   466,     0,     0,     0,   625,     0,   625,
       0,     0,     0,     0,     0,     0,   164,   168,   162,     0,
       0,     0,   412,   181,   182,   176,    25,   400,     0,     0,
       0,     0,    51,   623,    24,   187,     0,   188,   179,     0,
       0,   232,   235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   231,   246,   228,   230,   226,     0,    23,
       0,     0,   252,    34,    35,     0,     0,    41,    44,   624,
     467,    43,   468,     0,     0,     0,     0,     0,    49,   627,
     626,    47,   463,   151,     0,   439,   159,     0,   625,     0,
     471,   245,   472,     0,   261,     0,     0,     0,   386,   385,
     388,   389,   390,   391,   387,   392,   263,   264,     0,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,   347,
       0,   347,   347,   347,   347,   347,   347,   347,     0,     0,
       0,     0,     0,   405,   297,   254,   300,   259,   323,   324,
     325,   326,   298,   296,   401,   402,   432,   299,   382,     0,
       0,   409,     0,     0,    19,   183,   408,    23,     0,     0,
     243,    93,    72,    60,    61,    62,    63,    64,    65,    66,
      95,    95,    95,    97,    97,    93,    93,    93,    76,    93,
      93,    93,   117,   117,   117,   117,    85,    86,    87,    88,
      89,     0,   104,   100,    93,    59,    57,    56,     0,   139,
       0,     0,     0,   393,   189,     0,   252,   206,   236,     0,
     238,     0,   233,   234,   240,   241,   221,   223,     0,   218,
     229,     0,     0,     0,   212,   210,   293,   211,    23,     0,
     400,    37,   252,    38,   435,   434,   383,     0,   468,   625,
     441,     0,     0,   450,   448,   454,   447,   444,   449,   455,
     452,     0,   446,   445,   451,   453,   152,   624,   625,   161,
     158,   274,     0,   260,     0,     0,     0,     0,   257,   321,
     374,     0,   318,   319,     0,   320,   316,   317,     0,     0,
     339,     0,   190,   345,   346,   343,   344,   342,   341,   340,
       0,     0,     0,   186,     0,   406,   407,     0,     0,     0,
     404,     0,     0,   281,   282,   283,   284,   285,   286,   287,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     190,     0,   294,     0,     0,     0,     0,   413,     0,   186,
     412,    26,   242,     0,     0,   416,   425,     0,     0,    79,
       0,    67,    68,    69,     0,    70,    71,    73,    74,    75,
     117,   117,    80,     0,   120,   120,   120,   120,     0,   105,
       0,   107,   101,   102,    58,   135,   134,     0,     0,    52,
      53,     0,     0,   146,   147,    50,   140,   142,   145,   394,
     395,   437,   436,     0,   194,   203,   192,   198,     0,   400,
     237,   239,     0,     0,   222,   215,     0,   216,   217,     0,
       0,     0,   293,   253,   408,    33,     0,    48,   464,     0,
     457,   459,   458,   456,     0,   624,     0,   148,   160,     0,
       0,     0,     0,     0,   380,   377,     0,   322,     0,   348,
       0,   191,     0,     0,     0,     0,     0,   256,   255,   275,
     277,   279,     0,   258,     0,     0,     0,     0,     0,   288,
     270,   292,   266,   291,   290,   302,   301,   311,   312,   304,
     305,   306,   307,   308,   309,   310,   303,   358,   359,   315,
     265,   313,   314,   403,     0,     0,   383,     0,   431,   411,
     410,     0,    20,   425,   415,   427,   429,     0,     0,    27,
      23,     0,   421,     0,     0,     0,   120,   120,     0,     0,
      81,    82,    83,    84,    91,     0,   106,     0,   113,   103,
      55,   132,     0,   130,     0,   133,     0,     0,   143,    21,
       0,     0,   252,     0,   202,   195,   199,   201,     0,   408,
     219,     0,   224,     0,     0,     0,    32,   384,   625,   149,
     150,     0,   262,   338,   330,   331,     0,     0,   378,     0,
     351,   349,   350,   352,     0,     0,     0,   400,     0,   276,
     278,   280,     0,   288,   271,   267,     0,     0,   268,     0,
     327,   190,   295,   414,    28,     0,   430,     0,   417,     0,
       0,     0,    94,     0,     0,    98,    77,    78,   118,   119,
     121,     0,    90,   108,   109,   110,   111,   112,     0,   115,
     131,     0,   136,    93,   141,   144,   204,   193,   396,   200,
     196,     0,    31,     0,   213,     0,   250,     0,     0,    46,
       0,     0,   381,   337,     0,    93,   363,    97,    93,    93,
      93,    93,   366,   368,   371,     0,     0,   375,     0,     0,
     269,   272,   289,   328,     0,   428,     0,   423,     0,   419,
       0,   422,     0,     0,    92,     0,   116,   122,     0,   129,
     138,     0,   398,     0,     0,   220,     0,   247,   249,   248,
       0,   379,   334,   360,   365,   370,   364,   117,   367,   369,
     372,   332,   333,     0,     0,     0,   273,   329,     0,     0,
     418,    23,    96,    99,   114,   124,   126,     0,   127,   137,
       0,     0,    22,   197,   214,   251,     0,     0,   154,   362,
     361,   376,   336,   353,   426,   424,   420,   125,   123,     0,
      54,   397,   399,     0,     0,   153,     0,     0,     0,   128,
       0,   155,     0,     0,     0,   335,     0,     0,   354,   357,
       0,   355,     0,     0,     0,     0,     0,   157,   156,   356
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -625,  -625,  -625,  -625,    14,   430,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,   207,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -318,
      36,  -428,  -625,  -625,  -625,  -625,  -625,  -625,  -427,  -596,
    -625,  -625,  -625,  -625,    29,  -625,  -261,  -625,  -118,  -624,
    -625,  -625,  -625,  -321,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,    20,  -625,  -625,  -625,   265,   129,  -625,  -565,
    -393,  -114,  -625,  -119,  -625,   -40,  -103,   -56,  -625,  -625,
    -625,   208,  -625,  -625,  -625,  -625,   372,  -625,  -625,   378,
    -625,  -625,   433,  -625,  -341,  -447,  -183,  -625,  -625,  -625,
    -625,  -625,  -146,   -29,   -36,  -280,   691,  -625,  -625,  -625,
     216,  -625,  -625,  -133,  -134,  -625,  -625,  -625,     2,  -625,
     -45,  -117,  -625,  -625,  -625,  -282,  -625,   104,  -625,  -396,
      94,  -625,  -625,   -55,  -221,  -145,  -551,  -625,  -296,   367,
    -625,   579,  -625,   472,  -625,  -625,  -625,  -625,  -625,   271,
    -244,   877,  -264,   -13,   177,     0,   548,    -6,  -262
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,   229,    22,   319,    24,    25,   287,    26,    27,
      28,    29,   326,   251,    30,   257,   329,    31,    32,   236,
     291,   292,   452,   453,   454,   455,   456,   457,   775,   609,
     611,   615,   633,   780,   631,   778,   869,   927,   624,   770,
     968,   990,   640,   641,   642,   871,   872,   645,   646,   647,
      33,   516,   977,   978,    34,    35,    36,    37,   217,    38,
      39,    40,    42,    43,   241,   233,   240,   297,   465,   700,
     701,   656,   795,   796,   792,   320,   243,   244,   245,   883,
     246,   664,   665,   667,   318,   314,   315,   308,   309,   310,
     311,   419,   247,   484,   885,   490,   657,   523,   394,   395,
     713,   586,   838,   722,   396,   593,   397,   398,   399,   400,
     540,   401,   998,   739,   905,   531,   954,   694,   695,   819,
     402,   403,   462,   932,   972,   231,   404,   405,   560,   282,
     414,   606,   761,   759,   754,   755,   406,   407,   259,   260,
     653,   272,   266,   122,   517,   684,   685,   117,   502,   408,
     339,   409,   497,   332,   263,   410,   294,    46,   341
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,   218,   258,   466,   242,   416,   616,   343,   248,   220,
     221,   222,   223,   331,    23,   351,   625,   626,   627,   659,
     600,   724,   788,    44,    45,   745,    47,  1002,   979,   771,
     772,   773,   680,   863,   864,   865,   635,   293,   681,   858,
       1,    41,   866,   635,   249,   675,   295,   234,   965,   412,
     503,     1,   489,   756,   489,   237,     8,   468,   120,   296,
     121,   413,   469,   781,   504,   918,   721,   481,   482,     1,
     290,   285,   655,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,     8,   519,   585,   230,   859,
     505,   496,   603,   334,   604,   300,     8,   393,   411,   506,
     996,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   126,     8,   585,     8,   617,   618,   619,
     323,   620,   621,   622,  -590,   636,   791,   682,   227,   683,
     623,   790,   636,   691,   692,   826,   634,   637,   638,   483,
     558,   696,   966,   967,   299,   127,   698,   507,   508,   509,
     494,  -568,   737,  -590,   738,   895,   559,   702,   -23,   867,
     324,   706,   325,   875,   557,   558,   724,   300,   510,   511,
     856,   857,   228,   791,   555,   556,   693,   896,   817,  1003,
    -568,   559,   557,   558,   111,   528,   119,   530,   557,   558,
     595,   219,   512,   766,   767,   891,   111,   467,   897,   559,
     898,   230,   899,   235,   900,   559,   513,   478,   674,   901,
     232,   277,   997,   248,   264,   648,   714,   265,   902,   557,
     558,   111,   111,   903,   904,   596,   651,   592,   514,   268,
     715,   716,   717,   288,   652,   470,   559,   677,   270,   515,
     471,   557,   558,   629,   824,   271,   825,   273,   630,   321,
     788,   280,   476,   477,   258,   479,   688,   474,   559,   303,
     304,   279,   557,   558,   248,   584,   352,   340,   585,   340,
     238,   239,   248,   248,   248,   248,   914,   281,   806,   559,
     118,   121,   709,   710,   711,   248,   492,   712,    41,   258,
     248,   290,   111,   758,   756,   293,   334,   111,   283,   284,
     249,   298,   417,   111,   111,   415,   673,   753,   249,   249,
     249,   249,   827,   123,   124,   125,   317,   521,   261,   458,
     459,   321,   498,   493,   300,   293,   249,   301,   302,   303,
     304,   305,  -469,   306,   307,   488,   333,   662,   663,   829,
     830,   831,   587,   588,   327,   878,   334,   746,   340,   662,
     663,   839,   335,   522,   524,   525,   526,   527,  -470,   747,
     293,   358,   359,   360,   361,   362,   363,   756,   703,   704,
     364,   365,   336,   534,   707,   708,   342,   799,   539,   541,
     542,   541,   541,   541,   541,   541,   541,   541,   550,   551,
     552,   553,   554,   301,   302,   303,   304,   305,   337,   306,
     307,   111,   648,   882,   791,   293,   393,   345,   590,   347,
     594,   592,   749,   750,   349,   849,   293,   854,   855,   607,
     861,   862,   928,   929,   111,   472,   111,   111,   934,   935,
     936,   293,   807,   605,   119,   577,   578,   579,   580,   581,
     582,   583,   584,   111,   119,   585,   119,   111,   464,   111,
     473,   111,   225,   994,   293,   489,   111,   579,   580,   581,
     582,   583,   584,   887,   888,   585,   111,   612,   613,   944,
     741,   742,   500,   119,   501,   589,     8,   111,   252,   800,
     591,   597,   598,   802,   608,   111,   111,   111,   111,   111,
     610,   614,   623,   628,   632,   111,   649,   650,   111,   340,
     660,   661,   111,   111,   666,   669,   670,   671,   679,   676,
     816,   687,  -472,   111,   686,   559,   585,   689,   340,   693,
     980,   295,    41,   751,   111,   119,   111,   758,   330,   763,
     769,   764,   765,   768,   881,   774,   723,   777,   330,   783,
     330,   776,   648,   648,   785,   907,   889,   784,   267,   779,
     786,   801,   843,   269,   746,   930,   798,   -24,   258,   275,
     276,   847,   791,   845,   842,   851,   852,   463,   860,   853,
     261,   868,   870,   916,   592,   890,   893,   943,   498,   924,
     945,   946,   947,   948,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   594,   111,   585,   543,   544,   545,
     546,   547,   548,   549,   757,   261,   330,    41,   488,   908,
     922,   923,   925,   926,   300,   931,   953,   958,   949,   330,
     962,   760,   933,   950,   963,   970,   959,   971,   964,   976,
     648,   981,   987,   988,   892,   989,   119,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   999,
     747,   585,  1000,  1004,  1006,  1007,  1008,   278,  1011,  1009,
    1010,  1016,   984,   286,  1013,   639,   782,   969,   874,   803,
     804,   805,  1019,  1001,   879,   837,   119,   877,   119,   810,
     599,   723,   705,   322,   480,   475,   668,   910,   835,   807,
     991,   894,   906,   743,   752,   119,   818,   960,   844,   338,
     915,   495,   119,   344,   274,   346,   289,   348,   941,     0,
       0,   836,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,   420,     0,     0,     0,     0,     0,     0,     0,
     330,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,     0,     0,   585,   841,     0,     0,     0,
     876,     0,     0,     0,   248,     0,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
     330,     0,   678,     0,     0,     1,     2,     3,     4,     0,
     518,     0,   520,     0,   119,   498,     0,   592,   992,   330,
     249,     0,     0,     5,     0,     0,   690,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   340,   697,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       8,     0,     0,   119,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   757,     0,     0,     0,     0,
     920,   602,     0,   119,     0,     0,   111,     0,     0,     0,
       0,   111,   330,   119,   919,     0,     0,   486,   487,     0,
       0,     0,     0,     0,   261,     0,     0,     0,   762,     9,
      10,    11,    12,    13,   110,     0,     0,     0,     0,     0,
     940,     0,    14,    15,    16,     0,   226,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,   955,     0,
       0,     0,     0,   258,     0,   909,     0,   330,   757,     0,
      41,   226,   226,     0,   262,     0,     0,     0,   797,     0,
       0,     0,     0,     0,   961,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   330,     0,   585,
       0,     0,     0,     0,     0,     0,     0,   811,     0,     0,
      20,   119,     0,   119,   119,   601,     0,   111,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,   119,     0,
     119,   119,   119,     0,     0,   119,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,   226,     0,     0,
       0,     0,     0,   226,   226,     0,     0,     0,     0,     0,
    1012,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,     0,     0,   585,   119,     0,   119,     0,
       0,     0,     0,     0,     0,     0,   672,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,     0,     0,
     585,   119,     0,     0,     0,   873,     0,   330,   330,     0,
     529,     0,   532,   533,   797,   535,   536,   537,   538,   330,
       0,     0,   884,     0,   886,   886,   886,     0,     0,   330,
       0,     0,     0,     0,     0,     0,   789,     0,     0,   699,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,     0,     0,   119,     0,     0,     0,     0,
     119,   119,   808,   119,     0,     0,     0,   809,     0,     0,
     917,     0,   921,     0,   316,     0,   226,   226,     0,     0,
       0,     0,     0,     0,     0,     0,   119,     0,     0,     0,
       0,   748,     0,   226,     0,   330,     0,   226,     0,   226,
       0,   226,     0,   119,     0,     0,   350,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   226,     0,     0,
       0,     0,     0,     0,     0,   226,   226,   226,   226,   316,
       0,     0,     0,     0,     0,   485,     0,     0,   226,   873,
       0,     0,   226,   226,   330,   974,     0,   975,     0,     0,
       0,   262,   350,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,     0,   226,     0,     0,   261,
     985,     0,     0,     0,     0,     0,     0,   812,   813,   814,
     815,     0,     0,     0,   820,     0,   821,   993,   822,     0,
     823,     0,     0,   718,   828,     0,     0,     0,     0,     0,
       0,   719,   720,     0,   725,   726,   727,   728,   729,   730,
     731,   732,   733,   734,   735,   736,     0,   740,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   421,     0,
       0,     0,     0,   840,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   846,     0,     0,   848,   850,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     423,   424,   425,   426,   427,   428,   429,     0,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,     0,
       0,   441,   658,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   561,     0,   562,     0,     0,     0,     0,
       0,   563,   564,   565,   566,   567,   568,   569,     0,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,     0,     0,   585,   913,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   658,   658,   832,   833,   834,     0,     0,
       0,   658,     0,     0,     0,     0,   658,     0,     0,   658,
       0,     0,     0,     0,     0,     0,     0,   658,     0,     0,
       0,   658,     0,   937,     0,   938,   939,     0,     0,     0,
       0,     0,   942,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   951,   952,     0,     0,     0,     0,     0,
       0,     0,   957,     0,     0,     0,     0,   658,   350,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   982,     0,     0,     0,     0,     0,     0,   986,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   995,     0,   911,   912,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1005,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,     0,
       0,   226,  1017,  1018,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   658,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     956,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   658,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   983,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,   658,     0,
       0,     0,     0,     0,     0,   350,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1015,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   658,     0,
       0,     0,     0,     0,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    48,   140,
       0,   141,   142,   143,   144,   145,   146,    49,   147,   148,
     149,   150,   151,    50,   152,     0,    51,    52,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     0,     0,     0,   112,     0,   643,   644,     0,
       0,     0,     0,     0,    54,     0,   166,   167,   168,   169,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   787,
       0,     0,     0,     0,     0,     0,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,   182,     0,
     183,     0,     0,     0,   184,   185,     0,   186,     0,     0,
       0,   187,     0,   188,   189,   262,   190,   191,    55,   192,
     193,   194,   195,    56,   196,   197,   198,    57,   199,    58,
      59,     0,   200,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,   201,     0,    96,    97,    98,   202,   203,    99,   100,
     101,   102,   103,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,     0,     0,   215,   216,   104,     0,
     105,   106,   107,   108,   109,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,    48,   140,     0,
     141,   142,   143,   144,   145,   146,    49,   147,   148,   149,
     150,   151,    50,   152,     0,    51,    52,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,     0,     0,   112,     0,   643,   644,     0,     0,
       0,     0,     0,    54,     0,   166,   167,   168,   169,   170,
     171,     0,   172,   173,   174,   175,   176,   177,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,   181,     0,
       0,     0,     0,     0,     0,     0,     0,   182,     0,   183,
       0,     0,     0,   184,   185,     0,   186,     0,     0,     0,
     187,     0,   188,   189,     0,   190,   191,    55,   192,   193,
     194,   195,    56,   196,   197,   198,    57,   199,    58,    59,
       0,   200,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
     201,     0,    96,    97,    98,   202,   203,    99,   100,   101,
     102,   103,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,     0,     0,   215,   216,   104,     0,   105,
     106,   107,   108,   109,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    48,   140,     0,   141,
     142,   143,   144,   145,   146,    49,   147,   148,   149,   150,
     151,    50,   152,     0,    51,    52,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,     0,     0,   112,     0,   328,     0,     0,     0,     0,
       0,     0,    54,     0,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,   175,   176,   177,     0,     0,     0,
       0,     0,     0,     0,   178,   179,   180,   181,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,   183,     0,
       0,     0,   184,   185,     0,   186,     0,     0,     0,   187,
       0,   188,   189,     0,   190,   191,    55,   192,   193,   194,
     195,    56,   196,   197,   198,    57,   199,    58,    59,     0,
     200,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,   201,
       0,    96,    97,    98,   202,   203,    99,   100,   101,   102,
     103,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,     0,     0,   215,   216,   104,     0,   105,   106,
     107,   108,   109,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    48,   140,     0,   141,   142,
     143,   144,   145,   146,    49,   147,   148,   149,   150,   151,
      50,   152,     0,    51,    52,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     8,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,   166,   167,   168,   169,   170,   171,     0,
     172,   173,   174,   175,   176,   177,     0,     0,     0,     0,
       0,     0,     0,   178,   179,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,   182,     0,   183,     0,     0,
       0,   184,   185,     0,   186,     0,     0,     0,   187,     0,
     188,   189,     0,   190,   191,    55,   192,   193,   194,   195,
      56,   196,   197,   198,    57,   199,    58,    59,     0,   200,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,   201,     0,
      96,    97,    98,   202,   203,    99,   100,   101,   102,   103,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,     0,     0,   215,   216,   104,     0,   105,   106,   107,
     108,   109,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    48,   140,     0,   141,   142,   143,
     144,   145,   146,    49,   147,   148,   149,   150,   151,    50,
     152,     0,    51,    52,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     0,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,   166,   167,   168,   169,   170,   171,     0,   172,
     173,   174,   175,   176,   177,     0,     0,     0,     0,     0,
       0,     0,   178,   179,   180,   181,     0,     0,     0,     0,
       0,     0,   880,     0,   182,     0,   183,     0,     0,     0,
     184,   185,     0,   186,     0,     0,     0,   187,     0,   188,
     189,     0,   190,   191,    55,   192,   193,   194,   195,    56,
     196,   197,   198,    57,   199,    58,    59,     0,   200,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,   201,     0,    96,
      97,    98,   202,   203,    99,   100,   101,   102,   103,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       0,     0,   215,   216,   104,     0,   105,   106,   107,   108,
     109,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    48,   140,     0,   141,   142,   143,   144,
     145,   146,    49,   147,   148,   149,   150,   151,    50,   152,
       0,    51,    52,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,   166,   167,   168,   169,   170,   171,     0,   172,   173,
     174,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,   178,   179,   180,   181,     0,     0,     0,     0,     0,
       0,   973,     0,   182,     0,   183,     0,     0,     0,   184,
     185,     0,   186,     0,     0,     0,   187,     0,   188,   189,
       0,   190,   191,    55,   192,   193,   194,   195,    56,   196,
     197,   198,    57,   199,    58,    59,     0,   200,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,   201,     0,    96,    97,
      98,   202,   203,    99,   100,   101,   102,   103,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,     0,
       0,   215,   216,   104,     0,   105,   106,   107,   108,   109,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    48,   140,     0,   141,   142,   143,   144,   145,
     146,    49,   147,   148,   149,   150,   151,    50,   152,     0,
      51,    52,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
     166,   167,   168,   169,   170,   171,     0,   172,   173,   174,
     175,   176,   177,     0,     0,     0,     0,     0,     0,     0,
     178,   179,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,   182,     0,   183,     0,     0,     0,   184,   185,
       0,   186,     0,     0,     0,   187,     0,   188,   189,     0,
     190,   191,    55,   192,   193,   194,   195,    56,   196,   197,
     198,    57,   199,    58,    59,     0,   200,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,   201,     0,    96,    97,    98,
     202,   203,    99,   100,   101,   102,   103,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,     0,     0,
     215,   216,   104,     0,   105,   106,   107,   108,   109,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,    48,   140,     0,   141,   142,   143,   144,   145,   146,
      49,   147,   148,   149,   150,   151,    50,   152,     0,    51,
      52,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     0,     0,     0,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,   166,
     167,   168,   169,   170,   171,     0,   172,   173,   174,   175,
     176,   177,     0,     0,     0,     0,     0,     0,     0,   178,
     179,   180,   181,     0,     0,     0,     0,     0,     0,     0,
       0,   182,     0,   183,     0,     0,     0,   184,   185,     0,
     186,     0,     0,     0,   187,     0,   188,   189,     0,   190,
     191,    55,   192,   193,   194,   195,    56,   196,   197,   198,
      57,   199,    58,    59,     0,   200,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,   201,     0,    96,    97,    98,   202,
     203,    99,   100,   101,   102,   103,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,     0,     0,   215,
     216,   104,     0,   105,   106,   107,   108,   109,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      48,   140,     0,   141,   142,   143,   144,   145,   146,    49,
     147,   148,   149,   150,   151,    50,   152,     0,    51,    52,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,     0,     0,     0,   253,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,   166,   167,
     168,   169,   170,   171,     0,   172,   173,   174,   175,   176,
     177,     0,     0,     0,     0,     0,     0,     0,   178,   179,
     180,   181,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     0,   183,     0,     0,     0,   184,   185,     0,   186,
       0,     0,     0,   187,     0,   188,   189,     0,   190,   191,
      55,   192,   193,   194,   195,    56,   196,   197,   198,    57,
     199,    58,    59,     0,   200,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,   201,     0,    96,    97,    98,   202,   203,
      99,   100,   101,   102,   103,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,     0,     0,   215,   216,
     104,     0,   105,   106,   107,   108,   109,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,    48,
     140,     0,   141,   142,   143,   144,   145,   146,    49,   147,
     148,   149,   150,   151,    50,   152,     0,    51,    52,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,     0,     0,   112,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,   166,   167,   168,
     169,   170,   171,     0,   172,   173,   174,   175,   176,   177,
       0,     0,     0,     0,     0,     0,     0,   178,   179,   180,
     181,     0,     0,     0,     0,     0,     0,     0,     0,   182,
       0,   183,     0,     0,     0,   184,   185,     0,   186,     0,
       0,     0,   187,     0,   188,   189,     0,   190,   191,    55,
     192,   193,   194,   195,    56,   196,   197,   198,    57,   199,
      58,    59,     0,   200,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,   201,     0,    96,    97,    98,   202,   203,    99,
     100,   101,   102,   103,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,     1,     0,   215,   216,   104,
       0,   105,   106,   107,   108,   109,    48,     0,     0,     0,
       0,   353,     0,     0,     0,    49,     0,   354,     0,     0,
     355,    50,     0,     0,    51,    52,     0,     0,     0,     0,
     356,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,   253,   358,   359,   360,   361,   362,   363,
       0,     0,    54,   364,   365,   366,   367,     0,     0,   368,
     369,     0,   370,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   371,   372,     0,     0,     0,     0,   373,     0,
     374,     0,     0,   375,   376,   377,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,   378,
       0,    56,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     1,   392,   104,     0,   105,   106,
     107,   108,   109,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
      50,     0,     0,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
      56,     0,     0,     0,    57,     0,    58,    59,     0,     0,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
      96,    97,    98,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,   104,     0,   105,   106,   107,
     108,   109,    49,     0,     0,     0,     0,     0,    50,     0,
       0,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,    56,     0,
       0,     0,    57,     0,    58,    59,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   250,     0,     0,    96,    97,
      98,     0,    48,    99,   100,   101,   102,   103,     0,     0,
       0,    49,     0,     0,     0,     0,     0,    50,     0,     0,
      51,    52,     0,   104,     0,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,    56,     0,     0,
       0,    57,     0,    58,    59,     0,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,    96,    97,    98,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,     0,   105,   106,   107,   108,   109,    48,
       0,     0,   744,     0,   353,     0,     0,     0,    49,     0,
     354,     0,     0,   355,    50,     0,     0,    51,    52,     0,
       0,     0,     0,   356,   357,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,   253,   358,   359,   360,
     361,   362,   363,     0,     0,    54,   364,   365,   366,   367,
       0,     0,   368,   369,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   371,   372,   654,     0,     0,
       0,   373,     0,   374,     0,     0,   375,   376,   377,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,   378,     0,    56,     0,     0,     0,    57,     0,
      58,    59,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,    96,    97,    98,     0,     0,    99,
     100,   101,   102,   103,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,   392,   104,
       0,   105,   106,   107,   108,   109,    48,     0,     0,     0,
       0,   353,     0,     0,     0,    49,     0,   354,     0,     0,
     355,    50,     0,     0,    51,    52,     0,     0,     0,     0,
     356,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,   253,   358,   359,   360,   361,   362,   363,
       0,     0,    54,   364,   365,   366,   367,     0,     0,   368,
     369,     0,   370,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   371,   372,   654,     0,     0,     0,   373,     0,
     374,     0,     0,   375,   376,   377,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,   378,
       0,    56,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,   392,   104,     0,   105,   106,
     107,   108,   109,    48,     0,     0,     0,     0,   353,     0,
       0,     0,    49,     0,   354,     0,     0,   355,    50,     0,
       0,    51,    52,     0,     0,     0,     0,   356,   357,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,   293,
     253,   358,   359,   360,   361,   362,   363,     0,     0,    54,
     364,   365,   366,   367,     0,     0,   368,   369,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   371,
     372,     0,     0,     0,     0,   373,     0,   374,     0,     0,
     375,   376,   377,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,   378,     0,    56,     0,
       0,     0,    57,     0,    58,    59,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,    96,    97,
      98,     0,     0,    99,   100,   101,   102,   103,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,   392,   104,     0,   105,   106,   107,   108,   109,
      48,     0,     0,     0,     0,   353,     0,     0,     0,    49,
       0,   354,     0,     0,   355,    50,     0,     0,    51,    52,
       0,     0,     0,     0,   356,   357,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,   253,   358,   359,
     360,   361,   362,   363,     0,     0,    54,   364,   365,   366,
     367,     0,     0,   368,   369,     0,   370,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   371,   372,     0,     0,
       0,     0,   373,     0,   374,     0,     0,   375,   376,   377,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,   378,     0,    56,     0,     0,     0,    57,
       0,    58,    59,     0,     0,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,    96,    97,    98,     0,     0,
      99,   100,   101,   102,   103,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,    48,   392,
     104,     0,   105,   106,   107,   108,   109,    49,     0,     0,
       0,     0,   355,    50,     0,     0,    51,    52,     0,     0,
       0,     0,   356,   357,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     0,   253,   358,   359,   360,   361,
     362,   363,     0,     0,    54,   364,   365,   366,   367,     0,
       0,     0,   369,     0,   370,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   371,   372,     0,     0,     0,     0,
     373,     0,   374,     0,     0,   375,   376,   377,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,   378,     0,    56,     0,     0,     0,    57,     0,    58,
      59,     0,  1014,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    96,    97,    98,     0,     0,    99,   100,
     101,   102,   103,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,    48,   392,   104,     0,
     105,   106,   107,   108,   109,    49,     0,     0,     0,     0,
     355,    50,     0,     0,    51,    52,     0,     0,     0,     0,
     356,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,   253,   358,   359,   360,   361,   362,   363,
       0,     0,    54,   364,   365,   366,   367,     0,     0,     0,
     369,     0,   370,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   371,   372,     0,     0,     0,     0,   373,     0,
     374,     0,     0,   375,   376,   377,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,   378,
       0,    56,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,    48,   392,   104,     0,   105,   106,
     107,   108,   109,    49,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,     0,     0,
     585,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,    56,
       0,     0,     0,    57,     0,    58,    59,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,    96,
      97,    98,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
     793,     0,     0,     0,   104,    49,   105,   106,   107,   108,
     109,    50,     0,     0,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,   794,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,   557,   558,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   559,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,    56,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    96,    97,    98,    48,     0,    99,   100,   101,   102,
     103,     0,     0,    49,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,     0,   104,     0,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,   115,     0,     0,     0,   116,    56,
       0,     0,     0,    57,     0,    58,    59,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,    96,
      97,    98,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
     312,     0,     0,     0,   104,    49,   105,   106,   107,   108,
     109,    50,     0,     0,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,   313,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,    56,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    96,    97,    98,    48,     0,    99,   100,   101,   102,
     103,     0,     0,    49,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,     0,   104,     0,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,   460,     0,     0,   461,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,    56,
       0,     0,     0,    57,     0,    58,    59,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,    96,
      97,    98,    48,     0,    99,   100,   101,   102,   103,     0,
       0,    49,     0,     0,     0,     0,     0,    50,     0,     0,
      51,    52,     0,     0,   104,     0,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,     0,    55,     0,     0,     0,     0,    56,     0,     0,
       0,    57,     0,    58,    59,     0,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,    96,    97,    98,
      48,     0,    99,   100,   101,   102,   103,     0,     0,    49,
       0,     0,     0,     0,     0,    50,     0,     0,    51,    52,
       0,     0,   104,     0,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     8,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,     0,     0,    56,     0,     0,     0,    57,
       0,    58,    59,     0,     0,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,    96,    97,    98,    48,     0,
      99,   100,   101,   102,   103,     0,   418,    49,     0,     0,
       0,     0,     0,    50,     0,     0,    51,    52,     0,     0,
     104,     0,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,    56,     0,     0,     0,    57,     0,    58,
      59,     0,     0,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    96,    97,    98,    48,     0,    99,   100,
     101,   102,   103,     0,     0,    49,     0,     0,     0,     0,
       0,    50,     0,     0,    51,    52,     0,     0,   104,     0,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,   313,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,    56,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    96,    97,    98,    48,     0,    99,   100,   101,   102,
     103,     0,     0,    49,     0,     0,     0,     0,     0,    50,
       0,     0,    51,    52,     0,     0,   104,     0,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   794,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,    56,
       0,     0,     0,    57,     0,    58,    59,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,    96,
      97,    98,    48,     0,    99,   100,   101,   102,   103,     0,
       0,    49,     0,     0,     0,     0,     0,    50,     0,     0,
      51,    52,     0,     0,   104,     0,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,    56,     0,     0,
       0,    57,     0,    58,    59,     0,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,    96,    97,    98,
      48,     0,    99,   100,   101,   102,   103,     0,     0,    49,
       0,     0,     0,     0,     0,    50,     0,     0,    51,    52,
       0,     0,   104,     0,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,   253,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,     0,     0,    56,     0,     0,     0,    57,
       0,    58,    59,     0,     0,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   254,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,    96,    97,    98,    48,     0,
      99,   100,   101,   255,   256,     0,     0,    49,     0,     0,
       0,     0,     0,    50,     0,     0,    51,    52,     0,     0,
     104,     0,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,    56,     0,     0,     0,    57,     0,    58,
      59,     0,     0,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    96,    97,    98,    48,     0,    99,   100,
     101,   102,   103,     0,     0,    49,     0,     0,     0,     0,
       0,    50,     0,     0,    51,    52,     0,     0,   104,     0,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,    56,     0,     0,     0,    57,     0,    58,    59,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,   105,   106,
     107,   108,   109
};

static const yytype_int16 yycheck[] =
{
       0,    14,    47,   299,    44,   287,   434,   269,    44,    15,
      16,    17,    18,   257,     0,   279,   443,   444,   445,   466,
     416,   572,   646,     3,     4,   590,     6,    45,    53,   625,
     626,   627,    20,    55,    56,    57,    26,    52,    26,    53,
       5,    41,    64,    26,    44,   492,    19,    27,    26,    17,
      13,     5,    10,   604,    10,    41,    50,    38,   116,    32,
     118,    29,    43,    53,    27,    30,    60,    46,    47,     5,
      53,     5,   465,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    50,   348,   102,    13,   103,
      53,   335,    28,    51,    30,    51,    50,   280,   281,    62,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   114,    50,   102,    50,   435,   436,   437,
       9,   439,   440,   441,    77,   115,    51,   115,     0,   117,
     155,     9,   115,   526,   527,    20,   454,   120,   121,   118,
      68,   534,   120,   121,    28,   114,   539,   110,   111,   112,
     333,    77,    53,   106,    55,   103,    84,   550,     4,   181,
      49,   554,    51,   787,    67,    68,   717,    51,   131,   132,
     766,   767,   203,    51,    22,    23,    73,   125,    75,   197,
     106,    84,    67,    68,     7,   368,     9,   370,    67,    68,
      16,    14,   155,   620,   621,    74,    19,   300,   146,    84,
     148,    13,   150,    50,   152,    84,   169,   310,   490,   157,
       4,   217,   199,   249,   190,   459,    71,   119,   166,    67,
      68,    44,    45,   171,   172,    51,     9,   410,   191,   115,
      85,    86,    87,   233,    17,    38,    84,   499,   114,   202,
      43,    67,    68,    64,    49,   119,    51,    53,    69,   249,
     874,    14,   308,   309,   299,   311,   518,    38,    84,    40,
      41,   106,    67,    68,   300,    99,   279,   267,   102,   269,
      36,    37,   308,   309,   310,   311,   841,    15,   674,    84,
       9,   118,    64,    65,    66,   321,   326,    69,   288,   334,
     326,    53,   115,    48,   845,    52,    51,   120,    18,    19,
     300,    61,   288,   126,   127,   285,   489,   603,   308,   309,
     310,   311,   705,   114,   115,   116,    20,   353,    47,    51,
      52,   321,   335,   329,    51,    52,   326,    38,    39,    40,
      41,    42,   106,    44,    45,   321,    77,    48,    49,    64,
      65,    66,   107,   108,    28,   792,    51,   591,   348,    48,
      49,   744,   106,   353,   354,   355,   356,   357,   106,    51,
      52,    54,    55,    56,    57,    58,    59,   918,   551,   552,
      63,    64,   116,   373,   557,   558,    53,   659,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,    38,    39,    40,    41,    42,    69,    44,
      45,   224,   646,   799,    51,    52,   589,    21,   408,    48,
     410,   594,   595,   596,   117,    51,    52,    51,    52,   419,
      51,    52,    51,    52,   247,    38,   249,   250,    51,    52,
      51,    52,   676,   419,   257,    92,    93,    94,    95,    96,
      97,    98,    99,   266,   267,   102,   269,   270,    39,   272,
      38,   274,    19,    51,    52,    10,   279,    94,    95,    96,
      97,    98,    99,   804,   805,   102,   289,   431,   432,   897,
     587,   588,    21,   296,    49,    51,    50,   300,    45,   662,
     106,     7,    87,   666,    50,   308,   309,   310,   311,   312,
      50,    50,   155,    50,   172,   318,    30,    30,   321,   499,
      38,    38,   325,   326,    48,   115,   115,   115,    48,   106,
     693,   517,   106,   336,   131,    84,   102,    53,   518,    73,
     947,    19,   522,    34,   347,   348,   349,    48,   257,    56,
     102,    56,    56,    28,   798,    55,   572,    27,   267,    26,
     269,    64,   786,   787,    53,   827,   808,    50,   115,   173,
      51,    50,    35,   120,   798,   873,   106,     4,   603,   126,
     127,    25,    51,    51,   747,   106,    52,   296,    53,    51,
     299,    48,    53,    26,   757,    24,    76,   895,   591,    55,
     898,   899,   900,   901,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   594,   418,   102,   381,   382,   383,
     384,   385,   386,   387,   604,   334,   335,   607,   594,   196,
      56,    56,     7,   169,    51,    11,   194,     7,   140,   348,
      52,   607,   106,   140,    52,    14,   106,    12,   181,   131,
     874,    55,    26,    26,   817,    62,   459,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    55,
      51,   102,    30,   200,   133,   198,    35,   224,    35,   201,
     134,   200,   958,   233,   199,   458,   637,   928,   786,   669,
     670,   671,   201,   994,   793,   126,   499,   791,   501,   685,
     415,   717,   553,   250,   312,   307,   478,   833,   717,   933,
     970,   824,   826,   589,   600,   518,   694,   918,   753,   266,
     845,   334,   525,   270,   125,   272,   234,   274,   891,    -1,
      -1,    68,    -1,    -1,    -1,   538,    -1,    -1,    -1,    -1,
      -1,    -1,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     459,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   746,    -1,    -1,    -1,
     790,    -1,    -1,    -1,   790,    -1,    -1,    -1,   325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   336,
     499,    -1,   501,    -1,    -1,     5,     6,     7,     8,    -1,
     347,    -1,   349,    -1,   607,   798,    -1,   970,   971,   518,
     790,    -1,    -1,    23,    -1,    -1,   525,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   808,   538,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    -1,    -1,   646,    -1,    -1,    -1,    -1,    -1,    -1,
     653,    -1,    -1,    -1,   657,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   845,    -1,    -1,    -1,    -1,
     850,   418,    -1,   676,    -1,    -1,   679,    -1,    -1,    -1,
      -1,   684,   591,   686,   850,    -1,    -1,   319,   320,    -1,
      -1,    -1,    -1,    -1,   603,    -1,    -1,    -1,   607,   109,
     110,   111,   112,   113,     7,    -1,    -1,    -1,    -1,    -1,
     890,    -1,   122,   123,   124,    -1,    19,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   908,    -1,
      -1,    -1,    -1,   958,    -1,    68,    -1,   646,   918,    -1,
     920,    44,    45,    -1,    47,    -1,    -1,    -1,   657,    -1,
      -1,    -1,    -1,    -1,   920,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   676,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   686,    -1,    -1,
     190,   784,    -1,   786,   787,   417,    -1,   790,    -1,    -1,
     793,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   801,    -1,
     803,   804,   805,    -1,    -1,   808,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
    1010,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   849,    -1,   851,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   488,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
     102,   874,    -1,    -1,    -1,   784,    -1,   786,   787,    -1,
     369,    -1,   371,   372,   793,   374,   375,   376,   377,   798,
      -1,    -1,   801,    -1,   803,   804,   805,    -1,    -1,   808,
      -1,    -1,    -1,    -1,    -1,    -1,   653,    -1,    -1,   541,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,   928,    -1,    -1,    -1,    -1,
     933,   934,   679,   936,    -1,    -1,    -1,   684,    -1,    -1,
     849,    -1,   851,    -1,   247,    -1,   249,   250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   959,    -1,    -1,    -1,
      -1,   593,    -1,   266,    -1,   874,    -1,   270,    -1,   272,
      -1,   274,    -1,   976,    -1,    -1,   279,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   299,   300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   308,   309,   310,   311,   312,
      -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,   321,   928,
      -1,    -1,   325,   326,   933,   934,    -1,   936,    -1,    -1,
      -1,   334,   335,   336,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   347,    -1,   349,    -1,    -1,   958,
     959,    -1,    -1,    -1,    -1,    -1,    -1,   689,   690,   691,
     692,    -1,    -1,    -1,   696,    -1,   698,   976,   700,    -1,
     702,    -1,    -1,   562,   706,    -1,    -1,    -1,    -1,    -1,
      -1,   570,   571,    -1,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,    -1,   586,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,   745,    -1,   418,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   757,    -1,    -1,   760,   761,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,   138,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,   156,   465,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    69,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,   102,   839,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   526,   527,   714,   715,   716,    -1,    -1,
      -1,   534,    -1,    -1,    -1,    -1,   539,    -1,    -1,   542,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,
      -1,   554,    -1,   885,    -1,   887,   888,    -1,    -1,    -1,
      -1,    -1,   894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   905,   906,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   914,    -1,    -1,    -1,    -1,   590,   591,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   954,    -1,    -1,    -1,    -1,    -1,    -1,   961,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   977,    -1,   836,   837,    -1,
     653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   998,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,
      -1,   684,  1014,  1015,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   705,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     909,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   744,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   955,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   790,   791,    -1,
      -1,    -1,    -1,    -1,    -1,   798,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1012,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   841,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      98,    -1,    -1,    -1,   102,   103,    -1,   105,    -1,    -1,
      -1,   109,    -1,   111,   112,   958,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,    -1,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,   194,   195,   196,    -1,
     198,   199,   200,   201,   202,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,   102,   103,    -1,   105,    -1,    -1,    -1,
     109,    -1,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,    -1,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,   194,   195,   196,    -1,   198,
     199,   200,   201,   202,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,
      -1,    -1,   102,   103,    -1,   105,    -1,    -1,    -1,   109,
      -1,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
      -1,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,   194,   195,   196,    -1,   198,   199,
     200,   201,   202,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,    -1,
      -1,   102,   103,    -1,   105,    -1,    -1,    -1,   109,    -1,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,   169,    -1,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,   194,   195,   196,    -1,   198,   199,   200,
     201,   202,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    96,    -1,    98,    -1,    -1,    -1,
     102,   103,    -1,   105,    -1,    -1,    -1,   109,    -1,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,    -1,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,   194,   195,   196,    -1,   198,   199,   200,   201,
     202,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    96,    -1,    98,    -1,    -1,    -1,   102,
     103,    -1,   105,    -1,    -1,    -1,   109,    -1,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,    -1,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,   194,   195,   196,    -1,   198,   199,   200,   201,   202,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,    -1,    -1,    -1,   102,   103,
      -1,   105,    -1,    -1,    -1,   109,    -1,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,    -1,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
     194,   195,   196,    -1,   198,   199,   200,   201,   202,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    98,    -1,    -1,    -1,   102,   103,    -1,
     105,    -1,    -1,    -1,   109,    -1,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,   169,    -1,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   194,
     195,   196,    -1,   198,   199,   200,   201,   202,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,   102,   103,    -1,   105,
      -1,    -1,    -1,   109,    -1,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,    -1,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,   194,   195,
     196,    -1,   198,   199,   200,   201,   202,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,    -1,    -1,    -1,   102,   103,    -1,   105,    -1,
      -1,    -1,   109,    -1,   111,   112,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,    -1,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     5,    -1,   194,   195,   196,
      -1,   198,   199,   200,   201,   202,    16,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,    69,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,
     100,    -1,    -1,   103,   104,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,
      -1,   121,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,   171,   172,   173,    -1,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     5,   195,   196,    -1,   198,   199,
     200,   201,   202,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,    -1,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,   176,   177,   178,   179,   180,
      -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    -1,   196,    -1,   198,   199,   200,
     201,   202,    25,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,    -1,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     9,    -1,    -1,   171,   172,
     173,    -1,    16,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,   196,    -1,   198,   199,   200,   201,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,    -1,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,   171,   172,   173,
      -1,    -1,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,    16,
      -1,    -1,    19,    -1,    21,    -1,    -1,    -1,    25,    -1,
      27,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    62,    63,    64,    65,    66,
      -1,    -1,    69,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,
      -1,    98,    -1,   100,    -1,    -1,   103,   104,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,   119,    -1,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,    -1,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,   195,   196,
      -1,   198,   199,   200,   201,   202,    16,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,    69,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,    -1,
     100,    -1,    -1,   103,   104,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,
      -1,   121,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,   171,   172,   173,    -1,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,   195,   196,    -1,   198,   199,
     200,   201,   202,    16,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    -1,    27,    -1,    -1,    30,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    62,
      63,    64,    65,    66,    -1,    -1,    69,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,
     103,   104,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,   119,    -1,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,    -1,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,   195,   196,    -1,   198,   199,   200,   201,   202,
      16,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    30,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    -1,    -1,    62,    63,    64,    65,
      66,    -1,    -1,    69,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    -1,    98,    -1,   100,    -1,    -1,   103,   104,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,   119,    -1,   121,    -1,    -1,    -1,   125,
      -1,   127,   128,    -1,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    16,   195,
     196,    -1,   198,   199,   200,   201,   202,    25,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    -1,
      98,    -1,   100,    -1,    -1,   103,   104,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,   119,    -1,   121,    -1,    -1,    -1,   125,    -1,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,   171,   172,   173,    -1,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    16,   195,   196,    -1,
     198,   199,   200,   201,   202,    25,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,
     100,    -1,    -1,   103,   104,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,
      -1,   121,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,   171,   172,   173,    -1,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    16,   195,   196,    -1,   198,   199,
     200,   201,   202,    25,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,    -1,    -1,   196,    25,   198,   199,   200,   201,
     202,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,   171,   172,   173,    16,    -1,   176,   177,   178,   179,
     180,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,   116,    -1,    -1,    -1,   120,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,    -1,    -1,   196,    25,   198,   199,   200,   201,
     202,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,   171,   172,   173,    16,    -1,   176,   177,   178,   179,
     180,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,   171,
     172,   173,    16,    -1,   176,   177,   178,   179,   180,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,   196,    -1,   198,   199,   200,   201,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,    -1,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,   171,   172,   173,
      16,    -1,   176,   177,   178,   179,   180,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,   125,
      -1,   127,   128,    -1,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,   171,   172,   173,    16,    -1,
     176,   177,   178,   179,   180,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
     196,    -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,   125,    -1,   127,
     128,    -1,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,   171,   172,   173,    16,    -1,   176,   177,
     178,   179,   180,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,   171,   172,   173,    16,    -1,   176,   177,   178,   179,
     180,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,   125,    -1,   127,   128,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,   171,
     172,   173,    16,    -1,   176,   177,   178,   179,   180,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,   196,    -1,   198,   199,   200,   201,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,   125,    -1,   127,   128,    -1,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,   171,   172,   173,
      16,    -1,   176,   177,   178,   179,   180,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,   125,
      -1,   127,   128,    -1,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,   171,   172,   173,    16,    -1,
     176,   177,   178,   179,   180,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
     196,    -1,   198,   199,   200,   201,   202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,   125,    -1,   127,
     128,    -1,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,   171,   172,   173,    16,    -1,   176,   177,
     178,   179,   180,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,   171,   172,   173,    -1,    -1,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     5,     6,     7,     8,    23,    28,    46,    50,   109,
     110,   111,   112,   113,   122,   123,   124,   127,   128,   129,
     190,   205,   207,   208,   209,   210,   212,   213,   214,   215,
     218,   221,   222,   254,   258,   259,   260,   261,   263,   264,
     265,   359,   266,   267,   266,   266,   361,   266,    16,    25,
      31,    34,    35,    53,    62,   116,   121,   125,   127,   128,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   171,   172,   173,   176,
     177,   178,   179,   180,   196,   198,   199,   200,   201,   202,
     355,   358,    53,    67,   114,   116,   120,   351,   353,   358,
     116,   118,   347,   114,   115,   116,   114,   114,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      17,    19,    20,    21,    22,    23,    24,    26,    27,    28,
      29,    30,    32,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    53,    64,    65,    66,    67,
      68,    69,    71,    72,    73,    74,    75,    76,    84,    85,
      86,    87,    96,    98,   102,   103,   105,   109,   111,   112,
     114,   115,   117,   118,   119,   120,   122,   123,   124,   126,
     130,   169,   174,   175,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   194,   195,   262,   357,   358,
     361,   361,   361,   361,   114,   296,   355,     0,   203,   206,
      13,   329,     4,   269,   266,    50,   223,   208,    36,    37,
     270,   268,   279,   280,   281,   282,   284,   296,   308,   359,
       9,   217,   296,    53,   155,   179,   180,   219,   324,   342,
     343,   353,   355,   358,   190,   119,   346,   296,   115,   296,
     114,   119,   345,    53,   345,   296,   296,   361,   296,   106,
      14,    15,   333,    18,    19,     5,   209,   211,   359,   347,
      53,   224,   225,    52,   360,    19,    32,   271,    61,    28,
      51,    38,    39,    40,    41,    42,    44,    45,   291,   292,
     293,   294,    20,    55,   289,   290,   355,    20,   288,   208,
     279,   359,   296,     9,    49,    51,   216,    28,    55,   220,
     353,   354,   357,    77,    51,   106,   116,    69,   296,   354,
     359,   362,    53,   362,   296,    21,   296,    48,   296,   117,
     355,   356,   357,    21,    27,    30,    40,    41,    54,    55,
      56,    57,    58,    59,    63,    64,    65,    66,    69,    70,
      72,    92,    93,    98,   100,   103,   104,   105,   119,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   195,   300,   302,   303,   308,   310,   311,   312,
     313,   315,   324,   325,   330,   331,   340,   341,   353,   355,
     359,   300,    17,    29,   334,   266,   329,   208,    24,   295,
     296,   103,   125,   135,   136,   137,   138,   139,   140,   141,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   156,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   226,   227,   228,   229,   230,   231,    51,    52,
      56,    59,   326,   353,    39,   272,   342,   280,    38,    43,
      38,    43,    38,    38,    38,   293,   281,   281,   280,   281,
     290,    46,    47,   118,   297,   355,   360,   360,   208,    10,
     299,   296,   279,   361,   300,   343,   354,   356,   357,   296,
      21,    49,   352,    13,    27,    53,    62,   110,   111,   112,
     131,   132,   155,   169,   191,   202,   255,   348,   296,   362,
     296,   308,   359,   301,   359,   359,   359,   359,   300,   310,
     300,   319,   310,   310,   359,   310,   310,   310,   310,   359,
     314,   359,   359,   314,   314,   314,   314,   314,   314,   314,
     359,   359,   359,   359,   359,    22,    23,    67,    68,    84,
     332,    69,    71,    77,    78,    79,    80,    81,    82,    83,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   102,   305,   107,   108,    51,
     359,   106,   300,   309,   359,    16,    51,     7,    87,   270,
     333,   360,   296,    28,    30,   208,   335,   359,    50,   233,
      50,   234,   234,   234,    50,   235,   235,   233,   233,   233,
     233,   233,   233,   155,   242,   242,   242,   242,    50,    64,
      69,   238,   172,   236,   233,    26,   115,   120,   121,   225,
     246,   247,   248,    55,    56,   251,   252,   253,   354,    30,
      30,     9,    17,   344,    94,   274,   275,   300,   355,   299,
      38,    38,    48,    49,   285,   286,    48,   287,   285,   115,
     115,   115,   360,   300,   329,   299,   106,   362,   353,    48,
      20,    26,   115,   117,   349,   350,   131,   361,   362,    53,
     353,   274,   274,    73,   321,   322,   274,   353,   274,   360,
     273,   274,   274,   300,   300,   271,   274,   300,   300,    64,
      65,    66,    69,   304,    71,    85,    86,    87,   310,   310,
     310,    60,   307,   308,   340,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,    53,    55,   317,
     310,   325,   325,   331,    19,   273,   354,    51,   360,   300,
     300,    34,   334,   342,   338,   339,   340,   359,    48,   337,
     208,   336,   353,    56,    56,    56,   242,   242,    28,   102,
     243,   243,   243,   243,    55,   232,    64,    27,   239,   173,
     237,    53,   248,    26,    50,    53,    51,    77,   253,   296,
       9,    51,   278,    20,    55,   276,   277,   353,   106,   329,
     300,    50,   300,   359,   359,   359,   333,   354,   296,   296,
     361,   353,   360,   360,   360,   360,   300,    75,   322,   323,
     360,   360,   360,   360,    49,    51,    20,   274,   360,    64,
      65,    66,   310,   310,   310,   307,    68,   126,   306,   274,
     360,   359,   300,    35,   337,    51,   360,    25,   360,    51,
     360,   106,    52,    51,    51,    52,   243,   243,    53,   103,
      53,    51,    52,    55,    56,    57,    64,   181,    48,   240,
      53,   249,   250,   353,   252,   253,   279,   275,   299,   277,
      94,   356,   333,   283,   353,   298,   353,   298,   298,   362,
      24,    74,   300,    76,   317,   103,   125,   146,   148,   150,
     152,   157,   166,   171,   172,   318,   318,   329,   196,    68,
     306,   310,   310,   360,   273,   339,    26,   353,    30,   208,
     359,   353,    56,    56,    55,     7,   169,   241,    51,    52,
     233,    11,   327,   106,    51,    52,    51,   360,   360,   360,
     359,   300,   360,   233,   235,   233,   233,   233,   233,   140,
     140,   360,   360,   194,   320,   359,   310,   360,     7,   106,
     338,   208,    52,    52,   181,    26,   120,   121,   244,   250,
      14,    12,   328,    94,   353,   353,   131,   256,   257,    53,
     242,    55,   360,   310,   342,   353,   360,    26,    26,    62,
     245,   309,   300,   353,    51,   360,    87,   199,   316,    55,
      30,   257,    45,   197,   200,   360,   133,   198,    35,   201,
     134,    35,   359,   199,   130,   310,   200,   360,   360,   201
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   204,   205,   206,   206,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   208,
     208,   208,   209,   210,   210,   211,   211,   212,   212,   213,
     213,   214,   215,   215,   216,   216,   217,   217,   218,   218,
     219,   219,   219,   220,   220,   221,   221,   221,   221,   222,
     223,   224,   224,   224,   225,   226,   226,   226,   227,   227,
     228,   228,   228,   228,   228,   228,   228,   229,   229,   229,
     229,   229,   230,   230,   230,   230,   230,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   232,   232,   233,   233,   234,   234,   235,   235,   235,
     236,   236,   237,   237,   238,   238,   238,   239,   239,   239,
     239,   239,   239,   240,   240,   241,   241,   242,   242,   242,
     243,   243,   244,   244,   244,   244,   244,   245,   245,   246,
     247,   247,   247,   247,   248,   248,   249,   249,   250,   251,
     251,   251,   252,   252,   252,   253,   253,   253,   254,   254,
     254,   254,   254,   255,   256,   256,   257,   257,   258,   259,
     259,   259,   260,   260,   261,   262,   262,   262,   263,   264,
     264,   265,   265,   265,   265,   265,   267,   266,   268,   268,
     269,   269,   269,   270,   270,   270,   271,   271,   272,   272,
     273,   273,   274,   274,   275,   275,   275,   275,   276,   276,
     276,   277,   277,   278,   278,   279,   279,   280,   280,   281,
     281,   281,   282,   283,   283,   284,   284,   284,   284,   285,
     285,   286,   286,   287,   287,   288,   288,   289,   289,   289,
     290,   290,   291,   291,   291,   292,   293,   293,   293,   293,
     294,   294,   295,   295,   296,   296,   297,   297,   297,   297,
     298,   298,   299,   299,   300,   300,   300,   300,   300,   300,
     300,   301,   301,   302,   302,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   304,   304,   304,   304,   304,
     304,   305,   305,   305,   305,   305,   305,   305,   306,   306,
     307,   307,   307,   308,   309,   309,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   311,   311,   311,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   313,
     313,   313,   313,   313,   313,   313,   313,   314,   314,   315,
     315,   315,   315,   316,   316,   316,   316,   316,   317,   317,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   319,   319,   320,   320,   321,   321,   322,
     323,   323,   324,   324,   324,   325,   325,   325,   325,   325,
     325,   325,   325,   326,   326,   326,   327,   327,   328,   328,
     329,   329,   330,   330,   331,   332,   332,   332,   333,   333,
     333,   333,   334,   334,   334,   335,   335,   335,   335,   335,
     335,   336,   336,   336,   336,   337,   337,   338,   338,   339,
     339,   340,   341,   342,   342,   343,   344,   344,   345,   345,
     346,   346,   347,   347,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   349,   349,   349,   350,   350,
     351,   351,   351,   352,   352,   353,   353,   354,   354,   355,
     355,   356,   356,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   359,   360,   361,   362,   362,   362
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       6,     7,    10,     1,     3,     1,     3,     6,     7,     1,
       1,     8,     7,     6,     1,     1,     1,     3,     5,     3,
       1,     2,     1,     1,     1,     2,     8,     4,     6,     4,
       4,     1,     3,     3,     8,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     1,     4,     4,     2,
       2,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       4,     1,     3,     0,     3,     0,     5,     0,     3,     5,
       0,     1,     0,     1,     0,     1,     2,     0,     2,     2,
       2,     2,     2,     0,     3,     0,     1,     0,     3,     3,
       0,     2,     0,     2,     1,     2,     1,     0,     2,     4,
       2,     3,     2,     2,     1,     1,     1,     3,     2,     0,
       1,     3,     1,     2,     3,     1,     1,     1,     6,     7,
       7,     4,     5,     7,     1,     3,     8,     8,     5,     4,
       6,     5,     3,     2,     3,     1,     1,     1,     3,     2,
       1,     2,     2,     2,     2,     2,     0,     2,     0,     2,
       1,     2,     2,     0,     1,     1,     0,     1,     0,     1,
       0,     1,     1,     3,     1,     2,     3,     5,     0,     1,
       2,     1,     1,     0,     2,     1,     3,     1,     1,     1,
       3,     3,     3,     1,     3,     4,     4,     4,     3,     2,
       4,     0,     1,     0,     2,     0,     1,     0,     1,     2,
       1,     1,     1,     2,     2,     1,     2,     3,     2,     3,
       2,     2,     2,     1,     1,     3,     0,     5,     5,     5,
       1,     3,     0,     2,     1,     3,     3,     2,     3,     1,
       2,     0,     3,     1,     1,     3,     3,     4,     4,     5,
       3,     4,     5,     6,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     1,     1,     4,     5,     6,
       4,     4,     6,     6,     6,     9,     7,     5,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     2,     4,
       4,     4,     4,     0,     3,     4,     7,     3,     1,     1,
       2,     3,     3,     1,     2,     2,     1,     2,     1,     2,
       2,     1,     2,     0,     1,     0,     2,     1,     2,     4,
       0,     2,     1,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     3,     0,     2,
       0,     3,     1,     3,     2,     0,     1,     1,     0,     2,
       4,     4,     0,     2,     4,     2,     1,     3,     5,     4,
       6,     1,     3,     3,     5,     0,     5,     1,     3,     1,
       2,     3,     1,     1,     3,     3,     1,     1,     0,     2,
       0,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       0,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 275 "sql_old.y" /* yacc.c:1646  */
    {
    setParseTree(yylex, (yyvsp[-1].statement))
  }
#line 3835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 280 "sql_old.y" /* yacc.c:1646  */
    {}
#line 3841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 281 "sql_old.y" /* yacc.c:1646  */
    {}
#line 3847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 285 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = (yyvsp[0].selStmt)
  }
#line 3855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 304 "sql_old.y" /* yacc.c:1646  */
    {
    sel := (yyvsp[-3].selStmt).(*Select)
    sel.OrderBy = (yyvsp[-2].orderBy)
    sel.Limit = (yyvsp[-1].limit)
    sel.Lock = (yyvsp[0].str)
    (yyval.selStmt) = sel
  }
#line 3867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 312 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selStmt) = &Union{Type: (yyvsp[-4].str), Left: (yyvsp[-5].selStmt), Right: (yyvsp[-3].selStmt), OrderBy: (yyvsp[-2].orderBy), Limit: (yyvsp[-1].limit), Lock: (yyvsp[0].str)}
  }
#line 3875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 316 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selStmt) = &Select{Comments: Comments((yyvsp[-5].bytes2)), Cache: (yyvsp[-4].str), SelectExprs: SelectExprs{Nextval{Expr: (yyvsp[-2].expr)}}, From: TableExprs{&AliasedTableExpr{Expr: (yyvsp[0].tableName)}}}
  }
#line 3883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 323 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selStmt) = &Select{Comments: Comments((yyvsp[-8].bytes2)), Cache: (yyvsp[-7].str), Distinct: (yyvsp[-6].str), Hints: (yyvsp[-5].str), SelectExprs: (yyvsp[-4].selectExprs), From: (yyvsp[-3].tableExprs), Where: NewWhere(WhereStr, (yyvsp[-2].expr)), GroupBy: GroupBy((yyvsp[-1].exprs)), Having: NewWhere(HavingStr, (yyvsp[0].expr))}
  }
#line 3891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 329 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selStmt) = (yyvsp[0].selStmt)
  }
#line 3899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 333 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selStmt) = &ParenSelect{Select: (yyvsp[-1].selStmt)}
  }
#line 3907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 339 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selStmt) = (yyvsp[0].selStmt)
  }
#line 3915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 343 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selStmt) = &ParenSelect{Select: (yyvsp[-1].selStmt)}
  }
#line 3923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 350 "sql_old.y" /* yacc.c:1646  */
    {
    // insert_data returns a *Insert pre-filled with Columns & Values
    ins := (yyvsp[-1].ins)
    ins.Action = (yyvsp[-5].str)
    ins.Comments = (yyvsp[-4].bytes2)
    ins.Ignore = (yyvsp[-3].str)
    ins.Table = (yyvsp[-2].tableName)
    ins.OnDup = OnDup((yyvsp[0].updateExprs))
    (yyval.statement) = ins
  }
#line 3938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 361 "sql_old.y" /* yacc.c:1646  */
    {
    cols := make(Columns, 0, len((yyvsp[-1].updateExprs)))
    vals := make(ValTuple, 0, len((yyvsp[0].updateExprs)))
    for _, updateList := range (yyvsp[-1].updateExprs) {
      cols = append(cols, updateList.Name.Name)
      vals = append(vals, updateList.Expr)
    }
    (yyval.statement) = &Insert{Action: (yyvsp[-6].str), Comments: Comments((yyvsp[-5].bytes2)), Ignore: (yyvsp[-4].str), Table: (yyvsp[-3].tableName), Columns: cols, Rows: Values{vals}, OnDup: OnDup((yyvsp[0].updateExprs))}
  }
#line 3952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 373 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = InsertStr
  }
#line 3960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 377 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ReplaceStr
  }
#line 3968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 383 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &Update{Comments: Comments((yyvsp[-6].bytes2)), TableExprs: (yyvsp[-5].tableExprs), Exprs: (yyvsp[-3].updateExprs), Where: NewWhere(WhereStr, (yyvsp[-2].expr)), OrderBy: (yyvsp[-1].orderBy), Limit: (yyvsp[0].limit)}
  }
#line 3976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 389 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &Delete{Comments: Comments((yyvsp[-5].bytes2)), TableExprs:  TableExprs{&AliasedTableExpr{Expr:(yyvsp[-3].tableName)}}, Where: NewWhere(WhereStr, (yyvsp[-2].expr)), OrderBy: (yyvsp[-1].orderBy), Limit: (yyvsp[0].limit)}
  }
#line 3984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 393 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &Delete{Comments: Comments((yyvsp[-4].bytes2)), Targets: (yyvsp[-3].tableNames), TableExprs: (yyvsp[-1].tableExprs), Where: NewWhere(WhereStr, (yyvsp[0].expr))}
  }
#line 3992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 398 "sql_old.y" /* yacc.c:1646  */
    {}
#line 3998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 399 "sql_old.y" /* yacc.c:1646  */
    {}
#line 4004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 403 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableNames) = TableNames{(yyvsp[0].tableName)}
  }
#line 4012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 407 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableNames) = append((yyval.tableNames), (yyvsp[0].tableName))
  }
#line 4020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 413 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &Set{Comments: Comments((yyvsp[-3].bytes2)), Charset: (yyvsp[-1].colIdent)}
  }
#line 4028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 417 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &Set{Comments: Comments((yyvsp[-1].bytes2)), Exprs: (yyvsp[0].updateExprs)}
   }
#line 4036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 428 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdent) = (yyvsp[0].colIdent)
  }
#line 4044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 432 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdent) = NewColIdent(string((yyvsp[0].bytes)))
  }
#line 4052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 438 "sql_old.y" /* yacc.c:1646  */
    {
    (yyvsp[-1].ddl).TableSpec = (yyvsp[0].TableSpec)
    (yyval.statement) = (yyvsp[-1].ddl)
  }
#line 4061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 443 "sql_old.y" /* yacc.c:1646  */
    {
    // Change this to an alter statement
    (yyval.statement) = &DDL{Action: AlterStr, Table: (yyvsp[-1].tableName), NewName:(yyvsp[-1].tableName)}
  }
#line 4070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 448 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &DDL{Action: CreateStr, NewName: (yyvsp[-1].tableName).ToViewName()}
  }
#line 4078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 452 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &DDL{Action: CreateStr, NewName: (yyvsp[-1].tableName).ToViewName()}
  }
#line 4086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 458 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.ddl) = &DDL{Action: CreateStr, NewName: (yyvsp[0].tableName)}
    setDDL(yylex, (yyval.ddl))
  }
#line 4095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 465 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.TableSpec) = (yyvsp[-2].TableSpec)
    (yyval.TableSpec).Options = (yyvsp[0].str)
  }
#line 4104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 472 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.TableSpec) = &TableSpec{}
    (yyval.TableSpec).AddColumn((yyvsp[0].columnDefinition))
  }
#line 4113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 477 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.TableSpec).AddColumn((yyvsp[0].columnDefinition))
  }
#line 4121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 481 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.TableSpec).AddIndex((yyvsp[0].indexDefinition))
  }
#line 4129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 487 "sql_old.y" /* yacc.c:1646  */
    {
    (yyvsp[-6].columnType).NotNull = (yyvsp[-5].boolVal)
    (yyvsp[-6].columnType).Default = (yyvsp[-4].optVal)
    (yyvsp[-6].columnType).OnUpdate = (yyvsp[-3].optVal)
    (yyvsp[-6].columnType).Autoincrement = (yyvsp[-2].boolVal)
    (yyvsp[-6].columnType).KeyOpt = (yyvsp[-1].colKeyOpt)
    (yyvsp[-6].columnType).Comment = (yyvsp[0].optVal)
    (yyval.columnDefinition) = &ColumnDefinition{Name: NewColIdent(string((yyvsp[-7].bytes))), Type: (yyvsp[-6].columnType)}
  }
#line 4143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 498 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = (yyvsp[-2].columnType)
    (yyval.columnType).Unsigned = (yyvsp[-1].boolVal)
    (yyval.columnType).Zerofill = (yyvsp[0].boolVal)
  }
#line 4153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 508 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = (yyvsp[-1].columnType)
    (yyval.columnType).Length = (yyvsp[0].optVal)
  }
#line 4162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 513 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = (yyvsp[0].columnType)
  }
#line 4170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 519 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 523 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 527 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 531 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 535 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 539 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 543 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 549 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes))}
    (yyval.columnType).Length = (yyvsp[0].LengthScaleOption).Length
    (yyval.columnType).Scale = (yyvsp[0].LengthScaleOption).Scale
  }
#line 4236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 555 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes))}
    (yyval.columnType).Length = (yyvsp[0].LengthScaleOption).Length
    (yyval.columnType).Scale = (yyvsp[0].LengthScaleOption).Scale
  }
#line 4246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 561 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes))}
    (yyval.columnType).Length = (yyvsp[0].LengthScaleOption).Length
    (yyval.columnType).Scale = (yyvsp[0].LengthScaleOption).Scale
  }
#line 4256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 567 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes))}
    (yyval.columnType).Length = (yyvsp[0].LengthScaleOption).Length
    (yyval.columnType).Scale = (yyvsp[0].LengthScaleOption).Scale
  }
#line 4266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 573 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes))}
    (yyval.columnType).Length = (yyvsp[0].LengthScaleOption).Length
    (yyval.columnType).Scale = (yyvsp[0].LengthScaleOption).Scale
  }
#line 4276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 581 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 585 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes)), Length: (yyvsp[0].optVal)}
  }
#line 4292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 589 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes)), Length: (yyvsp[0].optVal)}
  }
#line 4300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 593 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes)), Length: (yyvsp[0].optVal)}
  }
#line 4308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 597 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 603 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-3].bytes)), Length: (yyvsp[-2].optVal), Charset: (yyvsp[-1].str), Collate: (yyvsp[0].str)}
  }
#line 4324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 607 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-3].bytes)), Length: (yyvsp[-2].optVal), Charset: (yyvsp[-1].str), Collate: (yyvsp[0].str)}
  }
#line 4332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 611 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes)), Length: (yyvsp[0].optVal)}
  }
#line 4340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 615 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-1].bytes)), Length: (yyvsp[0].optVal)}
  }
#line 4348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 619 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-2].bytes)), Charset: (yyvsp[-1].str), Collate: (yyvsp[0].str)}
  }
#line 4356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 623 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-2].bytes)), Charset: (yyvsp[-1].str), Collate: (yyvsp[0].str)}
  }
#line 4364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 627 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-2].bytes)), Charset: (yyvsp[-1].str), Collate: (yyvsp[0].str)}
  }
#line 4372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 631 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-2].bytes)), Charset: (yyvsp[-1].str), Collate: (yyvsp[0].str)}
  }
#line 4380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 635 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 639 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 643 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 647 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 651 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[0].bytes))}
  }
#line 4420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 655 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columnType) = ColumnType{Type: string((yyvsp[-3].bytes)), EnumValues: (yyvsp[-1].strs)}
  }
#line 4428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 661 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.strs) = make([]string, 0, 4)
    (yyval.strs) = append((yyval.strs), "'" + string((yyvsp[0].bytes)) + "'")
  }
#line 4437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 666 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.strs) = append((yyvsp[-2].strs), "'" + string((yyvsp[0].bytes)) + "'")
  }
#line 4445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 671 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = nil
  }
#line 4453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 675 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = NewIntVal((yyvsp[-1].bytes))
  }
#line 4461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 680 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.LengthScaleOption) = LengthScaleOption{}
  }
#line 4469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 684 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.LengthScaleOption) = LengthScaleOption{
        Length: NewIntVal((yyvsp[-3].bytes)),
        Scale: NewIntVal((yyvsp[-1].bytes)),
    }
  }
#line 4480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 692 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.LengthScaleOption) = LengthScaleOption{}
  }
#line 4488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 696 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.LengthScaleOption) = LengthScaleOption{
        Length: NewIntVal((yyvsp[-1].bytes)),
    }
  }
#line 4498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 702 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.LengthScaleOption) = LengthScaleOption{
        Length: NewIntVal((yyvsp[-3].bytes)),
        Scale: NewIntVal((yyvsp[-1].bytes)),
    }
  }
#line 4509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 710 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(false)
  }
#line 4517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 714 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(true)
  }
#line 4525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 719 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(false)
  }
#line 4533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 723 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(true)
  }
#line 4541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 729 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(false)
  }
#line 4549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 733 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(false)
  }
#line 4557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 737 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(true)
  }
#line 4565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 742 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = nil
  }
#line 4573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 746 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = NewStrVal((yyvsp[0].bytes))
  }
#line 4581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 750 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = NewIntVal((yyvsp[0].bytes))
  }
#line 4589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 754 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = NewFloatVal((yyvsp[0].bytes))
  }
#line 4597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 758 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = NewValArg((yyvsp[0].bytes))
  }
#line 4605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 762 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = NewValArg((yyvsp[0].bytes))
  }
#line 4613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 767 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = nil
  }
#line 4621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 771 "sql_old.y" /* yacc.c:1646  */
    {
  (yyval.optVal) = NewValArg((yyvsp[0].bytes))
}
#line 4629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 776 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(false)
  }
#line 4637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 780 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(true)
  }
#line 4645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 785 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ""
  }
#line 4653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 789 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[0].bytes))
  }
#line 4661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 793 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[0].bytes))
  }
#line 4669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 798 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ""
  }
#line 4677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 802 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[0].bytes))
  }
#line 4685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 807 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colKeyOpt) = colKeyNone
  }
#line 4693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 811 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colKeyOpt) = colKeyPrimary
  }
#line 4701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 815 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colKeyOpt) = colKey
  }
#line 4709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 819 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colKeyOpt) = colKeyUniqueKey
  }
#line 4717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 823 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colKeyOpt) = colKeyUnique
  }
#line 4725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 828 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = nil
  }
#line 4733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 832 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.optVal) = NewStrVal((yyvsp[0].bytes))
  }
#line 4741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 838 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexDefinition) = &IndexDefinition{Info: (yyvsp[-3].indexInfo), Columns: (yyvsp[-1].indexColumns)}
  }
#line 4749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 844 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexInfo) = &IndexInfo{Type: string((yyvsp[-1].bytes)) + " " + string((yyvsp[0].bytes)), Name: NewColIdent("PRIMARY"), Primary: true, Unique: true}
  }
#line 4757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 848 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexInfo) = &IndexInfo{Type: string((yyvsp[-2].bytes)) + " " + string((yyvsp[-1].str)), Name: NewColIdent(string((yyvsp[0].bytes))), Unique: true}
  }
#line 4765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 852 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexInfo) = &IndexInfo{Type: string((yyvsp[-1].bytes)), Name: NewColIdent(string((yyvsp[0].bytes))), Unique: true}
  }
#line 4773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 856 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexInfo) = &IndexInfo{Type: string((yyvsp[-1].str)), Name: NewColIdent(string((yyvsp[0].bytes))), Unique: false}
  }
#line 4781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 862 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[0].bytes))
  }
#line 4789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 866 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[0].bytes))
  }
#line 4797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 872 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexColumns) = []*IndexColumn{(yyvsp[0].indexColumn)}
  }
#line 4805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 876 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexColumns) = append((yyval.indexColumns), (yyvsp[0].indexColumn))
  }
#line 4813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 882 "sql_old.y" /* yacc.c:1646  */
    {
      (yyval.indexColumn) = &IndexColumn{Column: (yyvsp[-1].colIdent), Length: (yyvsp[0].optVal)}
  }
#line 4821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 887 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ""
  }
#line 4829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 891 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = " " + string((yyvsp[0].str))
  }
#line 4837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 895 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[-2].str)) + ", " + string((yyvsp[0].str))
  }
#line 4845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 903 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = (yyvsp[0].str)
  }
#line 4853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 907 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = (yyvsp[-1].str) + " " + (yyvsp[0].str)
  }
#line 4861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 911 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = (yyvsp[-2].str) + "=" + (yyvsp[0].str)
  }
#line 4869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 917 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = (yyvsp[0].colIdent).String()
  }
#line 4877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 921 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = "'" + string((yyvsp[0].bytes)) + "'"
  }
#line 4885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 925 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[0].bytes))
  }
#line 4893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 931 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &DDL{Action: AlterStr, Table: (yyvsp[-2].tableName), NewName: (yyvsp[-2].tableName)}
  }
#line 4901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 935 "sql_old.y" /* yacc.c:1646  */
    {
    // Change this to a rename statement
    (yyval.statement) = &DDL{Action: RenameStr, Table: (yyvsp[-3].tableName), NewName: (yyvsp[0].tableName)}
  }
#line 4910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 940 "sql_old.y" /* yacc.c:1646  */
    {
    // Rename an index can just be an alter
    (yyval.statement) = &DDL{Action: AlterStr, Table: (yyvsp[-3].tableName), NewName: (yyvsp[-3].tableName)}
  }
#line 4919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 945 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &DDL{Action: AlterStr, Table: (yyvsp[-1].tableName).ToViewName(), NewName: (yyvsp[-1].tableName).ToViewName()}
  }
#line 4927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 949 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &DDL{Action: AlterStr, Table: (yyvsp[-1].tableName), PartitionSpec: (yyvsp[0].partSpec)}
  }
#line 4935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 955 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.partSpec) = &PartitionSpec{Action: ReorganizeStr, Name: (yyvsp[-4].colIdent), Definitions: (yyvsp[-1].partDefs)}
  }
#line 4943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 961 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.partDefs) = []*PartitionDefinition{(yyvsp[0].partDef)}
  }
#line 4951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 965 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.partDefs) = append((yyvsp[-2].partDefs), (yyvsp[0].partDef))
  }
#line 4959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 971 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.partDef) = &PartitionDefinition{Name: (yyvsp[-6].colIdent), Limit: (yyvsp[-1].expr)}
  }
#line 4967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 975 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.partDef) = &PartitionDefinition{Name: (yyvsp[-6].colIdent), Maxvalue: true}
  }
#line 4975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 981 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &DDL{Action: RenameStr, Table: (yyvsp[-2].tableName), NewName: (yyvsp[0].tableName)}
  }
#line 4983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 987 "sql_old.y" /* yacc.c:1646  */
    {
    var exists bool
    if (yyvsp[-1].byt) != 0 {
      exists = true
    }
    (yyval.statement) = &DDL{Action: DropStr, Table: (yyvsp[0].tableName), IfExists: exists}
  }
#line 4995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 995 "sql_old.y" /* yacc.c:1646  */
    {
    // Change this to an alter statement
    (yyval.statement) = &DDL{Action: AlterStr, Table: (yyvsp[-1].tableName), NewName: (yyvsp[-1].tableName)}
  }
#line 5004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1000 "sql_old.y" /* yacc.c:1646  */
    {
    var exists bool
        if (yyvsp[-2].byt) != 0 {
          exists = true
        }
    (yyval.statement) = &DDL{Action: DropStr, Table: (yyvsp[-1].tableName).ToViewName(), IfExists: exists}
  }
#line 5016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1010 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &DDL{Action: TruncateStr, Table: (yyvsp[0].tableName)}
  }
#line 5024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1014 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &DDL{Action: TruncateStr, Table: (yyvsp[0].tableName)}
  }
#line 5032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1019 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &DDL{Action: AlterStr, Table: (yyvsp[0].tableName), NewName: (yyvsp[0].tableName)}
  }
#line 5040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1025 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ShowUnsupportedStr
  }
#line 5048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1029 "sql_old.y" /* yacc.c:1646  */
    {
    switch v := string((yyvsp[0].bytes)); v {
    case ShowDatabasesStr, ShowTablesStr:
      (yyval.str) = v
    default:
      (yyval.str) = ShowUnsupportedStr
    }
  }
#line 5061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1038 "sql_old.y" /* yacc.c:1646  */
    {
    switch v := string((yyvsp[0].bytes)); v {
    case ShowKeyspacesStr, ShowShardsStr, ShowVSchemaTablesStr:
      (yyval.str) = v
    default:
      (yyval.str) = ShowUnsupportedStr
    }
}
#line 5074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1049 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &Show{Type: (yyvsp[-1].str)}
  }
#line 5082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1055 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &Use{DBName: (yyvsp[0].tableIdent)}
  }
#line 5090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1059 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &Use{DBName:TableIdent{v:""}}
  }
#line 5098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1065 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &OtherRead{}
  }
#line 5106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1069 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &OtherRead{}
  }
#line 5114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1073 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &OtherRead{}
  }
#line 5122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1077 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &OtherAdmin{}
  }
#line 5130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1081 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.statement) = &OtherAdmin{}
  }
#line 5138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1086 "sql_old.y" /* yacc.c:1646  */
    {
    setAllowComments(yylex, true)
  }
#line 5146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1090 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.bytes2) = (yyvsp[0].bytes2)
    setAllowComments(yylex, false)
  }
#line 5155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1096 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.bytes2) = nil
  }
#line 5163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1100 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.bytes2) = append((yyvsp[-1].bytes2), (yyvsp[0].bytes))
  }
#line 5171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1106 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = UnionStr
  }
#line 5179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1110 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = UnionAllStr
  }
#line 5187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1114 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = UnionDistinctStr
  }
#line 5195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1119 "sql_old.y" /* yacc.c:1646  */
    {
  (yyval.str) = ""
}
#line 5203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1123 "sql_old.y" /* yacc.c:1646  */
    {
  (yyval.str) = SQLNoCacheStr
}
#line 5211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1127 "sql_old.y" /* yacc.c:1646  */
    {
  (yyval.str) = SQLCacheStr
}
#line 5219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1132 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ""
  }
#line 5227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1136 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = DistinctStr
  }
#line 5235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1141 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ""
  }
#line 5243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1145 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = StraightJoinHint
  }
#line 5251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1150 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selectExprs) = nil
  }
#line 5259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1154 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selectExprs) = (yyvsp[0].selectExprs)
  }
#line 5267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1160 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selectExprs) = SelectExprs{(yyvsp[0].selectExpr)}
  }
#line 5275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1164 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selectExprs) = append((yyval.selectExprs), (yyvsp[0].selectExpr))
  }
#line 5283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1170 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selectExpr) = &StarExpr{}
  }
#line 5291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1174 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selectExpr) = &AliasedExpr{Expr: (yyvsp[-1].expr), As: (yyvsp[0].colIdent)}
  }
#line 5299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1178 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selectExpr) = &StarExpr{TableName: TableName{Name: (yyvsp[-2].tableIdent)}}
  }
#line 5307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1182 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.selectExpr) = &StarExpr{TableName: TableName{Qualifier: (yyvsp[-4].tableIdent), Name: (yyvsp[-2].tableIdent)}}
  }
#line 5315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1187 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdent) = ColIdent{}
  }
#line 5323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1191 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdent) = (yyvsp[0].colIdent)
  }
#line 5331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1195 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdent) = (yyvsp[0].colIdent)
  }
#line 5339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1202 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdent) = NewColIdent(string((yyvsp[0].bytes)))
  }
#line 5347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1207 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExprs) = TableExprs{&AliasedTableExpr{Expr:TableName{Name: NewTableIdent("dual")}}}
  }
#line 5355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1211 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExprs) = (yyvsp[0].tableExprs)
  }
#line 5363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1217 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExprs) = TableExprs{(yyvsp[0].tableExpr)}
  }
#line 5371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1221 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExprs) = append((yyval.tableExprs), (yyvsp[0].tableExpr))
  }
#line 5379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1231 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExpr) = (yyvsp[0].aliasedTableName)
  }
#line 5387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1235 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExpr) = &AliasedTableExpr{Expr:(yyvsp[-2].subquery), As: (yyvsp[0].tableIdent)}
  }
#line 5395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1239 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExpr) = &ParenTableExpr{Exprs: (yyvsp[-1].tableExprs)}
  }
#line 5403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1245 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.aliasedTableName) = &AliasedTableExpr{Expr:(yyvsp[-2].tableName), As: (yyvsp[-1].tableIdent), Hints: (yyvsp[0].indexHints)}
  }
#line 5411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1251 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columns) = Columns{(yyvsp[0].colIdent)}
  }
#line 5419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1255 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columns) = append((yyval.columns), (yyvsp[0].colIdent))
  }
#line 5427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1268 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExpr) = &JoinTableExpr{LeftExpr: (yyvsp[-3].tableExpr), Join: (yyvsp[-2].str), RightExpr: (yyvsp[-1].tableExpr), Condition: (yyvsp[0].joinCondition)}
  }
#line 5435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1272 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExpr) = &JoinTableExpr{LeftExpr: (yyvsp[-3].tableExpr), Join: (yyvsp[-2].str), RightExpr: (yyvsp[-1].tableExpr), Condition: (yyvsp[0].joinCondition)}
  }
#line 5443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1276 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExpr) = &JoinTableExpr{LeftExpr: (yyvsp[-3].tableExpr), Join: (yyvsp[-2].str), RightExpr: (yyvsp[-1].tableExpr), Condition: (yyvsp[0].joinCondition)}
  }
#line 5451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1280 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableExpr) = &JoinTableExpr{LeftExpr: (yyvsp[-2].tableExpr), Join: (yyvsp[-1].str), RightExpr: (yyvsp[0].tableExpr)}
  }
#line 5459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1286 "sql_old.y" /* yacc.c:1646  */
    { (yyval.joinCondition) = JoinCondition{On: (yyvsp[0].expr)} }
#line 5465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1288 "sql_old.y" /* yacc.c:1646  */
    { (yyval.joinCondition) = JoinCondition{Using: (yyvsp[-1].columns)} }
#line 5471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1292 "sql_old.y" /* yacc.c:1646  */
    { }
#line 5477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1294 "sql_old.y" /* yacc.c:1646  */
    { (yyval.joinCondition) = (yyvsp[0].joinCondition) }
#line 5483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1298 "sql_old.y" /* yacc.c:1646  */
    { }
#line 5489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1300 "sql_old.y" /* yacc.c:1646  */
    { (yyval.joinCondition) = JoinCondition{On: (yyvsp[0].expr)} }
#line 5495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1303 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 5501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1305 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 5507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1308 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableIdent) = NewTableIdent("")
  }
#line 5515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1312 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableIdent) = (yyvsp[0].tableIdent)
  }
#line 5523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1316 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableIdent) = (yyvsp[0].tableIdent)
  }
#line 5531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1323 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableIdent) = NewTableIdent(string((yyvsp[0].bytes)))
  }
#line 5539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1329 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = JoinStr
  }
#line 5547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1333 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = JoinStr
  }
#line 5555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1337 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = JoinStr
  }
#line 5563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1343 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = StraightJoinStr
  }
#line 5571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1349 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = LeftJoinStr
  }
#line 5579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1353 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = LeftJoinStr
  }
#line 5587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1357 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = RightJoinStr
  }
#line 5595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1361 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = RightJoinStr
  }
#line 5603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1367 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = NaturalJoinStr
  }
#line 5611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1371 "sql_old.y" /* yacc.c:1646  */
    {
    if (yyvsp[0].str) == LeftJoinStr {
      (yyval.str) = NaturalLeftJoinStr
    } else {
      (yyval.str) = NaturalRightJoinStr
    }
  }
#line 5623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1381 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableName) = (yyvsp[0].tableName)
  }
#line 5631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1385 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableName) = (yyvsp[0].tableName)
  }
#line 5639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1391 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableName) = TableName{Name: (yyvsp[0].tableIdent)}
  }
#line 5647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1395 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableName) = TableName{Qualifier: (yyvsp[-2].tableIdent), Name: (yyvsp[0].tableIdent)}
  }
#line 5655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1400 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexHints) = nil
  }
#line 5663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1404 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexHints) = &IndexHints{Type: UseStr, Indexes: (yyvsp[-1].colIdents)}
  }
#line 5671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1408 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexHints) = &IndexHints{Type: IgnoreStr, Indexes: (yyvsp[-1].colIdents)}
  }
#line 5679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1412 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.indexHints) = &IndexHints{Type: ForceStr, Indexes: (yyvsp[-1].colIdents)}
  }
#line 5687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1418 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdents) = []ColIdent{(yyvsp[0].colIdent)}
  }
#line 5695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1422 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdents) = append((yyvsp[-2].colIdents), (yyvsp[0].colIdent))
  }
#line 5703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1427 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = nil
  }
#line 5711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1431 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr)
  }
#line 5719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1437 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr)
  }
#line 5727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1441 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &AndExpr{Left: (yyvsp[-2].expr), Right: (yyvsp[0].expr)}
  }
#line 5735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1445 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &OrExpr{Left: (yyvsp[-2].expr), Right: (yyvsp[0].expr)}
  }
#line 5743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1449 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &NotExpr{Expr: (yyvsp[0].expr)}
  }
#line 5751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1453 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &IsExpr{Operator: (yyvsp[0].str), Expr: (yyvsp[-2].expr)}
  }
#line 5759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1457 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr)
  }
#line 5767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1461 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &Default{ColName: (yyvsp[0].str)}
  }
#line 5775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1467 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ""
  }
#line 5783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1471 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[-1].bytes))
  }
#line 5791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1477 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(true)
  }
#line 5799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1481 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.boolVal) = BoolVal(false)
  }
#line 5807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1487 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ComparisonExpr{Left: (yyvsp[-2].expr), Operator: (yyvsp[-1].str), Right: (yyvsp[0].expr)}
  }
#line 5815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1491 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ComparisonExpr{Left: (yyvsp[-2].expr), Operator: InStr, Right: (yyvsp[0].colTuple)}
  }
#line 5823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1495 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ComparisonExpr{Left: (yyvsp[-3].expr), Operator: NotInStr, Right: (yyvsp[0].colTuple)}
  }
#line 5831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1499 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ComparisonExpr{Left: (yyvsp[-3].expr), Operator: LikeStr, Right: (yyvsp[-1].expr), Escape: (yyvsp[0].expr)}
  }
#line 5839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1503 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ComparisonExpr{Left: (yyvsp[-4].expr), Operator: NotLikeStr, Right: (yyvsp[-1].expr), Escape: (yyvsp[0].expr)}
  }
#line 5847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1507 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ComparisonExpr{Left: (yyvsp[-2].expr), Operator: RegexpStr, Right: (yyvsp[0].expr)}
  }
#line 5855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1511 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ComparisonExpr{Left: (yyvsp[-3].expr), Operator: NotRegexpStr, Right: (yyvsp[0].expr)}
  }
#line 5863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1515 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &RangeCond{Left: (yyvsp[-4].expr), Operator: BetweenStr, From: (yyvsp[-2].expr), To: (yyvsp[0].expr)}
  }
#line 5871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1519 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &RangeCond{Left: (yyvsp[-5].expr), Operator: NotBetweenStr, From: (yyvsp[-2].expr), To: (yyvsp[0].expr)}
  }
#line 5879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1523 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ExistsExpr{Subquery: (yyvsp[0].subquery)}
  }
#line 5887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1529 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = IsNullStr
  }
#line 5895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1533 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = IsNotNullStr
  }
#line 5903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1537 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = IsTrueStr
  }
#line 5911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1541 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = IsNotTrueStr
  }
#line 5919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1545 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = IsFalseStr
  }
#line 5927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1549 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = IsNotFalseStr
  }
#line 5935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1555 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = EqualStr
  }
#line 5943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1559 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = LessThanStr
  }
#line 5951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1563 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = GreaterThanStr
  }
#line 5959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1567 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = LessEqualStr
  }
#line 5967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1571 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = GreaterEqualStr
  }
#line 5975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1575 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = NotEqualStr
  }
#line 5983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1579 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = NullSafeEqualStr
  }
#line 5991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1584 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = nil
  }
#line 5999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1588 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr)
  }
#line 6007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1594 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colTuple) = (yyvsp[0].valTuple)
  }
#line 6015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1598 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colTuple) = (yyvsp[0].subquery)
  }
#line 6023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1602 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colTuple) = ListArg((yyvsp[0].bytes))
  }
#line 6031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1608 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.subquery) = &Subquery{(yyvsp[-1].selStmt)}
  }
#line 6039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1614 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.exprs) = Exprs{(yyvsp[0].expr)}
  }
#line 6047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1618 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.exprs) = append((yyvsp[-2].exprs), (yyvsp[0].expr))
  }
#line 6055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1624 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr)
  }
#line 6063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1628 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].boolVal)
  }
#line 6071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1632 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].colName)
  }
#line 6079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1636 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr)
  }
#line 6087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1640 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].subquery)
  }
#line 6095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1644 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: BitAndStr, Right: (yyvsp[0].expr)}
  }
#line 6103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1648 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: BitOrStr, Right: (yyvsp[0].expr)}
  }
#line 6111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1652 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: BitXorStr, Right: (yyvsp[0].expr)}
  }
#line 6119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1656 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: PlusStr, Right: (yyvsp[0].expr)}
  }
#line 6127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1660 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: MinusStr, Right: (yyvsp[0].expr)}
  }
#line 6135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1664 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: MultStr, Right: (yyvsp[0].expr)}
  }
#line 6143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1668 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: DivStr, Right: (yyvsp[0].expr)}
  }
#line 6151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1672 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: IntDivStr, Right: (yyvsp[0].expr)}
  }
#line 6159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1676 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: ModStr, Right: (yyvsp[0].expr)}
  }
#line 6167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1680 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: ModStr, Right: (yyvsp[0].expr)}
  }
#line 6175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1684 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: ShiftLeftStr, Right: (yyvsp[0].expr)}
  }
#line 6183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1688 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].expr), Operator: ShiftRightStr, Right: (yyvsp[0].expr)}
  }
#line 6191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1692 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].colName), Operator: JSONExtractOp, Right: (yyvsp[0].expr)}
  }
#line 6199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1696 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &BinaryExpr{Left: (yyvsp[-2].colName), Operator: JSONUnquoteExtractOp, Right: (yyvsp[0].expr)}
  }
#line 6207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1700 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &CollateExpr{Expr: (yyvsp[-2].expr), Charset: (yyvsp[0].str)}
  }
#line 6215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1704 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &UnaryExpr{Operator: BinaryStr, Expr: (yyvsp[0].expr)}
  }
#line 6223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1708 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &UnaryExpr{Operator: UBinaryStr, Expr: (yyvsp[0].expr)}
  }
#line 6231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1712 "sql_old.y" /* yacc.c:1646  */
    {
    if num, ok := (yyvsp[0].expr).(*SQLVal); ok && num.Type == IntVal {
      (yyval.expr) = num
    } else {
      (yyval.expr) = &UnaryExpr{Operator: UPlusStr, Expr: (yyvsp[0].expr)}
    }
  }
#line 6243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1720 "sql_old.y" /* yacc.c:1646  */
    {
    if num, ok := (yyvsp[0].expr).(*SQLVal); ok && num.Type == IntVal {
      // Handle double negative
      if num.Val[0] == '-' {
        num.Val = num.Val[1:]
        (yyval.expr) = num
      } else {
        (yyval.expr) = NewIntVal(append([]byte("-"), num.Val...))
      }
    } else {
      (yyval.expr) = &UnaryExpr{Operator: UMinusStr, Expr: (yyvsp[0].expr)}
    }
  }
#line 6261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1734 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &UnaryExpr{Operator: TildaStr, Expr: (yyvsp[0].expr)}
  }
#line 6269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1738 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &UnaryExpr{Operator: BangStr, Expr: (yyvsp[0].expr)}
  }
#line 6277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1742 "sql_old.y" /* yacc.c:1646  */
    {
    // This rule prevents the usage of INTERVAL
    // as a function. If support is needed for that,
    // we'll need to revisit this. The solution
    // will be non-trivial because of grammar conflicts.
    (yyval.expr) = &IntervalExpr{Expr: (yyvsp[-1].expr), Unit: (yyvsp[0].colIdent).String()}
  }
#line 6289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1760 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name: (yyvsp[-3].colIdent), Exprs: (yyvsp[-1].selectExprs)}
  }
#line 6297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1764 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name: (yyvsp[-4].colIdent), Distinct: true, Exprs: (yyvsp[-1].selectExprs)}
  }
#line 6305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1768 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Qualifier: (yyvsp[-5].tableIdent), Name: (yyvsp[-3].colIdent), Exprs: (yyvsp[-1].selectExprs)}
  }
#line 6313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1778 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name: NewColIdent("left"), Exprs: (yyvsp[-1].selectExprs)}
  }
#line 6321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1782 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name: NewColIdent("right"), Exprs: (yyvsp[-1].selectExprs)}
  }
#line 6329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1786 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ConvertExpr{Expr: (yyvsp[-3].expr), Type: (yyvsp[-1].convertType)}
  }
#line 6337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1790 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ConvertExpr{Expr: (yyvsp[-3].expr), Type: (yyvsp[-1].convertType)}
  }
#line 6345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1794 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ConvertUsingExpr{Expr: (yyvsp[-3].expr), Type: (yyvsp[-1].str)}
  }
#line 6353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1798 "sql_old.y" /* yacc.c:1646  */
    {
  (yyval.expr) = &MatchExpr{Columns: (yyvsp[-6].selectExprs), Expr: (yyvsp[-2].expr), Option: (yyvsp[-1].str)}
  }
#line 6361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1802 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &GroupConcatExpr{Distinct: (yyvsp[-4].str), Exprs: (yyvsp[-3].selectExprs), OrderBy: (yyvsp[-2].orderBy), Separator: (yyvsp[-1].str)}
  }
#line 6369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1806 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &CaseExpr{Expr: (yyvsp[-3].expr), Whens: (yyvsp[-2].whens), Else: (yyvsp[-1].expr)}
  }
#line 6377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1810 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &ValuesFuncExpr{Name: (yyvsp[-1].colIdent)}
  }
#line 6385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1820 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name:NewColIdent("current_timestamp")}
  }
#line 6393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1824 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name:NewColIdent("utc_timestamp")}
  }
#line 6401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1828 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name:NewColIdent("utc_time")}
  }
#line 6409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1832 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name:NewColIdent("utc_date")}
  }
#line 6417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1837 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name:NewColIdent("localtime")}
  }
#line 6425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1842 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name:NewColIdent("localtimestamp")}
  }
#line 6433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1847 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name:NewColIdent("current_date")}
  }
#line 6441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1852 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name:NewColIdent("current_time")}
  }
#line 6449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1866 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name: NewColIdent("if"), Exprs: (yyvsp[-1].selectExprs)}
  }
#line 6457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1870 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name: NewColIdent("database"), Exprs: (yyvsp[-1].selectExprs)}
  }
#line 6465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1874 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name: NewColIdent("mod"), Exprs: (yyvsp[-1].selectExprs)}
  }
#line 6473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1878 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &FuncExpr{Name: NewColIdent("replace"), Exprs: (yyvsp[-1].selectExprs)}
  }
#line 6481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1884 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ""
  }
#line 6489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1888 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = BooleanModeStr
  }
#line 6497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1892 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = NaturalLanguageModeStr
 }
#line 6505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1896 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = NaturalLanguageModeWithQueryExpansionStr
 }
#line 6513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1900 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = QueryExpansionStr
 }
#line 6521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1906 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[0].bytes))
}
#line 6529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1910 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string((yyvsp[0].bytes))
}
#line 6537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1916 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[-1].bytes)), Length: (yyvsp[0].optVal)}
  }
#line 6545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1920 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[-2].bytes)), Length: (yyvsp[-1].optVal), Charset: (yyvsp[0].str), Operator: CharacterSetStr}
  }
#line 6553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1924 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[-2].bytes)), Length: (yyvsp[-1].optVal), Charset: string((yyvsp[0].bytes))}
  }
#line 6561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1928 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[0].bytes))}
  }
#line 6569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1932 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[-1].bytes)), Length: (yyvsp[0].optVal)}
  }
#line 6577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1936 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[-1].bytes))}
    (yyval.convertType).Length = (yyvsp[0].LengthScaleOption).Length
    (yyval.convertType).Scale = (yyvsp[0].LengthScaleOption).Scale
  }
#line 6587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1942 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[0].bytes))}
  }
#line 6595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1946 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[-1].bytes)), Length: (yyvsp[0].optVal)}
  }
#line 6603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1950 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[0].bytes))}
  }
#line 6611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1954 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[-1].bytes))}
  }
#line 6619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1958 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[-1].bytes)), Length: (yyvsp[0].optVal)}
  }
#line 6627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1962 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[0].bytes))}
  }
#line 6635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1966 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.convertType) = &ConvertType{Type: string((yyvsp[-1].bytes))}
  }
#line 6643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1971 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = nil
  }
#line 6651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1975 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr)
  }
#line 6659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1980 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = string("")
  }
#line 6667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1984 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = " separator '"+string((yyvsp[0].bytes))+"'"
  }
#line 6675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1990 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.whens) = []*When{(yyvsp[0].when)}
  }
#line 6683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1994 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.whens) = append((yyvsp[-1].whens), (yyvsp[0].when))
  }
#line 6691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2000 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.when) = &When{Cond: (yyvsp[-2].expr), Val: (yyvsp[0].expr)}
  }
#line 6699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2005 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = nil
  }
#line 6707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2009 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr)
  }
#line 6715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2015 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colName) = &ColName{Name: (yyvsp[0].colIdent)}
  }
#line 6723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2019 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colName) = &ColName{Qualifier: TableName{Name: (yyvsp[-2].tableIdent)}, Name: (yyvsp[0].colIdent)}
  }
#line 6731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2023 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colName) = &ColName{Qualifier: TableName{Qualifier: (yyvsp[-4].tableIdent), Name: (yyvsp[-2].tableIdent)}, Name: (yyvsp[0].colIdent)}
  }
#line 6739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2029 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = NewStrVal((yyvsp[0].bytes))
  }
#line 6747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2033 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = NewHexVal((yyvsp[0].bytes))
  }
#line 6755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2037 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = NewBitVal((yyvsp[0].bytes))
  }
#line 6763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2041 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = NewIntVal((yyvsp[0].bytes))
  }
#line 6771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2045 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = NewFloatVal((yyvsp[0].bytes))
  }
#line 6779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2049 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = NewHexNum((yyvsp[0].bytes))
  }
#line 6787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2053 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = NewValArg((yyvsp[0].bytes))
  }
#line 6795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2057 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = &NullVal{}
  }
#line 6803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2063 "sql_old.y" /* yacc.c:1646  */
    {
    // TODO(sougou): Deprecate this construct.
    if (yyvsp[0].colIdent).Lowered() != "value" {
      yylex.Error("expecting value after next")
      return 1
    }
    (yyval.expr) = NewIntVal([]byte("1"))
  }
#line 6816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2072 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = NewIntVal((yyvsp[-1].bytes))
  }
#line 6824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2076 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = NewValArg((yyvsp[-1].bytes))
  }
#line 6832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2081 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.exprs) = nil
  }
#line 6840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2085 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.exprs) = (yyvsp[0].exprs)
  }
#line 6848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2090 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = nil
  }
#line 6856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2094 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr)
  }
#line 6864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2099 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.orderBy) = nil
  }
#line 6872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2103 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.orderBy) = (yyvsp[0].orderBy)
  }
#line 6880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2109 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.orderBy) = OrderBy{(yyvsp[0].order)}
  }
#line 6888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2113 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.orderBy) = append((yyvsp[-2].orderBy), (yyvsp[0].order))
  }
#line 6896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2119 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.order) = &Order{Expr: (yyvsp[-1].expr), Direction: (yyvsp[0].str)}
  }
#line 6904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2124 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = AscScr
  }
#line 6912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2128 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = AscScr
  }
#line 6920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2132 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = DescScr
  }
#line 6928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2137 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.limit) = nil
  }
#line 6936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2141 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.limit) = &Limit{Rowcount: (yyvsp[0].expr)}
  }
#line 6944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2145 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.limit) = &Limit{Offset: (yyvsp[-2].expr), Rowcount: (yyvsp[0].expr)}
  }
#line 6952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2149 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.limit) = &Limit{Offset: (yyvsp[0].expr), Rowcount: (yyvsp[-2].expr)}
  }
#line 6960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2154 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ""
  }
#line 6968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2158 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ForUpdateStr
  }
#line 6976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2162 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.str) = ShareModeStr
  }
#line 6984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2175 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.ins) = &Insert{Rows: (yyvsp[0].values)}
  }
#line 6992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2179 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.ins) = &Insert{Rows: (yyvsp[0].selStmt)}
  }
#line 7000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2183 "sql_old.y" /* yacc.c:1646  */
    {
    // Drop the redundant parenthesis.
    (yyval.ins) = &Insert{Rows: (yyvsp[-1].selStmt)}
  }
#line 7009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2188 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.ins) = &Insert{Columns: (yyvsp[-3].columns), Rows: (yyvsp[0].values)}
  }
#line 7017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2192 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.ins) = &Insert{Columns: (yyvsp[-2].columns), Rows: (yyvsp[0].selStmt)}
  }
#line 7025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2196 "sql_old.y" /* yacc.c:1646  */
    {
    // Drop the redundant parenthesis.
    (yyval.ins) = &Insert{Columns: (yyvsp[-4].columns), Rows: (yyvsp[-1].selStmt)}
  }
#line 7034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2203 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columns) = Columns{(yyvsp[0].colIdent)}
  }
#line 7042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2207 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columns) = Columns{(yyvsp[0].colIdent)}
  }
#line 7050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2211 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columns) = append((yyval.columns), (yyvsp[0].colIdent))
  }
#line 7058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2215 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.columns) = append((yyval.columns), (yyvsp[0].colIdent))
  }
#line 7066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2220 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.updateExprs) = nil
  }
#line 7074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2224 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.updateExprs) = (yyvsp[0].updateExprs)
  }
#line 7082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2230 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.values) = Values{(yyvsp[0].valTuple)}
  }
#line 7090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2234 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.values) = append((yyvsp[-2].values), (yyvsp[0].valTuple))
  }
#line 7098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2240 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.valTuple) = (yyvsp[0].valTuple)
  }
#line 7106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2244 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.valTuple) = ValTuple{}
  }
#line 7114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2250 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.valTuple) = ValTuple((yyvsp[-1].exprs))
  }
#line 7122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2256 "sql_old.y" /* yacc.c:1646  */
    {
    if len((yyvsp[0].valTuple)) == 1 {
      (yyval.expr) = &ParenExpr{(yyvsp[0].valTuple)[0]}
    } else {
      (yyval.expr) = (yyvsp[0].valTuple)
    }
  }
#line 7134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2266 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.updateExprs) = UpdateExprs{(yyvsp[0].updateExpr)}
  }
#line 7142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2270 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.updateExprs) = append((yyvsp[-2].updateExprs), (yyvsp[0].updateExpr))
  }
#line 7150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2276 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.updateExpr) = &UpdateExpr{Name: (yyvsp[-2].colName), Expr: (yyvsp[0].expr)}
  }
#line 7158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2285 "sql_old.y" /* yacc.c:1646  */
    { (yyval.byt) = 0 }
#line 7164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2287 "sql_old.y" /* yacc.c:1646  */
    { (yyval.byt) = 1 }
#line 7170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2290 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2292 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2295 "sql_old.y" /* yacc.c:1646  */
    { (yyval.str) = "" }
#line 7188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2297 "sql_old.y" /* yacc.c:1646  */
    { (yyval.str) = IgnoreStr }
#line 7194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2301 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2303 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2305 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2307 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2309 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2311 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2313 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2315 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2317 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2319 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2321 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2324 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2326 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2328 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2332 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2334 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2337 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2339 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2341 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2344 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2346 "sql_old.y" /* yacc.c:1646  */
    { (yyval.empty) = struct{}{} }
#line 7320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2350 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdent) = NewColIdent(string((yyvsp[0].bytes)))
  }
#line 7328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2354 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdent) = NewColIdent(string((yyvsp[0].bytes)))
  }
#line 7336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2361 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.colIdent) = NewColIdent(string((yyvsp[0].bytes)))
  }
#line 7344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2367 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableIdent) = NewTableIdent(string((yyvsp[0].bytes)))
  }
#line 7352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2371 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableIdent) = NewTableIdent(string((yyvsp[0].bytes)))
  }
#line 7360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2378 "sql_old.y" /* yacc.c:1646  */
    {
    (yyval.tableIdent) = NewTableIdent(string((yyvsp[0].bytes)))
  }
#line 7368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2553 "sql_old.y" /* yacc.c:1646  */
    {
    if incNesting(yylex) {
      yylex.Error("max nesting level reached")
      return 1
    }
  }
#line 7379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2562 "sql_old.y" /* yacc.c:1646  */
    {
    decNesting(yylex)
  }
#line 7387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2567 "sql_old.y" /* yacc.c:1646  */
    {
  forceEOF(yylex)
}
#line 7395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2572 "sql_old.y" /* yacc.c:1646  */
    {
    forceEOF(yylex)
  }
#line 7403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2576 "sql_old.y" /* yacc.c:1646  */
    {
    forceEOF(yylex)
  }
#line 7411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2580 "sql_old.y" /* yacc.c:1646  */
    {
    forceEOF(yylex)
  }
#line 7419 "y.tab.c" /* yacc.c:1646  */
    break;


#line 7423 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
