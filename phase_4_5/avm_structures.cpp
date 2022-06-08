#include <unordered_map>
#include "avm_structures.h"
#include "actions.h"

std::vector<double>			numConsts;
unsigned        			totalNumConsts = 0;
std::vector<std::string> 	stringConsts;
unsigned        			totalStringConsts = 0;
std::vector<std::string> 	namedLibFuncs;
unsigned        			totalNamedLibfuncs = 0;
std::vector<userfunc*> 		userFuncs;
unsigned        			totalUserFuncs = 0;

unsigned userfuncs_newfunc (userfunc* f) {
	for(int i = 0; i < userFuncs.size(); ++i) {
		if ((userFuncs[i]->id) == f->id)
			return i;
	}
	userFuncs.push_back(f);
	return totalUserFuncs++;
}

unsigned consts_newstring(std::string *str) {
	for(int i = 0; i < stringConsts.size(); ++i) {
		if ((stringConsts[i]) == *str)
			return i;
	}
	stringConsts.push_back(*str);
	return totalStringConsts++;
}

unsigned consts_newnumber(double n) {
	for(int i = 0; i < numConsts.size(); ++i) {
		if (numConsts[i] == n)
			return i;
	}
	numConsts.push_back(n);
	return totalNumConsts++;
}

unsigned consts_newused(std::string str) {
	for(int i = 0; i < namedLibFuncs.size(); ++i) {
		if (namedLibFuncs[i] == str)
			return i;
	}
	namedLibFuncs.push_back(str);
	return totalNamedLibfuncs++;
}

void make_operand(expr* e, vmarg *arg) {
	if(!e) {
		arg->val = -1;
		return;
	}
	switch (e->type) {
		case VAR_E:
		case TABLEITEM_E:
		case ARITHEXPR_E:
		case BOOLEXPR_E:
		case NEWTABLE_E:
			arg->val = e->sym->offset;
			switch (e->sym->space) {
				case programvar:	arg->type = GLOBAL_A; break;
				case functionlocal:	arg->type = LOCAL_A; break;
				case formalarg: 	arg->type = FORMAL_A; break;
				default:
					assert(0);
			}
			break;
		/* CONSTANTS */
		case CONSTBOOL_E:
			arg->val = e->value.boolConst;
			arg->type = BOOL_A;
			break;
		case CONSTDOUBLE_E:
			arg->val = consts_newnumber(e->value.doubleConst);
			arg->type = NUMBER_A;
			break;
		case CONSTINT_E:
			arg->val = consts_newnumber((double)e->value.intConst);
			arg->type = NUMBER_A;
			break;
		case CONSTSTRING_E:
			arg->val = consts_newstring(e->value.strConst);
			arg->type = STRING_A;
			break;
		case NIL_E:
			arg->type = NIL_A;
			break;
		case PROGRAMFUNC_E:
			arg->type = USERFUNC_A;
			struct userfunc *uf;
			uf = new struct userfunc;
			uf->id = e->sym->name;
			uf->address = e->sym->iaddress + 2;
			uf->localSize = e->sym->totalLocals;// mhpws totalLocals * size of memcell
			arg->val = userfuncs_newfunc(uf);
			break;
		case LIBRARYFUNC_E:
			arg->type = LIBFUNC_A;
			arg->val = consts_newused(e->sym->name);
			break;
		default:
			assert(0);
	}
}

extern std::vector<quad> quad_vec;

std::vector<instruction*> instr_vec;

unsigned get_current_instr() {
	return instr_vec.size();
}

instruction* new_instr(quad *q, vmopcode op) {
	instruction *instr = new instruction();
	instr->opcode = op;
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	q->taddress = get_current_instr() + 1;
	return instr;
}

instruction* new_reljump(quad *q, vmopcode op) {
	instruction *instr = new_instr(q, op);
	instr->result.val = q->label;
	instr->result.type = LABEL_A;// it was anyway
	return instr;
}

void generate_ASSIGN(quad* q) {
	instr_vec.push_back(new_instr(q, ASSIGN_V));
	
}
void generate_ADD(quad* q) {
	instr_vec.push_back(new_instr(q, ADD_V));
	
}
void generate_SUB(quad* q) {
	instr_vec.push_back(new_instr(q, SUB_V));
	
}
void generate_MUL(quad* q) {
	instr_vec.push_back(new_instr(q, MUL_V));
	
}
void generate_DIV(quad* q) {
	instr_vec.push_back(new_instr(q, DIV_V));
	
}
void generate_MOD(quad* q) {
	instr_vec.push_back(new_instr(q, MOD_V));
	
}

extern expr *newexpr_constdouble(double);

void generate_UMINUS(quad* q) {// It is multiplication with -1
	instruction *instr = new_instr(q, MUL_V);
	make_operand(newexpr_constdouble(-1), &instr->arg2);
	instr_vec.push_back(instr);
}
void generate_NOP(quad* q) {std::cout << "Entered generate_NOP\n";}

// void generate_AND(quad* q) {
// 	instr_vec.push_back(new_instr(q, AND_V));

// }
// void generate_OR(quad* q) {
// 	instr_vec.push_back(new_instr(q, OR_V));

// }
// void generate_NOT(quad* q) {
// 	instr_vec.push_back(new_instr(q, NOT_V));
// 	
// } unused opcodes

void generate_IF_EQ(quad* q) {// NOTE IF_EQ is the quad generated for every assign
	instr_vec.push_back(new_reljump(q, JEQ_V));

}
void generate_IF_NOTEQ(quad* q) {
	instr_vec.push_back(new_reljump(q, JNE_V));

}
void generate_IF_LESSEQ(quad* q) {
	instr_vec.push_back(new_reljump(q, JLE_V));

}
void generate_IF_GREATEREQ(quad* q) {
	instr_vec.push_back(new_reljump(q, JGE_V));

}
void generate_IF_LESS(quad* q) {
	instr_vec.push_back(new_reljump(q, JLT_V));

}
void generate_IF_GREATER(quad* q) {
	instr_vec.push_back(new_reljump(q, JGT_V));

}
void generate_CALL(quad* q) {
	instr_vec.push_back(new_instr(q, CALL_V));

	}
void generate_PARAM(quad* q) {
	instr_vec.push_back(new_instr(q, PUSHARG_V));
	
}
static void new_ret_instr(quad* q) {
	instruction *instr = new instruction;
	instr->result.type = RETVAL_A;
	instr->opcode = ASSIGN_V;
	make_operand(q->arg2, &instr->arg2);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_RET(quad* q) {
	// TODO if q has value to be returned assign it to the appropriate register
	if(q->arg2) {
		new_ret_instr(q);
	}
}
void generate_GETRETVAL(quad* q) {
	// TODO capture the register's value and pass it somewhere.
	// Thought: pass it to a register that is for param call args if we are about to call func
	// else idk
	new_ret_instr(q);
	
}
void generate_FUNCSTART(quad* q) {
	instr_vec.push_back(new_instr(q, FUNCENTER_V));

}
void generate_FUNCEND(quad* q) {
	instr_vec.push_back(new_instr(q, FUNCEXIT_V));

}
void generate_TABLECREATE(quad* q) {
	instr_vec.push_back(new_instr(q, NEWTABLE_V));

}
void generate_TABLEGETELEM(quad* q) {
	instr_vec.push_back(new_instr(q, TABLEGETELEM_V));

}
void generate_TABLESETELEM(quad* q) {
	instr_vec.push_back(new_instr(q, TABLESETELEM_V));

}
void generate_JUMP(quad* q) {
	instr_vec.push_back(new_reljump(q, JUMP_V));
}

generator_func_t generators[] {
	generate_ASSIGN,
	generate_ADD,
	generate_SUB,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_UMINUS,
	generate_NOP,// AND , den yparxei quad and
	generate_NOP,// OR , den yparxei quad or 
	generate_NOP,// NOT , den yparxei quad not
	generate_IF_EQ,
	generate_IF_NOTEQ,
	generate_IF_LESSEQ,
	generate_IF_GREATEREQ,
	generate_IF_LESS,
	generate_IF_GREATER,
	generate_CALL,
	generate_PARAM,
	generate_RET,
	generate_GETRETVAL,
	generate_FUNCSTART,
	generate_FUNCEND,
	generate_TABLECREATE,
	generate_TABLEGETELEM,
	generate_TABLESETELEM,
	generate_JUMP
};

void generate() {
	for (unsigned i = 0; i < quad_vec.size(); ++i) {
		// TODO den m aresei. Isws xreiastei na kanw refine to <quad> se <quad*> logw gnwstou bug twn vect apo ph3
		generators[quad_vec[i].op](&quad_vec[i]);
	}
}
/*
avmbinaryfile:  magicnumber globaloffset arrays code
magicnumber:    340200501
globaloffseT: 	globaloffset
arrays:     strings numbers userfunctions libfunctions
strings:    total (string)*
total:      unsigned
string:     size (char)*
size:       unsigned
numbers:    total(double*)
userfunctions:  total(userfunc)*
userfunc:       address localsize id
address:        unsigned
localsize:      unsigned
id:             string
libfunctions:   strings
code:           total(instruction)*
instruction:    opcode operand operand operand
opcode:         byte
operand:        type value
type:           byte
value:          unsigned
*/
extern unsigned programVarOffset;
extern unsigned formalArgOffset;
extern unsigned functionLocalOffset;
extern unsigned curScopeSpace;

extern std::vector<std::unordered_map<std::string, std::vector<st_entry>>> symbol_table;
void print_file_identifiers() {
	std::string header = "avmbinaryfile: magicnumber globaloffset arrays code\n";
	unsigned magic_num = 340200501;
	unsigned globaloffset = programVarOffset;
	std::cout << header << "magic_num: " << magic_num << std::endl << "globaloffset: " <<  globaloffset << std::endl;
	for (auto map : symbol_table) {
		for ( auto pair : map) {
			for ( auto entry : pair.second) {
				if(entry.space == programvar) {
					std::cout << entry.name << "," << entry.scope << "," << entry.offset << " ";
				}
			}
		}
	}
	std::cout << "\n";
	std::cout << "string_table_size: " << totalStringConsts << std::endl;
	for(int i = 0; i < totalStringConsts; ++i) {
		std::cout <<  stringConsts[i].size() << "," << stringConsts[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "num_table_size: " << totalNumConsts << std::endl;
	for(int i = 0; i < totalNumConsts; ++i) {
		std::cout << numConsts[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "libfunc_table_size: " << totalNamedLibfuncs << std::endl;
	for(int i = 0; i < totalNamedLibfuncs; ++i) {
		std::cout << namedLibFuncs[i] << " ";// names
	}
	std::cout << std::endl;

	std::cout << "userfunc_table_size: " << totalUserFuncs << std::endl;
	for(int i = 0; i < totalUserFuncs; ++i) {
		std::cout << userFuncs[i]->id << "->" << userFuncs[i]->address << " ";
	}
	std::cout << std::endl;
	//instructions
}

#include <fstream>
void generate_binary(std::string outname) {
	std::ofstream outfile;
	outfile.open(outname, "w");
	char* magic_num = "340200501";
	outfile.write(magic_num, 10); outfile.write("\n", 1);
	outfile.write(programVarOffset, sizeof(unsigned));outfile.write("\n", 1);
	for (auto map : symbol_table) {
		for ( auto pair : map) {
			for ( auto entry : pair.second) {
				if(entry.space == programvar) {
					outfile.write(entry.name, entry.name.size());outfile.write(",", 1);
					outfile.write(entry.scope, sizeof(unsigned));outfile.write(",", 1);
					outfile.write(entry.offset, sizeof(unsigned));outfile.write(" ", 1);
				}
			}
		}
	}
	outfile.write("\n", 1);
	outfile.write(totalStringConsts, sizeof(unsigned));outfile.write("\n", 1);
	for(int i = 0; i < totalStringConsts; ++i) {
		outfile.write(stringConsts[i].size(), sizeof(unsigned));outfile.write(",", 1);
		outfile.write(stringConsts[i], stringConsts[i].size());outfile.write(" ", 1);
	}
	outfile.write("\n", 1);
	outfile.write(totalNumConsts, sizeof(unsigned));outfile.write("\n", 1);
	for(int i = 0; i < totalNumConsts; ++i) {
		outfile.write(numConsts[i], sizeof(double));outfile.write(" ", 1);
	}
	outfile.write("\n", 1);
	outfile.write(totalNamedLibfuncs, sizeof(unsigned));outfile.write("\n", 1);
	for(int i = 0; i < totalNamedLibfuncs; ++i) {
		outfile.write(namedLibFuncs[i], namedLibFuncs[i].size());outfile.write(" ", 1);// names
	}
	outfile.write(" ", 1);

	outfile.write(totalUserFuncs, sizeof(unsigned));outfile.write(" ", 1);
	for(int i = 0; i < totalUserFuncs; ++i) {
		outfile.write(userFuncs[i]->id, userFuncs[i]->id.size());outfile.write(",", 1);
		outfile.write(userFuncs[i]->address, sizeof(unsigned));outfile.write(" ", 1);
	}
	outfile.write("\n", 1);
	// instructions
	for (int i = 0; i < instr_vec.size(); ++i) {
		outfile.write(instrCodes[instr_vec[i]->opcode], sizeof(enum vmopcode));// opcode is enum
		if(instr_vec[i]->result.val != (unsigned)-1)
			std::cout << argCodes[instr_vec[i]->result.type] << (instr_vec[i]->opcode == JUMP_V?
						"->" + std::to_string(instr_vec[i]->result.val) + " ":  " ");
		else
			std::cout << "unused_result" << " ";
		if(instr_vec[i]->arg1.val != (unsigned)-1)
			std::cout << argCodes[instr_vec[i]->arg1.type] << " ";
		else
			std::cout << "unused_arg1" << " ";
		if(instr_vec[i]->arg2.val != (unsigned)-1)
			std::cout << argCodes[instr_vec[i]->arg2.type] << " ";
		else
			std::cout << "unused_arg2" << " ";
		std::cout << instr_vec[i]->srcLine << std::endl;
	}
}

void print_instructions () {// for debug
	std::string instrCodes[] = {"ASSIGN_V", "ADD_V", "SUB_V", "MUL_V", "DIV_V", "MOD_V", "UMINUS_V", "AND_V",
	"OR_V", "NOT_V", "JEQ_V", "JNE_V", "JLE_V", "JGE_V", "JLT_V", "JGT_V",
	"CALL_V", "PUSHARG_V", "FUNCENTER_V", "FUNCEXIT_V", "NEWTABLE_V", "TABLEGETELEM_V",
	"TABLESETELEM_V", "JUMP_V", "NOP_V"};
	std::string argCodes[] = {"LABEL_A", "GLOBAL_A", "FORMAL_A", "LOCAL_A", "NUMBER_A", "STRING_A", "BOOL_A",
	"NIL_A", "USERFUNC_A", "LIBFUNC_A", "RETVAL_A"};
	print_file_identifiers();
	for (int i = 0; i < instr_vec.size(); ++i) {
		std::cout << i+1 << ": " << instrCodes[instr_vec[i]->opcode] << " ";
		if(instr_vec[i]->result.val != (unsigned)-1)
			std::cout << argCodes[instr_vec[i]->result.type] << (instr_vec[i]->opcode == JUMP_V?
						"->" + std::to_string(instr_vec[i]->result.val) + " ":  " ");
		else
			std::cout << "unused_result" << " ";
		if(instr_vec[i]->arg1.val != (unsigned)-1)
			std::cout << argCodes[instr_vec[i]->arg1.type] << " ";
		else
			std::cout << "unused_arg1" << " ";
		if(instr_vec[i]->arg2.val != (unsigned)-1)
			std::cout << argCodes[instr_vec[i]->arg2.type] << " ";
		else
			std::cout << "unused_arg2" << " ";
		std::cout << instr_vec[i]->srcLine << std::endl;
	}
	std::cout << " -------------------------------------------\n";
}
// int main () {
// 	// FILE  *q_inter_f;
// 	// size_t len, read;
// 	// char *line;
// 	// q_inter_f = fopen("quads.txt", "r");
// 	// if(!q_inter_f){
// 	// 	std::cout << "File quads.txt doesn't exist .\n";
// 	// 	return 1;
// 	// }
// 	// while((read = getline(&line, &len, q_inter_f)) != EOF) {
// 	// 	line[read-1] = 0; // getting rid of newline
// 	// }
// }
