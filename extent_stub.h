#ifndef _EXTENT_TREE_STUB_H_
#define _EXTENT_TREE_STUB_H_

#include "extent_tree.h"

void ext_meta_mba_init();

Ext_Nat_Entry_ID_Type ext_alloc_obj_id( );

void ext_dealloc_obj_id(
    Ext_Nat_Entry_ID_Type eobj_id );

void ext_write_by_obj_id(
    Ext_Nat_Entry_ID_Type eobj_id,
    void *eobj);

void* ext_read_by_obj_id(
    Ext_Nat_Entry_ID_Type eobj_id );

class blk_addr_handle{
public:
    blk_addr_handle(
        int ch,
        uint64_t blk_st, unit64_t blk_ed);
    int GetBlkNr();
    void BlkAddrAdd(int x, uint64_t* addr);
    void BlkAddrSub(int x, uint64_t* addr);
    int BlkAddrCmp(
        uint64_t* laddr,
        uint64_t* raddr);
private:
    int ch;
    uint64_t blk_st;
    uint64_t blk_ed;
}

#endif