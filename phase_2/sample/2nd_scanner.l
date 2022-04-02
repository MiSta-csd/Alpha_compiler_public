%{
#if defined(WIN32)
#define YY_NO_UNISTD_H
static int isatty (int i) { return 0; }
#elif defined(_WIN32_WCE)
#define YY_NO_UNISTD_H
static int isatty (void *i) { return 0; }
#endif

#include "symbolTable.h"
#include "parser.h"
#include "scanner_func.h"

typedef struct two_ints
{
	int start;
	int end;
}two_ints;

int count_nested_comments(two_ints **linenos);
int convert_escaped_chars(char **converted);


%}

%option header-file="./scanner.h"
%option noyywrap
%option yylineno


integer			(0[xX][0-9A-Fa-f]+)|([0-9]+)
real			[0-9]+\.[0-9](e|E)?[0-9]*
string			\"([^\"]|([^\"\\]\\(\\\\)*\"))*\"
space			[\r\n \t\v]
identifier		[a-zA-Z][a-zA-Z_0-9]*
slcomment		"//".*
mlcomment		"/*"

%%

\n				{ line_count++; }
{space}			{ ; }

{integer}		{ yylval.intVal = atoi(yytext); return INTEGER; }
{real}			{ yylval.realVal = atof(yytext); return REAL; }

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
"="			{ return EQUAL; }
"+"			{ return PLUS; }
"-"			{ return MINUS; }
"*"			{ return MULT; }
"/"			{ return DIVIDE; }
"%"			{ return PERCENT; }
"=="		{ return EQUALEQUAL; }
"!="		{ return NOTEQUAL; }
"++"		{ return PLUSPLUS; }
"--"		{ return MINUSMINUS; }
">"			{ return GREATER; } // or LCHEVRON?
"<"			{ return LESSER; } // or RCHEVRON?
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

{identifier}	{ yylval.charVal = strdup(yytext); return ID; }
{string}		{	char *converted;
					if(convert_escaped_chars(&converted)==0){
						fprintf(stderr, "Invalid escaped charachter inside string: %s"
							" at line: %d\n", yytext, yylineno);	
					}
					yylval.charVal = converted; return STRING; }

{slcomment}		{ ; }
{mlcomment}		{	int i;
					int number_of_comments;
					two_ints *lines;
					int old_lineno = yylineno;
					if((number_of_comments = count_nested_comments(&lines))==-1)
					{
						fprintf(stderr, "Invalid sequence of multiline comments at line: %d\n", old_lineno);
						exit(-1);
					}
				}

.				{ 	fprintf(stderr, "Unmatchable token: %s, at line: %d\n", yytext, yylineno);
					exit(-1); }
<<EOF>>			{ return 0; }

%%


int count_nested_comments(two_ints **linenos)
{
	int c,i;
	int count_starts=1;
	int count_ends=0;
	int comment_state=0;
	two_ints *line_map= (two_ints *)malloc(sizeof(struct two_ints));
	
	line_map->start = yylineno; line_map->end = 0;
	while((c=input()) > 0)//gia kapoio paraouro logo den taresei to EOF
	{
		if(comment_state==0)
		{	
			if(c=='/')
				comment_state=1;
			else if(c=='*')
				comment_state=2;
		}
		else if(comment_state==1)
		{
			if(c=='*')
			{
				count_starts++;
				line_map = (two_ints *)realloc(line_map,
					sizeof(struct two_ints)*count_starts);
				line_map[count_starts-1].start = yylineno; 
				line_map[count_starts-1].end = 0;
			}
			if(c!='/')
				comment_state=0;
		}
		else if(comment_state==2)
		{
			if(c=='/')
			{
				count_ends++;
				for(i=count_starts;i>0;i--)
				{
					if(line_map[i-1].end==0)
					{
						line_map[i-1].end = yylineno;
						break;
					}
				}
				if(count_ends==count_starts)
				{
					*linenos=line_map;
					return count_starts;
				}

			}
			comment_state = c=='*' ? 2 : 0;
		}
	}
	return -1;
}

int convert_escaped_chars(char **converted)
{
	int i,ci,gut=1;
	int string_state = 0;
	char *converted_string;
	char *yytext2 = strdup(yytext);
	converted_string = (char *)malloc(sizeof(char)*(yyleng+1));

	for(i=0,ci=0;i<=yyleng;i++)
	{
		if(string_state==0)
		{
			if(yytext2[i]=='\\')
				string_state = 1;
			else
				converted_string[ci++]=yytext2[i];
		}
		else if(string_state==1)
		{
			if(yytext2[i]=='\\')
				converted_string[ci++]='\\';
			else if(yytext2[i]=='n')
				converted_string[ci++]='\n';
			else if(yytext2[i]=='t')
				converted_string[ci++]='\t';
			else if(yytext2[i]=='\"')
				converted_string[ci++]='\"'; 
			else
			{
				converted_string[ci++]='\\';
				converted_string[ci++]=yytext2[i];
				gut =0;
			}
			string_state=0;
		}
	}
	*converted= converted_string;
	return gut;
}

/*
{real}			{ create_token(yylval, 4, yytext, 0); return 1; }
{string}		{	char *converted;
					int d = 0;
					if(convert_escaped_chars(&converted)==0)
						d=2;	
					create_token(yylval, 5, converted, d); return 1;
				}
{puncuation}	{ create_token(yylval, 6, yytext, 0); return 1; }

{identifier}	{ create_token(yylval, 1, yytext, 0); return 1; }
{slcomment}		{ create_token(yylval, 7, yytext, 0); return 1; }
{mlcomment}		{	int i, comment_type = 8;
					int number_of_comments;
					two_ints *lines;
					int old_lineno = yylineno;
					if((number_of_comments = count_nested_comments(&lines))==-1)
					{
						fprintf(stderr, "Invalid sequence of multiline comments at line: %d\n", old_lineno);
						return -1;
					}
					char val[20]; 
					alpha_token_t *prev=NULL;
					alpha_token_t *curr= NULL;
					alpha_token_t *start= NULL;
					for(i=0;i<number_of_comments;i++)
					{
						sprintf(val, "%d - %d", lines[i].start, lines[i].end);
						create_token(yylval, comment_type, val, 0);
						curr=(alpha_token_t *)malloc(sizeof(struct alpha_token_t));
						*curr=*((alpha_token_t *)yylval);
						curr->tok_val = strdup(val);
						curr->tok_line = lines[i].start;
						if(i>0)
							prev->next = curr;
						else
							start = curr;
						prev=curr;
						comment_type = 9;
					}
					(*(alpha_token_t *)yylval) = *start;
					free(lines);
					return 1;

				}
				*/