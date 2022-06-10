#include "avm_table.h"
#include "avm_mem_structs.h"
#include <assert.h>
#include <string>
#include <unordered_map>

avm_table::avm_table ()
{
    this->strIndexed = new std::unordered_map<std::string,avm_memcell>;
    this->numIndexed = new std::unordered_map<double,avm_memcell>;
    this->funcIndexed = new std::unordered_map<unsigned,avm_memcell>;
    this->trollIndexed = new std::unordered_map<std::string,avm_memcell>;
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
            std::unordered_map<double,avm_memcell>::const_iterator got =
                table->numIndexed->find (index->data.numVal);
            if (got == table->numIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->numIndexed->at(index->data.numVal));// isodynamo fainetai                                    
            // to allaksa se key double kai paizei profanws                                 
        }
        case STRING_M:          
        {
            std::unordered_map<std::string,avm_memcell>::const_iterator got =
                table->strIndexed->find (*(index->data.strVal));
            if (got == table->strIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->strIndexed->at((*(index->data.strVal))));
        }
        case USERFUNC_M:
        {
            std::unordered_map<unsigned,avm_memcell>::const_iterator got =
                table->funcIndexed->find (index->data.funcVal.address);
            if (got == table->funcIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->funcIndexed->at(index->data.funcVal.address));  
        }
        case BOOL_M:
        {
            bool b = index->data.boolVal;
            std::string s = (b) ? "true" : "false";
            
            std::unordered_map<std::string,avm_memcell>::const_iterator got =
                table->trollIndexed->find (s);
            if (got == table->trollIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->trollIndexed->at(s));   
        }
        case LIBFUNC_M:
        {
            std::unordered_map<std::string,avm_memcell>::const_iterator got =
                table->trollIndexed->find (*(index->data.libfuncVal));
            if (got == table->trollIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->trollIndexed->at((*(index->data.libfuncVal))));
        }
        case NIL_M:
        {
            std::string s = "nil";
            
            std::unordered_map<std::string,avm_memcell>::const_iterator got =
                table->trollIndexed->find (s);
            if (got == table->trollIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->trollIndexed->at(s));   
        }
        case UNDEF_M:
        {
            avm_error("Element cannot be cannot have UNDEF type!");
            return new avm_memcell();   // Added to pacify compiler :/
            break;
        }

        default:
            assert(0);
            return new avm_memcell(); // Added to pacify compiler :/
            break;
    }
}

/* void            avm_tablesetelem (
                                    avm_table*  table,
                                    avm_memcell* index,
                                    avm_memcell* content
                                 )
{
    assert(table && index);

    switch (index->type)
    {
        case NUMBER_M:
        {
            std::unordered_map<double,avm_memcell>::const_iterator got =
                table->numIndexed->find (index->data.numVal);
            if (got == table->numIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->numIndexed->at(index->data.numVal));// isodynamo fainetai                                    
            // to allaksa se key double kai paizei profanws                                 
        }
        case STRING_M:          
        {
            std::unordered_map<std::string,avm_memcell>::const_iterator got =
                table->strIndexed->find (*(index->data.strVal));
            if (got == table->strIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->strIndexed->at((*(index->data.strVal))));
        }
        case USERFUNC_M:
        {
            std::unordered_map<unsigned,avm_memcell>::const_iterator got =
                table->funcIndexed->find (index->data.funcVal.address);
            if (got == table->funcIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->funcIndexed->at(index->data.funcVal.address));  
        }
        case BOOL_M:
        {
            bool b = index->data.boolVal;
            std::string s = (b) ? "true" : "false";
            
            std::unordered_map<std::string,avm_memcell>::const_iterator got =
                table->trollIndexed->find (s);
            if (got == table->trollIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->trollIndexed->at(s));   
        }
        case LIBFUNC_M:
        {
            std::unordered_map<std::string,avm_memcell>::const_iterator got =
                table->trollIndexed->find (*(index->data.libfuncVal));
            if (got == table->trollIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->trollIndexed->at((*(index->data.libfuncVal))));
        }
        case NIL_M:
        {
            std::string s = "nil";
            
            std::unordered_map<std::string,avm_memcell>::const_iterator got =
                table->trollIndexed->find (s);
            if (got == table->trollIndexed->end())
            {
                return new avm_memcell();
            }
            else
            return &(table->trollIndexed->at(s));   
        }
        case UNDEF_M:
        {
            avm_error("Element cannot be cannot have UNDEF type!");
            return new avm_memcell();   // Added to pacify compiler :/
            break;
        }

        default:
            assert(0);
            return new avm_memcell(); // Added to pacify compiler :/
            break;
    }
}
 */