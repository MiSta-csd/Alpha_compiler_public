#include "avm_auxiliary.h"
#include <stdlib.h>



void memclear_string (avm_memcell* m)
{
    assert(m->data.strVal);
    delete m->data.strVal;
}


void memclear_table (avm_memcell* m)
{
    assert(m->data.tableVal);
    avm_tabledecrefcounter(m->data.tableVal);
}


void avm_memcellclear (avm_memcell* m)
{
    if (m->type)
    {
        memclear_func_t f = memclearFuncs[m->type];
        if (f)
            (*f) (m);
        m->type = UNDEF_M;
    }
    
}

void avm_warning (std::string s, ...)
{

    std::cout << "\033[33m" << "WARNING: " << s << "\033[37m" << std::endl;
}

void avm_error (std::string s, ...)
{
    std::cout << "\033[31m" << "ERROR :" << s << "\033[37m" << std::endl;
}

/* Memcell data extraction */

double avm_get_numVal(avm_memcell* m)
{
    assert(m);
    assert(m->type == NUMBER_M);
    return m->data.numVal; 
}

std::string avm_get_stringVal(avm_memcell* m)
{
    assert(m);
    assert(m->type == STRING_M);
    std::string s;
    s = *(m->data.strVal);
    return s;
}

bool avm_get_boolVal(avm_memcell* m)
{
    assert(m);
    assert(m->type == BOOL_M);
    return m->data.boolVal;
}

/* avm_table* avm_get_tableVal(avm_memcell* m)
{
        // TODO or uneeded
} */


userfunc avm_get_funcVal(avm_memcell* m)
{
    assert(m);
    assert(m->type == USERFUNC_M);
    return m->data.funcVal;
}


/* String Convertors */

std::string avm_tostring (avm_memcell* m){
    assert(m->type >= 0 && m->type <= UNDEF_M);
    return (*tostringFuncs[m->type]) (m);
}


std::string number_tostring (avm_memcell* m)
{
    assert(m && m->type == NUMBER_M);
    double d = avm_get_numVal(m);
    return std::to_string(d);
}

std::string string_tostring (avm_memcell* m)
{
    assert(m && m->type == STRING_M);
    std::string s = avm_tostring(m);
    return s;
}

std::string bool_tostring (avm_memcell* m)
{
    assert(m && m->type == BOOL_M);
    bool b = avm_get_boolVal(m);
    if(b)   /* std::to_string(b) -> prints 1 or 0 */
        return "true";
    else
        return "false";
}

std::string table_tostring (avm_memcell* m)
{
    assert(m && m->type == TABLE_M);
    return "I am a table.";
    /* TODO */
}

std::string userfunc_tostring (avm_memcell* m)

{
    assert(m && m->type == USERFUNC_M);
    return "Function: " + m->data.funcVal.id;
    /* May need to elaborate. */
}


std::string libfunc_tostring (avm_memcell* m)
{
    assert(m && m->type == LIBFUNC_M);
    return *(new std::string(*(m->data.libfuncVal)));
}

std::string nil_tostring (avm_memcell* m)
{
    assert(m && m->type == NIL_M);
    return "nil";
}

std::string undef_tostring (avm_memcell* m)
{
    assert(m && m->type == UNDEF_M);
    return "undef";
}

userfunc* avm_get_funcinfo (unsigned address)
{       
    
    assert(stack[address].type == USERFUNC_M ||
           stack[address].type == LIBFUNC_M
           );

    return &(stack[address].data.funcVal);

}