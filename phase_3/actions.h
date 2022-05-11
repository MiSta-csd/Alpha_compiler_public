#pragma once
#include "quads.h"

std::string exp_type_to_string(expr*);

bool check_arith (expr* e, std::string context);

expr* expr_compare_expr(expr *arg1, enum iopcode opcode, expr *arg2);

expr* expr_action_expr(expr *arg1, enum iopcode opcode, expr *arg2, std::string context);

void emit_branch_quads();

void backpatch(std::vector<quad*>*, unsigned label);

std::vector<quad*>* merge(std::vector<quad*>* list1, std::vector<quad*>* list2);

expr* true_test(expr*);
