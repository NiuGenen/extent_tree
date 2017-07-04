#include"extent_list.h"
#include"extent_stub.h"
#include<iostream>

using namespace std;

int ch = 0;
uint64_t blk_st = 0;
uint64_t blk_ed = 1023;
blk_addr_handle handler(ch,blk_st,blk_ed);

#define TEXT_SIZE 16

int main()
{
    ExtentList el(ch,blk_st,blk_ed,4,handler);

    struct extent_descriptor* edes[TEXT_SIZE];
    for(int i=0; i<TEXT_SIZE; ++i){
        edes[i] = el.getNewExt();
        el.display();
    }
    
    el.put( edes );
    el.put( edes +1 );
    el.put( edes +4 );
    el.put( edes +5 );
    el.display();

    el.GC();
    el.display();
}
