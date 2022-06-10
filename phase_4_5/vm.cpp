// #include "avm_mem_structs.h"
// #include "avm_auxiliary.h"
// #include "avm_table.h"
// #include "avm_execution.h"
#include "avm_structures.h"
#include <stdio.h>

// TODO experimenting. Might delete
struct programVar {
	std::string *name;
	unsigned scope;
	// unsigned offset;
}typedef programVar;

programVar *ProgVarSegment;
std::vector<std::string*> str_vec;
std::vector<double> num_vec;
std::vector<userfunc> userFuncs;
std::vector<std::string> libFuncs;

int main () {
	FILE  *bin_f;
	unsigned magic, len, num_ch;
	bin_f = fopen("alpha.bin", "r");
	if(!bin_f){
		std::cout << "File alpha.bin doesn't exist.\n";
		return 1;
	}
	fread(&magic, sizeof(unsigned), 1, bin_f);
	if(magic != MAGIC_NUM){
		std::cout << "This binary file is not produced by alpha lang!\n";
		return 1;
	}
	std::cout << magic << std::endl;
	
	fread(&len, sizeof(unsigned), 1, bin_f);// progVar len
	std::cout << len << std::endl;
	ProgVarSegment = (programVar*) malloc(len*sizeof(programVar));
	for(int i = 0; i < len; ++i) {// ProgVars
		unsigned name_sz, scope, offset;
		char name_buf[256]; // megalytera onomata apo 256? tou pousth!
		fread(&name_sz, sizeof(unsigned), 1, bin_f);
		
		fread(name_buf, name_sz, 1, bin_f);
		name_buf[name_sz] = 0;
		fread(&scope, sizeof(unsigned), 1, bin_f);
		fread(&offset, sizeof(unsigned), 1, bin_f);
		ProgVarSegment[offset].name = new std::string(name_buf);
		ProgVarSegment[offset].scope = scope;
		std::cout << name_sz << "," << *ProgVarSegment[offset].name <<","<<ProgVarSegment[offset].scope<<" ";
	}
	std::cout << std::endl;
	fread(&len, sizeof(unsigned), 1, bin_f);// constStr len
	std::cout << len << std::endl;
	for(int i = 0; i < len; ++i) {// strings
		unsigned str_size;
		fread(&str_size, sizeof(unsigned), 1, bin_f);
		std::string *tmp_str = new std::string;
		tmp_str->resize(str_size);
		for (int j = 0; j < str_size; ++j) {
			char c;
			fread(&c, 1, 1, bin_f);
			tmp_str->at(j) = c;
		}// TODO check case where string is ""
		str_vec.push_back(tmp_str);
		std::cout << str_size << "," << *str_vec.back() << " ";
	}
	fread(&len, sizeof(unsigned), 1, bin_f);// constNum len
	std::cout << std::endl << len << std::endl;
	for(int i = 0; i < len; ++i) {
		double n;
		fread(&n, sizeof(double), 1, bin_f);
		num_vec.push_back(n);
		std::cout << num_vec.back() << " ";
	}
	fread(&len, sizeof(unsigned), 1, bin_f);// libFuncs len
	std::cout << std::endl << len << std::endl;
	for(int i = 0; i < len; ++i) {
		unsigned name_len;
		fread(&name_len, sizeof(unsigned), 1, bin_f);
		char buffer[64];// libf names are known and are short
		fread(&buffer, name_len, 1, bin_f);
		buffer[name_len] = 0;
		libFuncs.push_back(std::string(buffer));
		std::cout << libFuncs.back() << " ";
	}
	fread(&len, sizeof(unsigned), 1, bin_f);// UserFuncs len
	std::cout << std::endl << len << std::endl;
	for(int i = 0; i < len; ++i) {
		unsigned name_len, address, local_size, arg_size;
		fread(&name_len, sizeof(unsigned), 1, bin_f);
		std::string *tmp_str = new std::string;
		tmp_str->resize(name_len);
		for(int j = 0; j < name_len; ++j) {
			char c;
			fread(&c, 1, 1, bin_f);
			tmp_str->at(j) = c;
		}
		fread(&address, sizeof(unsigned), 1, bin_f);
		fread(&local_size, sizeof(unsigned), 1, bin_f);
		fread(&arg_size, sizeof(unsigned), 1, bin_f);
		userFuncs.push_back( userfunc{ address,
			local_size,
			arg_size,
			tmp_str});
	std::cout << name_len << "," << *(userFuncs[i].id) << ","
	<< userFuncs[i].address << "," << userFuncs[i].localSize << "," << userFuncs[i].argSize << " ";
	}
	std::cout << std::endl;
	// instructions
	fclose(bin_f);
}
