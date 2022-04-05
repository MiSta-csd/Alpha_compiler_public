%{
#pragma once
#include <assert.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include "symtable.h"

int yyerror(std::string message);

extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern int yylex();

extern std::vector< std::unordered_map<std::string, st_entry> > symbol_table;

int scope = 0;

void print_rules(std::string str) {
	std::cout << "~ entered rule :\t " << str << std::endl;
}

%}

%defines
%output "parser.cpp"

%union{
	int intConst;
	double realConst;
	std::string *strConst;

}

%token<intConst> INTEGER 
%token<realConst> REAL
%token<strConst> STRING
%token TRUE FALSE OR LOCAL NIL UMINUS MINUSMINUS ID
%token IF ELSE WHILE FUNCTION FOR RETURN BREAK CONTINUE AND NOT 
%token ASSIGN PLUS MINUS MULT DIVIDE PERCENT NOTEQUAL PLUSPLUS
%token GREATER  LESSER GREATEREQUAL LESSEREQUAL EQUAL
%token LCBRACK RCBRACK LBRACK RBRACK LPAREN RPAREN SEMICOLON COMMA COLON COLONCOLON DOT DOTDOT
%type program stmts stmt expr term assignexpr primary
%type member call elist objectdef const returnstmt
%type<strConst> funcdef lvalue // will be actual symTable's type

%right 		ASSIGN
%left 		OR
%left 		AND
%nonassoc 	EQUAL NOTEQUAL
%nonassoc 	GREATER  LESSER GREATEREQUAL LESSEREQUAL
%left 		PLUS MINUS
%left 		MULT DIVIDE PERCENT
%right 		NOT PLUSPLUS MINUSMINUS UMINUS
%left 		DOT DOTDOT
%left 		LBRACK RBRACK
%left 		LPAREN RPAREN

%start program
%expect 1

%%

program:	  stmts						{std::cout << "Finished reading statements\n";}
			;

// Rule 2.
stmts		: stmts stmt 				{print_rules("2.1 stmts -> stmts stmt");}
			|							{print_rules("2.2 stmts -> ε");}
			;
// Rule 3.
stmt		: expr SEMICOLON			{print_rules("3.1 stmt -> expr ;");}
			| ifstmt					{print_rules("3.2 stmt -> ifstmt");}
			| whilestmt					{print_rules("3.3 stmt -> whilestmt");}
			| forstmt					{print_rules("3.4 stmt -> forstmt");}
			| returnstmt				{print_rules("3.5 stmt -> returnstmt");}
			| BREAK SEMICOLON			{print_rules("3.6 stmt -> BREAK ;");}
			| CONTINUE SEMICOLON		{print_rules("3.7 stmt -> CONTINUE ;");}
			| block						{print_rules("3.8 stmt -> block");}
			| funcdef					{print_rules("3.9 stmt -> funcdef");}
			| SEMICOLON					{print_rules("3.10 stmt -> ;");}
			;

// Rule 4.
expr		: assignexpr				{print_rules("4.1 expr -> assignexpr");}
			| expr PLUS expr			{print_rules("4.2 expr -> expr + expr");}
			| expr MINUS expr			{print_rules("4.3 expr -> expr - expr");}
			| expr MULT expr			{print_rules("4.4 expr -> expr * expr");}
			| expr DIVIDE expr			{print_rules("4.5 expr -> expr / expr");}
			| expr PERCENT expr			{print_rules("4.6 expr -> expr \% expr");}
			| expr GREATER expr			{print_rules("4.7 expr -> expr > expr");}
			| expr GREATEREQUAL expr	{print_rules("4.8 expr -> expr >= expr");}	
			| expr LESSER expr			{print_rules("4.9 expr -> expr < expr");}
			| expr LESSEREQUAL expr		{print_rules("4.10 expr -> expr <= expr");}	
			| expr EQUAL expr			{print_rules("4.11 expr -> expr == expr");}	
			| expr NOTEQUAL expr		{print_rules("4.12 expr -> expr != expr");}
			| expr AND expr				{print_rules("4.13 expr -> expr AND expr");}
			| expr OR expr				{print_rules("4.14 expr -> expr OR expr");}
			| term						{print_rules("4.15 expr -> term");}
			;
// Rule 5.
term		: LPAREN expr RPAREN		{print_rules("5.1 term -> ( expr )");}
			| MINUS expr %prec UMINUS	{print_rules("5.2 term -> - expr");}
			| NOT expr					{print_rules("5.3 term -> NOT expr");}
			| PLUSPLUS lvalue			{print_rules("5.4 term -> ++ lvalue");}
			| lvalue PLUSPLUS			{print_rules("5.5 term -> lvalue ++");}
			| MINUSMINUS lvalue			{print_rules("5.6 term -> -- lvalue");}
			| lvalue MINUSMINUS			{print_rules("5.7 term ->  lvalue --");}
			| primary					{print_rules("5.8 term -> primary");}
			;
// Rule 6.
assignexpr	: lvalue ASSIGN expr		{
		   							/* 		if($1.type==LIBFUNC || $1.type==USERFUNC) */
												/* insertError("invalid assignment(lvalue is a function)\n", yylineno); */
											print_rules("6.1 assignexpr -> lvalue = expr");
										};

// Rule 7.
primary		: lvalue					{print_rules("7.1 primary -> lvalue");}
			| call						{print_rules("7.2 primary -> call");}
			| objectdef					{print_rules("7.3 primary -> objectdef");}
			| LPAREN funcdef RPAREN		{print_rules("7.4 primary -> ( funcdef )");}
			| const						{print_rules("7.5 primary -> const");}
			;
// Rule 8.
lvalue		: ID						{
											/* l = lookup((char *)$1, NORMAL_LOC, 0); */
											/* printf("normal normal %s",$1); */
											/* if(l==ERR) */
											/* 	insertError("a matching variable was found but a function was defined inbetween\n", yylineno); */
											/* if(l==NOTFOUND) */
											/* 	$$ = *insert((char *)$1, (scope==0)?GLOBALVAR:LOCALVAR); */
											/* if(l==FOUND_NOTREDIFIN) */
											/* 	$$ = return_Entry; */
											print_rules("8.1 lvalue -> ID");
										}
			| LOCAL ID					{
											/* l = lookup((char *)$2, LOCAL_LOC, 0); */
											/* printf("local local %s",$2); */
											/* if(l==ERR){ */
											/* 	insertError("id reserved for LIB FUNC\n", yylineno); */
											/* } */
											/* else if(l==NOTFOUND){ */
											/* 	$$ = *insert((char *)$2, (scope==0)?GLOBALVAR:LOCALVAR); */
											/* } */
											/* else if(l==FOUND) */
											/* 	$$ = return_Entry; */
											print_rules("8.2 lvalue -> local ID");}
			| COLONCOLON ID				{
											/* l = lookup((char *)$2, GLOBAL_LOC, 0); */
											/* printf("colon colon %s,enum %d",$2, l); */
											/* if(l==ERR){ */
											/* 	insertError("id was not found in the SymbolTable\n", yylineno); */
											/* } */
											/* else if(l==FOUND || l==FOUND_NOTREDIFIN) */
											/* 	$$ = return_Entry; */
											/* print_rules("8.3 lvalue -> ::ID"); */
										}
			| member					{print_rules("8.4 lvalue -> member");}
			;
// Rule 9.
member		: lvalue DOT ID				{print_rules("9.1 member -> lvalue . ID");}
			| lvalue LBRACK expr RBRACK	{print_rules("9.2 member -> lvalue [ expr ]");}
			| call DOT ID				{print_rules("9.3 member -> call . ID");}
			| call LBRACK expr RBRACK 	{print_rules("9.4 member -> call [ expr ]");}
			;
// Rule 10.
call		: call LPAREN elist RPAREN	{print_rules("10.1 member -> call ( elist )");}
			| lvalue callsuffix			{print_rules("10.2 member -> lvalue callsuffix");}
			| LPAREN funcdef RPAREN LPAREN elist RPAREN
										{print_rules("10.3 member -> ( funcdef ) ( elist )");}
			;
// Rule 11.
callsuffix	: normcall					{print_rules("11.1 member -> normcall");}
			| methodcall				{print_rules("11.2 member -> methodcall");}
			;
// Rule 12.
normcall	: LPAREN elist RPAREN		{print_rules("12.1 normcall -> ( elist )");}
			;
// Rule 13.
methodcall	: DOTDOT ID LPAREN elist RPAREN
		   								{print_rules("13.1 methodcall -> .. ID ( elist )");}
			;
// Rule 14.
elist		: expr 						{print_rules("14.1 elist -> expr");}
			| elist COMMA expr 			{print_rules("14.2 elist -> elist , expr");}
			| 							{print_rules("14.3 elist -> ε");}
			;
// Rule 15.
objectdef	: LBRACK elist RBRACK 		{print_rules("15.1 objectdef -> [ elist ]");}
			| LBRACK indexed RBRACK 	{print_rules("15.2 objectdef -> [ indexed ]");}
			;
// Rule 16.
indexed		: indexedelem 				{print_rules("16.1 indexed -> indexedelem");}
			| indexed COMMA indexedelem	{print_rules("16.2 indexed ->  indexed , indexedelem");}
			;
// Rule 17.
indexedelem	: LCBRACK expr COLON expr RCBRACK
										{print_rules("17.1 indexedelem -> { expr : expr }");}
			;
// Rule 18.
block		: LCBRACK //{ increaseScope();}
	   					stmts RCBRACK 	{
											/* hide(); decreaseScope(); */
	   										print_rules("18.1 block -> { stmts }");
										}
			;
// Rule 19.
funcdef		: FUNCTION //{/*change from here(oldlineno[scope])*/oldlineno[scope] = yylineno;}
		 				LPAREN			{scope++;}
						idlist RPAREN	{
											scope--;
											/* char *tempName = malloc(10); */
											/* sprintf(tempName, "$f%d", nonos++); */
											/* swap(&yylineno, &oldlineno[scope]); */
											/* funcDefs[scope]= *insert(tempName,  USERFUNC); */
											/* swap(&yylineno, &oldlineno[scope]); */
											/* free(tempName);} block {$$ = funcDefs[scope]; */
											print_rules("19.1 funcdef -> function ( idlist ) block");
										}
			/* | FUNCTION 					{oldlineno[scope] = yylineno;} */
			  ID LPAREN					{scope++;} 
			  idlist RPAREN				{
											scope--;
											/* l = lookup((char *)$3, NORMAL_LOC, 1); */
											/* if(l==ERR) */
											/* 	insertError("a variable or Function was detected in the same scope", yylineno); */
											/* if(l==NOTFOUND) */
											/* { */
											/* 	swap(&yylineno, &oldlineno[scope]); */
											/* 	funcDefs[scope]= *insert((char *)$3,  USERFUNC); */
											/* 	swap(&yylineno, &oldlineno[scope]); */
											/* } */
										}
			 block 						{
											/* $$ = funcDefs[scope]; */
											print_rules("19.2 indexed -> function ID ( idlist ) block");
										}	// reduce/reduce conflict
			 ;/*change to here(oldlineno[scope])*/
// Rule 20.
const		: INTEGER 					{print_rules("20.1 const -> INTEGER");}
	   		| REAL 						{("20.1 const -> REAL");}
			| STRING 					{print_rules("20.2 const -> STRING");}
			| NIL 						{print_rules("20.3 const -> NIL");}
			| TRUE 						{print_rules("20.4 const -> TRUE");}
			| FALSE						{print_rules("20.5 const -> FALSE");}
			;
// Rule 21.
idlist		: ID 						{
											/* 	l = lookup((char *)$1, FORMAL_LOC, 0); */
											/* if(l==ERR) */
											/* 	insertError("variable already declared in argument list\n", yylineno); */
											/* if(l==NOTFOUND) */
											/* 	insert((char *)$1, FORMALVAR); */
											print_rules("22.1 idlist -> ID");
										}
			| idlist COMMA ID 			{
											/* l = lookup((char *)$3, FORMAL_LOC, 0); */
											/* if(l==ERR) */
											/* 	insertError("variable already declared in argument list\n", yylineno); */
											/* if(l==NOTFOUND) */
											/* 	insert((char *)$3, FORMALVAR); */
											print_rules("22.2 idlist -> idlist , ID");
										}
			|
			;
// Rule 22.
ifstmt		: IF LPAREN expr RPAREN stmt 			
										{print_rules("23.1 ifstmt -> if ( expr ) stmt");}
			| IF LPAREN expr RPAREN stmt ELSE stmt
										{print_rules("23.2 ifstmt -> if ( expr ) stmt else stmt");}
			;
// Rule 23.
whilestmt	: WHILE LPAREN expr RPAREN stmt
		  								{print_rules("24.1 whilestmt -> while ( expr ) stmt");}
			;
// Rule 24.
forstmt		: FOR LPAREN elist SEMICOLON expr SEMICOLON elist RPAREN stmt 
										{print_rules("25.1 forstmt -> for ( elist ; expr ; elist ) stmt");}
			;
// Rule 25.
returnstmt 	: RETURN SEMICOLON 			{print_rules("26.1 returnstmt -> return ;");}
			| RETURN expr SEMICOLON 	{print_rules("26.2 returnstmt -> return expr ;");}
			;

%%

extern void validate_comments();

int yyerror(std::string message){
	std::cout << message << ": at line: " << yylineno << ", before token: " << yytext << std::endl
	<< "INVALID INPUT\n";
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

    while( yyparse() != 0);
	validate_comments();

    return 0;
}

