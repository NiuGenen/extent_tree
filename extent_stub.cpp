#include"extent_tree_stub.h"
#include <stdlib.h>

#define extent_tree_stub_size   65536
#define extent_node_size        4096

void* ext_obj_table[ extent_tree_stub_size ]; // [0] not use
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
            ext_obj_table[i] = (void* )malloc( extent_node_size );
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
    if( eobj_id > 0 && ext_obj_used[ eobj_id ] == '1' ){
        ext_obj_table[ eobj_id ] = eobj;
    }
}

void* ext_read_by_obj_id(
    Ext_Nat_Entry_ID_Type eobj_id )
{
    if( eobj_id > 0 && ext_obj_used[ eobj_id ] == '1' ){
        return ext_obj_table[ eobj_id ];
    }
    return nullptr;
}



blk_addr_handle::blk_addr_handle(
    int ch, uint64_t blk_st, uint64_t blk_ed
)
{
    this.ch = ch;
    this.blk_st = blk_st;
    this.blk_ed = blk_ed;
}

int blk_addr_handle::GetBlkNr(){
    return blk_st - blk_ed;
}

void blk_addr_handle::BlkAddrAdd(int x, uint64_t* addr)
{
    *addr += x;
}

void blk_addr_handle::BlkAddrSub(int x, uint64_t* addr)
{
    *addr -= x;
    if(*addr < 0) *addr = 0;
}

int blk_addr_handle::BlkAddrCmp(
    uint64_t* laddr,
    uint64_t* raddr)
{
    if( *laddr == *raddr ){
        return 0;
    }
    if( *laddr < *raddr ){
        return -1;
    }
    return 1;
}
