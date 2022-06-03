#include "alpha_ph4_generate.h"
#include <cstdio>

extern std::vector<quad> quad_vec;

unsigned instr_counter = 0;

void generate_ASSIGN(quad* q) { q->taddress = ++instr_counter;}
void generate_ADD(quad* q) { q->taddress = ++instr_counter;}
void generate_SUB(quad* q) { q->taddress = ++instr_counter;}
void generate_MUL(quad* q) { q->taddress = ++instr_counter;}
void generate_DIV(quad* q) { q->taddress = ++instr_counter;}
void generate_MOD(quad* q) { q->taddress = ++instr_counter;}
void generate_NOP(quad* q) { q->taddress = ++instr_counter;}
void generate_AND(quad* q) { q->taddress = ++instr_counter;}
void generate_OR(quad* q) { q->taddress = ++instr_counter;}
void generate_NOT(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_EQ(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_NOTEQ(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_LESSEQ(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_GREATEREQ(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_LESS(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_GREATER(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_CALL(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_PARAM(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_RET(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_GETRETVAL(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_FUNCSTART(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_FUNCEND(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_TABLECREATE(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_TABLEGETELEM(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_TABLESETELEM(quad* q) { q->taddress = ++instr_counter;}
void generate_IF_JUMP(quad* q) { q->taddress = ++instr_counter;}

generator_func_t generators[] {
	generate_ASSIGN,
	generate_ADD,
	generate_SUB,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_NOP,
	generate_AND,
	generate_OR,
	generate_NOT,
	generate_IF_EQ,
	generate_IF_NOTEQ,
	generate_IF_LESSEQ,
	generate_IF_GREATEREQ,
	generate_IF_LESS,
	generate_IF_GREATER,
	generate_IF_CALL,
	generate_IF_PARAM,
	generate_IF_RET,
	generate_IF_GETRETVAL,
	generate_IF_FUNCSTART,
	generate_IF_FUNCEND,
	generate_IF_TABLECREATE,
	generate_IF_TABLEGETELEM,
	generate_IF_TABLESETELEM,
	generate_IF_JUMP
};

void generate() {
	for (unsigned i = 0; i < quad_vec.size(); ++i) {
		// TODO den m aresei. Isws xreiastei na kanw refine to <quad> se <quad*> GTPM logw gnwstou bug apo ph3
		generators[quad_vec[i].op](&quad_vec[i]);
	}
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
