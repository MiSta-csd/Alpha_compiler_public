#pragma once
#include "quads.h"

std::string exp_type_to_string(expr*);

bool check_arith (expr* e, std::string context);

expr* expr_compare_expr(expr *arg1, enum iopcode opcode, expr *arg2);

expr* expr_action_expr(expr *arg1, enum iopcode opcode, expr *arg2, std::string context);

void backpatch(std::vector<int>*, unsigned label);

void patchlabel (unsigned quadNo, unsigned label);

std::vector<int>* merge(std::vector<int>* list1, std::vector<int>* list2);

expr* true_test(expr*);

expr * lvalue_expr (st_entry *sym);

expr * newexpr (expr_t t);

expr * newexpr_conststring (std::string *s);

expr * newexpr_constbool (bool);

expr * newexpr_constint (int);

expr *newexpr_constdouble(double);

expr * emit_iftableitem (expr *e);

expr* emit_branch_assign_quads(expr *ex);

expr * emit_ifbool(expr *operand);

expr * member_item (expr* lv, std::string *name);

expr * make_call (expr* lv, std::vector<expr*> *exp_vec);

void resettemp();

std::string newtempname();

st_entry* newtemp();

bool istempname (std::string s);

bool istempexpr (expr* e);
