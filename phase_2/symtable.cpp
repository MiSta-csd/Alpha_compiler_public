#include "symtable.h"
unsigned int scope;
unsigned int scope_MAX;
bool in_funcdef;
unsigned int nonos;



extern int yylineno;


std::vector<std::vector<st_entry> > symbol_table;

std::vector<struct st_entry*> f_arg_list;



st_entry* st_insert(std::string name, enum st_entry_type type){

    st_entry *new_entry;
    assert(new_entry = new st_entry);
 

    *new_entry = {
		true,
		name,
		type,
		(type==USER_FUNC) ? new std::vector<st_entry*> : NULL,
		scope,
		yylineno
	};

	symbol_table[scope].push_back(*new_entry);


	return new_entry;
}

std::string st_godfather(){

    std::string s = "$f_" + nonos++;
    return s;
}

void st_increase_scope(){    
    scope++;
	
    if(scope > scope_MAX){
		scope_MAX = scope;
		symbol_table.push_back(*(new std::vector<st_entry>));
	}
}

void st_decrease_scope(){
	scope--;
}

unsigned int st_get_scope(){
    
    return scope;
}

st_entry* st_lookup(std::string name_input){

	st_entry* tmp = NULL;
    
    /* check for locals first */
    if(tmp = st_lookup(name_input, st_get_scope())){
            return tmp;
    }

    /* check argList */
    for (auto arg : f_arg_list){
        if((arg->name == name_input) && (arg->active==true)){
                return arg;
            }
    }

    /* checking all current and lower scopes */
    for (int i = (static_cast<int>(st_get_scope())-1); i >= 0; i--){
        for (auto v : symbol_table[i]){
            if((v.name == name_input) && (v.active)
                && (v.type != FORMAL_ARG)){
                tmp = &v;
                return tmp;
            }
        }
    }
	
    return tmp;
}

// for local purpose
st_entry* st_lookup(std::string name_input, unsigned int scope_input){

    st_entry* tmp = NULL;

    for (auto v : symbol_table[scope_input]){
        if((v.name == name_input) && (v.active)){
            tmp = &v;
        }
    }
	return tmp;
}

int st_hide(unsigned int scope_input){

    assert(scope_input > 0);
    for (auto v : symbol_table[scope_input]){
        v.active = false;
    }

	return 0;
}

int load_2_arglist(struct st_entry* arg){

    f_arg_list.push_back(arg);

    return 0;
}


int offload_arglist(st_entry* func){
    assert(f_arg_list.size() > 0);
    std::cout << func->type <<std::endl;
    assert(func->type == USER_FUNC);
    assert(func->argList);
    *(func->argList) = f_arg_list;
    f_arg_list.clear();

    return 0;
}

void st_set_in_funcdef(bool b){
    in_funcdef = b;
}

bool st_get_in_funcdef(){
    return in_funcdef;
}

void st_initialize(){
    scope = 0;
    yylineno = 1; /* Maybe unneeded */
    scope_MAX = 0;
    nonos = 0;

    symbol_table.push_back(*(new std::vector<st_entry>));
    st_insert("print", LIB_FUNC);
	st_insert("input", LIB_FUNC);
	st_insert("objectmemberkeys", LIB_FUNC);
	st_insert("objecttotalmembers", LIB_FUNC);
	st_insert("objectcopy", LIB_FUNC);
	st_insert("totalarguments", LIB_FUNC);
	st_insert("argument", LIB_FUNC);
	st_insert("typeof", LIB_FUNC);
	st_insert("strtonum", LIB_FUNC);
	st_insert("sqrt", LIB_FUNC);
	st_insert("cos", LIB_FUNC);
	st_insert("sin", LIB_FUNC);
}

void st_print_table(){

    std::string st_type_print[] = { "global variable", "formal argument", 
    "local variable", "library function", "user function"};
    std::cout << "\n";
    int i = 0;
    for (auto v : symbol_table){
        std::cout << " -----------      scope #" << i++ 
            << "      ----------- " << std::endl;
        for (auto v2 : v){
            std::cout << "\"" << v2.name << "\" ["
            << st_type_print[v2.type] << "] "
            << "(line " << v2.line << ") (scope "
            << v2.scope << ") \n";
        }
        std::cout << std::endl;
    }
}


