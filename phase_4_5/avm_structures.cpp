// #include <cstdio>
#include "avm_structures.h"

std::vector<double>			numConsts;
unsigned        			totalNumConsts = 0;
std::vector<std::string*> 	stringConsts;
unsigned        			totalStringConsts = 0;
std::vector<std::string> 	namedLibfuncs;
unsigned        			totalNamedLibfuncs = 0;
std::vector<userfunc*> 		userFuncs;
unsigned        			totalUserFuncs = 0;

unsigned consts_newstring(std::string *str) {
	stringConsts.push_back(str);
	return totalStringConsts++;
}

unsigned consts_newnumber(double n) {
	numConsts.push_back(n);
	return totalNumConsts++;
}

unsigned consts_newused(std::string str) {
	namedLibfuncs.push_back(str);
	return totalNamedLibfuncs++;
}

void make_operand(expr* e, vmarg *arg) {
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
			arg->val = e->sym->taddress;// TODO
		case LIBRARYFUNC_E:
			arg->type = LIBFUNC_A;
			arg->val = consts_newused(e->sym->name);
		default:
			assert(0);
	}
}

extern std::vector<quad> quad_vec;

std::vector<vminstruction*> instr_vec;
std::vector<incomplete_jump> inc_j_vec;

unsigned get_current_instr() {
	return instr_vec.size();
}


void generate_ASSIGN(quad* q) {// TODO check for patchings
	vminstruction *instr = new vminstruction();
	instr->opcode = ASSIGN_V;
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_ADD(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_SUB(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_MUL(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_DIV(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_MOD(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}

void generate_NOP(quad* q) {std::cout << "Entered generate_NOP\n";}

void generate_AND(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	inc_j_vec.push_back(incomplete_jump{.instrNo = 0,.iaddress = q->label});
	q->taddress = get_current_instr();
}
void generate_OR(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	inc_j_vec.push_back(incomplete_jump{.instrNo = 0,.iaddress = q->label});
	q->taddress = get_current_instr();
}
void generate_NOT(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}

void generate_IF_EQ(quad* q) {// NOTE IF_EQ is the quad generated for every assign
	vminstruction *instr = new vminstruction();
	inc_j_vec.push_back(incomplete_jump{.instrNo = 0,.iaddress = q->label});// TODO fix
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_IF_NOTEQ(quad* q) {
	vminstruction *instr = new vminstruction();
	inc_j_vec.push_back(incomplete_jump{.instrNo = 0,.iaddress = q->label});// TODO fix
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_IF_LESSEQ(quad* q) {
	vminstruction *instr = new vminstruction();
	inc_j_vec.push_back(incomplete_jump{.instrNo = 0,.iaddress = q->label});// TODO fix
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_IF_GREATEREQ(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	instr->srcLine = q->line;
	inc_j_vec.push_back(incomplete_jump{.instrNo = 0,.iaddress = q->label});// TODO fix
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_IF_LESS(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	instr->srcLine = q->line;
	inc_j_vec.push_back(incomplete_jump{.instrNo = 0,.iaddress = q->label});// TODO fix
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_IF_GREATER(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	instr->srcLine = q->line;
	inc_j_vec.push_back(incomplete_jump{.instrNo = 0,.iaddress = q->label});// TODO fix
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_CALL(quad* q) {
	vminstruction *instr = new vminstruction();


	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_PARAM(quad* q) {
	vminstruction *instr = new vminstruction();


	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_RET(quad* q) {
	vminstruction *instr = new vminstruction();


	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_GETRETVAL(quad* q) {
	vminstruction *instr = new vminstruction();

	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_FUNCSTART(quad* q) {
	vminstruction *instr = new vminstruction();


	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_FUNCEND(quad* q) {
	vminstruction *instr = new vminstruction();


	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_TABLECREATE(quad* q) {
	vminstruction *instr = new vminstruction();


	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_TABLEGETELEM(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_TABLESETELEM(quad* q) {
	vminstruction *instr = new vminstruction();
	make_operand(q->arg1, &instr->arg1);
	make_operand(q->arg2, &instr->arg2);
	make_operand(q->result, &instr->result);
	instr->srcLine = q->line;
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}
void generate_JUMP(quad* q) {
	vminstruction *instr = new vminstruction();
	instr->srcLine = q->line;
	inc_j_vec.push_back(incomplete_jump{.instrNo = 0,.iaddress = q->label});// TODO patch
	instr_vec.push_back(instr);
	q->taddress = get_current_instr();
}

generator_func_t generators[] {
	generate_ASSIGN,
	generate_ADD,
	generate_SUB,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_NOP,// UMINUS
	generate_AND,// AND
	generate_OR,// OR
	generate_NOT,// NOT
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
		// TODO den m aresei. Isws xreiastei na kanw refine to <quad> se <quad*> GTPM logw gnwstou bug apo ph3
		generators[quad_vec[i].op](&quad_vec[i]);
	}
}

void print_instructions () {// for debug
	std::string instrCodes[] = {"ASSIGN_V", "ADD_V", "SUB_V", "MUL_V", "DIV_V", "MOD_V", "UMINUS_V", "AND_V",
	"OR_V", "NOT_V", "JEQ_V", "JNE_V", "JLE_V", "JGE_V", "JLT_V", "JGT_V",
	"CALL_V", "PUSHARG_V", "FUNCENTER_V", "FUNCEXIT_V", "NEWTABLE_V", "_V", "TABLEGETELEM_V",
	"TABLESETELEM_V", "NOP_V"};
	std::string argCodes[] = {"LABEL_A", "GLOBAL_A", "FORMAL_A", "LOCAL_A", "NUMBER_A", "STRING_A", "BOOL_A",
	"NIL_A", "USERFUNC_A", "LIBFUNC_A", "RETVAL_A"};
	for (int i = 0; i < instr_vec.size(); ++i) {
		std::cout << i+1 << ": " << instrCodes[instr_vec[i]->opcode] << " ";
		if(instr_vec[i]->arg1.type)
			std::cout << argCodes[instr_vec[i]->arg1.type] << " ";
		if(instr_vec[i]->arg2.type)
			std::cout << argCodes[instr_vec[i]->arg2.type] << " ";
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
