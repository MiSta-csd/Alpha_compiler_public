#include "avm_auxiliary.h"
#include "avm_mem_structs.h"
#include <stdlib.h>
// #include <stdarg.h>

extern avm_memcell stack[AVM_STACKSIZE];
extern void memclear_table (avm_memcell* m);
extern unsigned executionFinished;

memclear_func_t memclearFuncs[] = {
    0, /*  number */
    memclear_string,
    0,
    memclear_table,
    0,
    0,
    0,
    0
};

std::string typeStrings[] = {
    "number", 
    "string", 
    "bool", 
    "table", 
    "userfunc", 
    "libfunc", 
    "nil", 
    "undef"
};

bool number_tobool (avm_memcell* m) { return m->data.numVal != 0; }
bool string_tobool (avm_memcell* m) { return !(m->data.strVal->empty()); }
bool bool_tobool (avm_memcell* m) { return m->data.boolVal; }
bool table_tobool (avm_memcell* m) { return true; }
bool userfunc_tobool (avm_memcell* m) { return true; }
bool libfunc_tobool (avm_memcell* m) { return true; }
bool nil_tobool (avm_memcell* m) { return false; }
bool undef_tobool (avm_memcell* m) { assert(0); return false; }

void memclear_string (avm_memcell* m)
{
    assert(m->data.strVal);
    delete m->data.strVal;
}

tobool_func_t toboolFuncs[] = {
    number_tobool,
    string_tobool,
    bool_tobool,
    table_tobool,
    userfunc_tobool,
    libfunc_tobool, 
    nil_tobool,
    undef_tobool
};


void avm_memcellclear (avm_memcell* m)
{
    if (m->type) // dhladh edw mas leei an to type einai != NUMBER_M hmmmmm
    {
        memclear_func_t f = memclearFuncs[m->type];// kai edw exei synarthseis mono gia string kai table vals
        if (f)
            (*f) (m);
        m->type = UNDEF_M;
    }
    
}

void avm_warning (std::string s, ...)
{
    // va_list arglist;
    // va_start(arglist, s);// to s xrhsimopoieitai gia na kserei poio einai to teleytaio arg pou 8a diavasei
    std::cout << "\033[33m" << "WARNING: " << s << "\033[37m" << std::endl;
    // avm_memcell *arg_cell;
    // while ((arg_cell = va_arg(arglist, avm_memcell*))) {
    //     std:: cout << arg_cell->type << " yo!\n";// etsi gia to gmt
    // }
    // va_end(arglist); // DJ Kostas
}

void avm_error (std::string s, ...)
{
    std::cout << "\033[31m" << "ERROR :" << s << "\033[37m" << std::endl;
    executionFinished = 1;
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

userfunc avm_get_funcVal(avm_memcell* m)
{
    assert(m);
    assert(m->type == USERFUNC_M);
    return m->data.funcVal;
}

tostring_func_t tostringFuncs[] = {
    number_tostring,
    string_tostring,
    bool_tostring,
    table_tostring,
    userfunc_tostring,
    libfunc_tostring, 
    nil_tostring,
    undef_tostring
};


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
    std::string s = "";
    std::string pcfr="";
    s + "[ ";
    if (m->data.tableVal->numIndexed->size())
    {
        for (auto x : *(m->data.tableVal->numIndexed))
        {
            s + "{ "+std::to_string(x.first)+" : "+avm_tostring(&(x.second))+" }";
        }
    }
    
    if (m->data.tableVal->strIndexed->size())
    {
        for (auto x : *(m->data.tableVal->strIndexed))
        {
            s + "{ "+x.first+" : "+avm_tostring(&(x.second))+" }";
        }
    }

    if (m->data.tableVal->funcIndexed->size())
    {
        for (auto x : *(m->data.tableVal->funcIndexed))
        {
            s + "{ f_id:"+std::to_string(x.first)+" : "+avm_tostring(&(x.second))+" }";
        }
    }

    if (m->data.tableVal->trollIndexed->size())
    {
        for (auto x : *(m->data.tableVal->trollIndexed))
        {
            s + "{ "+x.first+" : "+avm_tostring(&(x.second))+" }";
        }
    }

    s + " ]";

    return s;   
}

std::string userfunc_tostring (avm_memcell* m)
{
    assert(m && m->type == USERFUNC_M);
    return "Function: " + *(m->data.funcVal.id); /* + " | Address: " 
        + std::to_string(m->data.funcVal.address); */
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

bool avm_tobool (avm_memcell* m)
{
    assert(m->type >= 0 && m->type < UNDEF_M);
    return (*toboolFuncs[m->type]) (m);
}
