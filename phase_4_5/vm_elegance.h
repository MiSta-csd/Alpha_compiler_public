#pragma once
#include <iostream>

struct programVar {
	std::string *name;
	unsigned scope;
}typedef programVar;

void decode_binary_init_vm(FILE *bin_f);
