#include "avm_libfuncs.h"
#include "avm_auxiliary.h"

extern unsigned totalActuals;

typedef void (*library_func_t)(void);


void libfunc_print (void){
    unsigned n = avm_totalactuals();

    for(unsigned i = 0; i < n; ++i)
    {
        std::string s = avm_tostring(avm_getactual(i));
        std::cout << s;
    }
}

int isNumber(const std::string& str)
{   
    bool dot = false;
    for (char const &c : str) {      
        if (c == '.' && dot == false){
            dot = true;
        }else if (std::isdigit(c) == 0){
            return 0;
        } 
    }
    if (dot){
        return 2;
    }
    return 1;
}

void handleString(std::string input){
    reg_RETVAL.type = STRING_M;
    reg_RETVAL.data.strVal = new std::string(input);
}

void libfunc_input(void)
{
    std::string input;
    std::cin >> input;
    int num;

    num = isNumber(input);

    if (input.back() == '"' && input[0] == '"'){
        handleString(input);
    }else if (num == 1 || num == 2){
        reg_RETVAL.type = NUMBER_M;
        reg_RETVAL.data.numVal = stod(input);
    }else if (input.find("true") != -1){
        reg_RETVAL.type = BOOL_M;
        reg_RETVAL.data.boolVal = 1;
    }else if(input.find("false") != -1){    /* double d std::to_string(d) */
        reg_RETVAL.type = BOOL_M;
        reg_RETVAL.data.boolVal = 0;
    }else if(input.find("nil") != -1){
        reg_RETVAL.type = NIL_M;
    }else{
        handleString(input);
    }
}

void avm_tablesetelem(avm_table *table, avm_memcell* index, avm_memcell* content);

// void libfunc_objectmemberkeys(void)
// {
//     avm_memcell *actual = avm_getactual(0);
// 	avm_table *actual_table = actual->data.tableVal;

// 	if(actual->type != table_m)
// 		avm_error("s", "Error: Expected table type argument");

// 	avm_memcellclear(&reg_RETVAL);
// 	avm_memcellclear(&ax); //maybe dont do this?
// 	retval.type = table_m;
// 	retval.data.tableVal = avm_tablenew();
// 	avm_table *ret_table = retval.data.tableVal;

// 	int i;
// 	ax.type = number_m;
// 	ax.data.numVal.type = 0;
// 	for(i = 0; i < actual_table->total_counter; i++){
// 		ax.data.numVal.intConst = i;
// 		avm_tablesetelem(ret_table, &ax, actual_table->keys[i]);
// 	}
// }


void avm_calllibfunc(char *id){
    library_func_t f = avm_getlibraryfunc(id);
    if(!f){
        avm_error("ss", "Unsupported library function %s called.", id);
        executionFinished = 1;
    }
    else{
		topsp = top;
		totalActuals = 0;
		(*f)();
		if(!executionFinished)
			execute_funcexit((instruction * )0);
    }
}

void libfunc_typeof(void)
{
    unsigned n = avm_totalactuals();

    if(n != 1)
        avm_error("sd", "Error: one argument, (not %d) expected in 'typeof'!\n", n);
    else
	{
		avm_memcellclear(&reg_RETVAL);
		reg_RETVAL.type = STRING_M;
		reg_RETVAL.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
	}
}

void libfunc_totalarguments(void)
{
    unsigned int p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear(&reg_RETVAL);

	if(!p_topsp)
	{
		avm_warning("Warning: 'totalarguments' called outside a function.\n");
		reg_RETVAL.type = NIL_M;
	}
	else
	{
		reg_RETVAL.type = NUMBER_M;
		reg_RETVAL.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}

