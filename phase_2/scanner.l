%{
#if defined(WIN32)
#define YY_NO_UNISTD_H
#elif defined(_WIN32_WCE)
#define YY_NO_UNISTD_H
#endif

#include <stdlib.h>
#include <iostream>
#include <string>
/* #include <vector> */
#include <stack>
#include <climits> // this is added to allow uns lng cast to int
/* #include <cassert> */
#include "parser.hpp"


unsigned long tok_count = 1lu;
unsigned int line_count = 1u;
std::stack<unsigned long> cmnt_stack;

/*
	*@brief function for handling escape characters inside strings
*/
/* void handle_string(){ */
/* 	assert(yytext); */
/* 	std::string str, debug; */
/* 	str.resize(yyleng); */
/* 	int i = 0, j = 0; */
/* 	enum tok_error_t flag = FLAWLESS; */
/* 	while(yytext[i] != 0) { */
/* 		if(yytext[i] == '\"' && i > 0 && yytext[i-1] != '\\' && j > 0) { */
/* 			str.at(j) += '\"'; */
/* 			if(flag == WARNING) { */
/* 				debug = std::string("Invalid escape characters detected: ") + debug; */
/* 			} */
/* 			alpha_token_t tok{ */
/* 				line_count, */
/* 				tok_count++, */
/* 				str.substr(0, j+1), */
/* 				flag, */
/* 				debug, */
/* 				STRINGCONST, */
/* 			}; */
/* 			tok_vec.push_back(tok); */
/* 			flag = FLAWLESS; */
/* 			str.clear(); */
/* 			str.resize(yyleng - j); */
/* 			j = 0; */
/* 			debug.clear(); */
/* 			++i; */
/* 			continue; */
/* 		} */
/* 		else if(yytext[i] == '\\') { */
/* 			++i; */
/* 			switch(yytext[i]){ */
/* 				case 'n': */
/* 					str.at(j) = '\n'; */
/* 					break; */
/* 				case 't': */
/* 					str.at(j) = '\t'; */
/* 					break; */
/* 				case 'a': */
/* 					str.at(j) = '\a'; */
/* 					break; */
/* 				case '\"': */
/* 					str.at(j) = '\"'; */
/* 					break; */
/* 				case '\\': */
/* 					str.at(j) = '\\'; */
/* 					break; */
/* 				case 'v': */
/* 					str.at(j) = '\v'; */
/* 					break; */
/* 				case '0': */
/* 					str.at(j) = '\0'; */
/* 					break; */
/* 				default :	// for printing the bad esc chars */
/* 					debug.append((yytext + i-1), 2); */
/* 					debug.append("  "); */
/* 					str.at(j++) = yytext[i-1]; */
/* 					str.at(j) = yytext[i]; */
/* 					flag = WARNING; */
/* 			} */
/* 		} */
/* 		else { */
/* 			str.at(j) = yytext[i]; */
/* 		} */
/* 		++i; */
/* 		++j; */
/* 	} */
/* 	if(yytext[i-2] == '\\'){ */
/* 		debug = "string literal is not closing"; */
/* 		alpha_token_t tok{ */
/* 			line_count, */
/* 			tok_count++, */
/* 			str.substr(0, j+1), */
/* 			ERROR, */
/* 			debug, */
/* 			STRINGCONST, */
/* 		}; */
/* 		tok_vec.push_back(tok); */
/* 	} */
/* } */

%}

%option noyywrap
%option yylineno
%option header-file="./scanner.hpp"


keyword			if|else|while|for|function|return|break|continue|and|not|or|local|true|false|nil
integer			(0[xX][0-9A-Fa-f]+)|([0-9]+)
real			[0-9]+\.[0-9](e|E)?[0-9]*
string			\"[^\n]*\"
/* punctuation		"::"|".."|[\{\}\[\]\(\)\;\,\:\.] */
identifier		[a-zA-Z][a-zA-Z_0-9]*
slcomment		"//".*
mlcomment		"/*"
space			[ \t]*

%x MLCOMMENT
%x C_STRING

%%

\n				{ line_count++; }
{space}			{;}

{slcomment}		{ 
				}

{mlcomment}		{
					std::string str = std::to_string(line_count);
					str.append(" - ");
					cmnt_stack.push(tok_count);
					BEGIN(MLCOMMENT);
				}

<MLCOMMENT>"\n"	{ line_count++; }

<MLCOMMENT>"/"+"*"	
				{
					/* std::string st = std::to_string(line_count); */
					/* st.append(" - "); */
					/* cmnt_stack.push(tok_count); */
				}

<MLCOMMENT>"*"+"/"
				{ 	
					/* if (!cmnt_stack.empty()) { */
					/* 	int indx = cmnt_stack.top() & INT_MAX; */
					/* 	tok_vec[indx-2].tok_val.append(std::to_string(line_count)); */
					/* 	cmnt_stack.pop(); */
					/* 	if (cmnt_stack.empty()){ */
					/* 		BEGIN(INITIAL); */
					/* 	}else{ */
					/* 		BEGIN(MLCOMMENT); */
					/* 	} */
					/* } */
				}
<MLCOMMENT>.  	{ ; }


"if"		{ return IF; }
"else"		{ return ELSE; }
"while"		{ return WHILE; }
"function"	{ return FUNCTION; }
"for"		{ return FOR; }
"return"	{ return RETURN; }
"break"		{ return BREAK; }
"continue"	{ return CONTINUE; }
"and"		{ return AND; }
"not"		{ return NOT; }
"or"		{ return OR; }
"local"		{ return LOCAL; }
"true"		{ return TRUE; }
"false"		{ return FALSE; }
"nil"		{ return NIL; }
"="			{ return ASSIGN; }
"+"			{ return PLUS; }
"-"			{ return MINUS; }
"*"			{ return MULT; }
"/"			{ return DIVIDE; }
"%"			{ return PERCENT; }
"=="		{ return EQUAL; }
"!="		{ return NOTEQUAL; }
"++"		{ return PLUSPLUS; }
"--"		{ return MINUSMINUS; }
">"			{ return GREATER; }
"<"			{ return LESSER; }
">="		{ return GREATEREQUAL; }
"<="		{ return LESSEREQUAL; }
"{"			{ return LCBRACK; }
"}"			{ return RCBRACK; }
"["			{ return LBRACK; }
"]"			{ return RBRACK; }
"("			{ return LPAREN; }
")"			{ return RPAREN; }
";"			{ return SEMICOLON; }
","			{ return COMMA; }
":"			{ return COLON; }
"::"		{ return COLONCOLON; }
"."			{ return DOT; }
".."		{ return DOTDOT; }

{integer}		{ 
					return INTEGER;
				}
{real}			{ 
					return REAL;
				}
{string}		{ 
					/* handle_string(); */
					return STRING;
				}

{identifier}	{ 
					return ID;
				}

.               { 
					/* std::string str(yytext), debug; */
					/* int i = 0; */
					/* while(isspace(yytext[i])){ */
					/* 	++i; */
					/* } */
					/* enum token_t_enum category = UNDEFINED; */
					/* if(yytext[i] == '\"'){ */
					/* 	debug = "string literal is not closing"; */
						/* category = STRINGCONST; */
					/* } */
					/* else{ */
					/* 	debug = std::string("Undefined character token : ") += yytext[i]; */
					/* } */
				}

<<EOF>>			{ return 0; }

%%

/* int validate_comments() { */
/* 	 */
/* 	int indx = 0; */
/* 	while (!cmnt_stack.empty()) { */
/* 		indx = cmnt_stack.top() & INT_MAX; */
/* 		tok_vec[indx-2].tok_err_t = ERROR; */
/* 		tok_vec[indx-2].tok_debug = "Non-closing comment block."; */
/* 		cmnt_stack.pop(); */
/* 	} */
/* 	return ((indx) ? -1 : 0); */
/* } */
