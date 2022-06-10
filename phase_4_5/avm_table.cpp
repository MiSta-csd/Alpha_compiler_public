#include "avm_table.h"
#include <assert.h>
#include <unordered_map>

avm_table::avm_table ()
{
	this->strIndexed = new std::unordered_map<avm_memcell,avm_memcell>();
	this->numIndexed = new std::unordered_map<avm_memcell,avm_memcell>();
	this->funcIndexed = new std::unordered_map<avm_memcell,avm_memcell>();
    this->trollIndexed = new std::unordered_map<avm_memcell,avm_memcell>();
    this->avm_table_elem_count();
}

avm_table::~avm_table () 
{
    delete this->strIndexed;
    delete this->numIndexed;
    delete this->funcIndexed; 
    delete this->trollIndexed;
} 

void avm_tableincrefcounter (avm_table* t) {
    ++t->refCounter;
}

void avm_tabledecrefcounter (avm_table* t) {
    assert(t->refCounter > 0);
    if(!--t->refCounter)
        avm_tabledestroy(t);
}


avm_table*      avm_tablenew (void) {
    avm_table* t = new avm_table();
    t->refCounter = 0; /* total becomes set inside ctor */   
    // AVM_WIPEOUT(*t);
    // I think it's unneeded now!
    return t;
}


void            avm_tabledestroy (avm_table* t)
{
    t->~avm_table();
    
}

unsigned avm_table::avm_table_elem_count()
{
    unsigned res = this->strIndexed->size() + this->numIndexed->size() +
                this->funcIndexed->size() + this->trollIndexed->size();
    this->total = res;
    return res;
}

avm_memcell*    avm_tablegetelem (
                                    avm_table* table,
                                    avm_memcell* index
                                 )
{
    assert(table && index);

    switch (index->type)
    {
        case NUMBER_M:
        {
            return &(table->numIndexed->at(*index));// isodynamo fainetai
            break;                                    
        }
        case STRING_M:          
        {
            /* code */;
            break;
        }
        case USERFUNC_M:
        {
            /* code */;
            break;
        }
        case BOOL_M:
        {
            /* code */;
            break;
        }
        case LIBFUNC_M:
        {
            /* code */;
        }
        case NIL_M:
        {
            /* code */;
            break;
        }
        case UNDEF_M:
        {
            avm_error("Element cannot be cannot have UNDEF type!");
            break;
        }

        default:
            break;
    }
}

void            avm_tablesetelem (
                                    avm_table*  table,
                                    avm_memcell* index,
                                    avm_memcell* content
                                 );
