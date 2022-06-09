#include "avm_libfuncs.h"
#include "avm_auxiliary.h"

extern unsigned totalActuals;

libPair* new_libPair(char* id, library_func_t addr)
{
    libPair* new_pair;
    new_pair = (libPair*)malloc(sizeof(libPair));
    new_pair->name = id;
    new_pair->lib_function = addr;
    new_pair->next = NULL;
    return new_pair;
};

unsigned int avm_string2hash(char *key)
{
    assert(key != NULL);

    int i;
    int string_len = strlen(key);

    int g = 31;
    unsigned int hash = 0;
    for(i = 0; i < string_len; i++)
    {
        hash = g * hash + key[i];
    }

    return hash;
}

int avm_hash2index(unsigned int hash)
{
    int index;

    index = hash % AVM_TABLE_HASHSIZE;
    if(index >= AVM_TABLE_HASHSIZE)
    {
        index = avm_hash2index(index);
    }

    assert(index >= 0 && index < AVM_TABLE_HASHSIZE);

    return index;
}

int avm_hash(char *key)
{
    int hash = avm_string2hash(key);
    return avm_hash2index(hash);
}

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

void libfunc_objectmemberkeys(void)
{
    avm_memcell *actual = avm_getactual(0);
	avm_table *actual_table = actual->data.tableVal;

	if(actual->type != TABLE_M)
		avm_error("s", "Error: Expected table type argument");

	avm_memcellclear(&reg_RETVAL);
	avm_memcellclear(&reg_AX); //maybe dont do this?
	reg_RETVAL.type = TABLE_M;
	reg_RETVAL.data.tableVal = avm_tablenew();
	avm_table *ret_table = reg_RETVAL.data.tableVal;

	int i;
	reg_AX.type = NUMBER_M;
	for(i = 0; i < actual_table->total; i++){
		reg_AX.data.numVal = i;
		avm_tablesetelem(ret_table, &reg_AX, actual_table->keys[i]);
	}
}

library_func_t avm_getlibraryfunc(std::string id)
{
	assert(id);
	assert(lib_h_table);

    unsigned int index = avm_hash(id);
	assert(index < AVM_TABLE_HASHSIZE);
    libPair* iterator = lib_h_table->pairs[index];

	if(iterator == NULL)
		return NULL;

	while(iterator)
	{
		if(strcmp(iterator->name,id) == 0){
			return iterator->lib_function;
		}
		iterator = iterator->next;
	}

    return NULL;
}


void avm_calllibfunc(std::string id){
    library_func_t f = avm_getlibraryfunc(id);
    if(!f){
        avm_error("Unsupported library function %s called!", id);
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
        avm_error("Error: one argument, (not %d) expected in 'typeof'!\n", n);
    else
	{
		avm_memcellclear(&reg_RETVAL);
		reg_RETVAL.type = STRING_M;
		reg_RETVAL.data.strVal = new std::string(typeStrings[avm_getactual(0)->type]);
	}
}

void libfunc_totalarguments(void)
{
    unsigned int p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear(&reg_RETVAL);

	if(!p_topsp)
	{
		avm_error("'totalarguments' called outside a function!\n");
		reg_RETVAL.type = NIL_M;
	}
	else
	{
		reg_RETVAL.type = NUMBER_M;
		reg_RETVAL.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}

