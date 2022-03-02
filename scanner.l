%{
#if defined(WIN32)
#define YY_NO_UNISTD_H
static int isatty (int i) { return 0; }
#elif defined(_WIN32_WCE)
#define YY_NO_UNISTD_H
static int isatty (void *i) { return 0; }
#endif

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "alpha_token_t.h"

#define YY_DECL int aplha_yylex (std::vector<alpha_token_t> &yylval)

unsigned long tok_count = 1lu;
unsigned int line_count = 1u;
/*
	*@brief function for handling escape characters inside strings
*/
void handle_escape_chars(std::string &str, std::string &debug){
	assert(yytext);
	str.resize(yyleng);
	int i = 0, j = 0;
	while(yytext[i] != 0){
		if(yytext[i] == '\\'){
			++i;
			switch(yytext[i]){
				case 'n':
					str.at(j) = '\n';
					break;
				case 't':
					str.at(j) = '\t';
					break;
				case 'a':
					str.at(j) = '\a';
					break;
				case '"':
					str.at(j) = '\"';
					break;
				case '\\':
					str.at(j) = '\\';
					break;
				case 'v':
					str.at(j) = '\v';
					break;
				default :
					debug.append((yytext+i-1),2);
					debug.append(", ");
					str.at(j++) = yytext[i-1];
					str.at(j) = yytext[i];
			}
		}
		else
			str.at(j) = yytext[i];
		++i;
		++j;
	}
}

%}

%option header-file="./scanner.h"
%option noyywrap
%option yylineno


keyword			if|else|while|for|function|return|break|continue|and|not|or|local|true|false|nil
operator		[=\+\-\*\/\%\>\<]|"=="|"!="|"++"|"--"|">="|"<="
integer			(0[xX][0-9A-Fa-f]+)|([0-9]+)
real			[0-9]+\.[0-9](e|E)?[0-9]*
string			\".*\"
punctuation		"::"|".."|[\{\}\[\]\(\)\;\,\:\.]
identifier		[a-zA-Z][a-zA-Z_0-9]*
slcomment		"//".*
mlcomment		"/*".*"*/"

%%

"EXIT"|"exit"	{ exit(0); }
\n				{ line_count++; }
{keyword}		{
					std::string str(yytext);
					alpha_token_t tok{
						line_count,
						tok_count++,
						str,
						"",
						KEYWORD,
					};
					yylval.push_back(tok);
					return 1;
				}
{operator}		{}
{integer}		{}
{real}			{}
{string}		{
					std::string str, debug;
					handle_escape_chars(str, debug);
					alpha_token_t tok{
						line_count,
						tok_count++,
						str,
						debug,
						STRINGCONST,
					};
					yylval.push_back(tok);
					return 1;
	}
{punctuation}	{
					std::string str(yytext);
					alpha_token_t tok{
						line_count,
						tok_count++,
						str,
						"",
						PUNCTUATION,
					};
					yylval.push_back(tok);
					return 1;
	}
{identifier}	{ 
					std::string str(yytext);
					alpha_token_t tok{
						line_count,
						tok_count++,
						str,
						"",
						IDENTIFIER,
					};
					yylval.push_back(tok);
					return 1;
				}
{slcomment}		{}
{mlcomment}		{}
.               {;}
<<EOF>>			{ std::cout << "I reached the end of file.\n";return -1; }

%%

const char* tok_types[] = {"UNDEFINED", "KEYWORD", "IDENTIFIER", "OPERATOR",
"INTCONST", "DOUBLECONST", "STRINGCONST", "PUNCTUATION",
"LINE_COMMENT", "BLOCK_COMMENT", "NESTED_COMMENT"};

std::vector<alpha_token_t> token_vector;

void print_vector(const char* tok_types[]){	
	std::cout << "------------------------- Lexical Analysis -----------------------------------------\n";
	for (auto t : token_vector){
	 	std::cout << t.tok_line << ":\t#" << t.tok_num 
		 		<< "\t" << t.tok_val << "\t" << tok_types[t.tok_type]
				<< std::endl;
		if(!t.tok_debug.empty()){
			std::cout << "\033[33m" << "WARNING-->";
			std::cout << "\033[37m";
			std::cout << "Bad escape characters --> " << t.tok_debug << std::endl;
		}
	}
}

int main(int argc, char** argv) {
	std::cout << "\033[37m"; // to change the text color to white
    if (argc > 1) {
		if (!(yyin = fopen(argv[1], "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
	} else {
		yyin = stdin;
	}

    while(aplha_yylex(token_vector) != EOF);

	print_vector(tok_types);
    return 0;
}
