#define SYM_T_H
#include <iostream>
#include <vector>

enum st_entry_type {
	GLOBAL_ARG = 0,
	FORMAL_ARG,
	LOCAL_ARG,
	LIB_FUNC,
	USER_FUNC
};


struct st_entry {
	bool active;
	std::string name;
	enum st_entry_type type;
	std::vector<st_entry> argList;	// Formal Arguments list
									// in case of function
	unsigned int scope;
	unsigned long line;
} typedef st_entry;


/* TODO */ // insert, lookup, hide
// struct st_entry create_st_entry(std::string name, enum st_entry_type type){

// }
