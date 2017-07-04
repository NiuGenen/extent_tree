#include<stdlib.h>
#include<iostream>

struct obj{
    int a;
    int b;
};

int main()
{
    //void* a = malloc(sizeof(struct obj));
    void*a = malloc(4096);
    struct obj* o = (struct obj*)a;
    o->a = 1;
    o->b = 2;

    std::cout<<o->a<<" "<<o->b<<std::endl;
}
