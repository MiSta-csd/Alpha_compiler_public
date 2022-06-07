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

void avm_warning (std::string s)
{

    std::cout << "\033[33m" << "WARNING: " << s << "\033[37m" << std::endl;
}

void avm_error (std::string s)
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

std::string bool_tostring (avm_memcell* m);
std::string table_tostring (avm_memcell* m);
std::string userfunc_tostring (avm_memcell* m);
std::string libfunc_tostring (avm_memcell* m);
std::string nil_tostring (avm_memcell* m);
std::string undef_tostring (avm_memcell* m);
