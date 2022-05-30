#include "avm_table.h"
#include <assert.h>
#include <unordered_map>

avm_table::avm_table () {
	strIndexed = NULL;
	numIndexed = NULL;
	funcIndexed = NULL;
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
    avm_table* t = new avm_table;   /* TODO !!!! */
    AVM_WIPEOUT(*t);

    //t->funcIndexed = new std::unordered_map<avm_memcell, avm_memcell>;

    return t;
}


void            avm_tabledestroy (avm_table* t);
avm_memcell*    avm_tablegetelem (avm_memcell* key);
void            avm_tablesetelem (avm_memcell* key, avm_memcell* value);
