#pragma once
#include <unordered_map>
#include "avm_mem_structs.h"

avm_table*      avm_tablenew (void);
void            avm_tabledestroy (avm_table* t);
avm_memcell*    avm_tablegetelem (avm_memcell* key);
void            avm_tablesetelem (avm_memcell* key, avm_memcell* value);

/* typedef struct avm_table_bucket {
    avm_memcell         key;
    avm_memcell         value;
    avm_table_bucket*   next;
}; // Savvidis impl */

#define AVM_TABLE_HASHSIZE 211

typedef struct avm_table {
    unsigned                        refCounter;
    /* no pointers! */
    std::unordered_map<std::string,
    avm_memcell>                    *strIndexed;
    std::unordered_map<int,
    avm_memcell>                    *numIndexed;
    std::unordered_map<avm_memcell (*)(...),
    avm_memcell>                    *funcIndexed;
    std::unordered_map<avm_memcell,
    avm_memcell>                    *trollIndexed; /* allows keys of type : libfunc, bool, nil */
    unsigned        total; /* = strIndexed.size() + numIndexed.size() + */
                        /* funcIndexed.size() + trollIndexed.size(); */  /* total no of elems */
	avm_table();
} avm_table;

void            avm_tableincrefcounter (avm_table* t);
void            avm_tabledecrefcounter (avm_table* t);
/* void            avm_tablebucketsinit (avm_table_bucket** p); // Savvidis impl */
