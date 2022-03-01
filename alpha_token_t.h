#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>

enum token_t_enum {
	UNDEFINED       =0,
    KEYWORD         =1,
	IDENTIFIER      =2,
	OPERATOR        =3,
	INTCONST        =4,
	DOUBLECONST     =5,
	STRINGCONST     =6,
	PUNCTUATION     =7,
	LINE_COMMENT    =8,
	BLOCK_COMMENT   =9,
	NESTED_COMMENT  =10
};


typedef struct alpha_token_t {
	unsigned tok_line;
	unsigned long tok_num;
	std::string tok_val;
	std::string tok_debug; /* added to print various useful messages */
		/* 	0 -> All is fine
			1 -> ?
			2 -> "Invalid escaped charachter detected"
		*/
	enum token_t_enum tok_type;
} alpha_token_t;
