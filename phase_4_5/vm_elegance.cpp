#include "vm_elegance.h"
#include <vector>
#include "avm_structures.h"

programVar *ProgVarSegment;
std::vector<std::string*> str_vec;
std::vector<double> num_vec;
std::vector<userfunc> userFuncs;
std::vector<std::string> libFuncs;
std::vector<instruction> instr_vec;

void decode_binary_init_vm(FILE *bin_f) {
    unsigned magic, len, num_ch;
    fread(&magic, sizeof(unsigned), 1, bin_f);
	if(magic != MAGIC_NUM){
		std::cout << "This binary file is not produced by alpha lang!\n";
		exit(1);
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

	// instructions opcode [vmarg] [vmarg] [vmarg] [srcLine]
    unsigned long instrs;
    fread(&instrs, sizeof(unsigned long), 1, bin_f);
    for(int i = 0; i < instrs; ++i) {
        enum vmopcode op;
        fread(&op, sizeof(enum vmopcode), 1, bin_f);
        vmarg tmp_arg;
        instruction tmp_instr;
        unsigned srcLine;
        tmp_instr.opcode = op;
        switch(op) {
            case ASSIGN_V:// 4 operands inc srcL
                fread(&tmp_arg, sizeof(vmarg), 1, bin_f);
                tmp_instr.result =  tmp_arg;
                fread(&tmp_arg, sizeof(vmarg), 1, bin_f);
                tmp_instr.arg1 =  tmp_arg;
                tmp_instr.arg2.val = (unsigned)-1;
                fread(&srcLine, sizeof(unsigned), 1, bin_f);
                tmp_instr.srcLine =  srcLine;
                instr_vec.push_back(tmp_instr);
                break;
            case ADD_V:// 5 operands including srcLine
            case SUB_V:
            case MUL_V:
            case DIV_V:
            case MOD_V:
            case JEQ_V:
            case JNE_V:
            case JLT_V:
            case JGT_V:
            case JLE_V:
            case JGE_V:
            case TABLEGETELEM_V:
            case TABLESETELEM_V:
                fread(&tmp_arg, sizeof(vmarg), 1, bin_f);
                tmp_instr.result =  tmp_arg;
                fread(&tmp_arg, sizeof(vmarg), 1, bin_f);
                tmp_instr.arg1 =  tmp_arg;
                fread(&tmp_arg, sizeof(vmarg), 1, bin_f);
                tmp_instr.arg2 =  tmp_arg;
                fread(&srcLine, sizeof(unsigned), 1, bin_f);
                tmp_instr.srcLine =  srcLine;
                instr_vec.push_back(tmp_instr);
                break;
            case FUNCENTER_V:
            case FUNCEXIT_V:
            case JUMP_V:
            case NEWTABLE_V:
            case CALL_V:
                fread(&tmp_arg, sizeof(vmarg), 1, bin_f);
                tmp_instr.result =  tmp_arg;
                tmp_instr.arg1.val = (unsigned)-1;
                tmp_instr.arg2.val = (unsigned)-1;
                fread(&srcLine, sizeof(unsigned), 1, bin_f);
                tmp_instr.srcLine =  srcLine;
                instr_vec.push_back(tmp_instr);
                break;
            case PUSHARG_V:
                tmp_instr.result.val = (unsigned)-1;
                fread(&tmp_arg, sizeof(vmarg), 1, bin_f);
                tmp_instr.arg1 = tmp_arg;
                tmp_instr.arg2.val = (unsigned)-1;
                fread(&srcLine, sizeof(unsigned), 1, bin_f);
                tmp_instr.srcLine =  srcLine;
                instr_vec.push_back(tmp_instr);
                break;
            default:
                assert(0);
        }
    }
    // tmp_print_instructions();
}


// void tmp_print_instructions () {// for debug
// 	std::string instrCodes[] = {"ASSIGN_V", "ADD_V", "SUB_V", "MUL_V", "DIV_V", "MOD_V", "UMINUS_V", "AND_V",
// 	"OR_V", "NOT_V", "JEQ_V", "JNE_V", "JLE_V", "JGE_V", "JLT_V", "JGT_V",
// 	"CALL_V", "PUSHARG_V", "FUNCENTER_V", "FUNCEXIT_V", "NEWTABLE_V", "TABLEGETELEM_V",
// 	"TABLESETELEM_V", "JUMP_V", "NOP_V"};
// 	std::string argCodes[] = {"LABEL_A", "GLOBAL_A", "FORMAL_A", "LOCAL_A", "NUMBER_A", "STRING_A", "BOOL_A",
// 	"NIL_A", "USERFUNC_A", "LIBFUNC_A", "RETVAL_A"};

// 	// print_file_identifiers();

// 	for (int i = 0; i < instr_vec.size(); ++i) {
// 		std::cout << i+1 << ": " << instrCodes[instr_vec[i].opcode] << " ";
// 		if(instr_vec[i].result.val != (unsigned)-1)
// 			std::cout << argCodes[instr_vec[i].result.type] << (instr_vec[i].opcode == JUMP_V?
// 						"->" + std::to_string(instr_vec[i].result.val) + " ":  " ");
// 		else
// 			std::cout << "unused_result" << " ";
// 		if(instr_vec[i].arg1.val != (unsigned)-1)
// 			std::cout << argCodes[instr_vec[i].arg1.type] << " ";
// 		else
// 			std::cout << "unused_arg1" << " ";
// 		if(instr_vec[i].arg2.val != (unsigned)-1)
// 			std::cout << argCodes[instr_vec[i].arg2.type] << " ";
// 		else
// 			std::cout << "unused_arg2" << " ";
// 		std::cout << instr_vec[i].srcLine << std::endl;
// 	}
// 	std::cout << " -----------------------------------------------\n";
// }