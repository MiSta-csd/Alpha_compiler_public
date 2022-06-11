// #include "avm_mem_structs.h"
// #include "avm_auxiliary.h"
// #include "avm_table.h"
// #include "avm_execution.h"
#include "avm_structures.h"
#include <stdio.h>
#include "vm_elegance.h"

extern programVar *ProgVarSegment;
extern std::vector<std::string*> str_vec;
extern std::vector<double> num_vec;
extern std::vector<userfunc> userFuncs;
extern std::vector<std::string> libFuncs;

int main () {
	FILE  *bin_f;
	bin_f = fopen("alpha.bin", "r");
	if(!bin_f){
		std::cout << "File alpha.bin doesn't exist.\n";
		return 1;
	}
	decode_binary_init_vm(bin_f);
	
	fclose(bin_f);
}
