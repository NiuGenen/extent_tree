#include"extent_tree_stub.h"

#define extent_tree_stub_size 65536

void* ext_obj_table[ extent_tree_stub_size ];
char  ext_obj_used[  extent_tree_stub_size ];

void ext_meta_mba_init()
{
    for(int i=0;i <extent_tree_stub_size; ++i){
        ext_obj_table[i] = nullptr;
        ext_obj_used[i]  = '0';
    }
}

Ext_Nat_Entry_ID_Type ext_alloc_obj_id()
{
    for(int i=0; i<extent_tree_stub_size; ++i){
        if( ext_obj_used[i] == '0' ){
            ext_obj_used[i] = '1';
            return i;
        }
    }
    return 0;
}

void ext_dealloc_obj_id(
    Ext_Nat_Entry_ID_Type eobj_id )
{
    ext_obj_used[ eobj_id ] = '0';
}

void ext_write_by_obj_id(
    Ext_Nat_Entry_ID_Type eobj_id,
    void *eobj)
{
    if( ext_obj_used[ eobj_id ] == '1' ){
        ext_obj_table[ eobj_id ] = eobj;
    }
}

void* ext_read_by_obj_id(
    Ext_Nat_Entry_ID_Type eobj_id )
{
    if( ext_obj_used[ eobj_id ] == '1' ){
        return ext_obj_table[ eobj_id ];
    }
    return nullptr;
}