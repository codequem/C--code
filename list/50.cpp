#include <stdlib.h>
struct foo{
    int (*fun) (struct foo * this,int a,int b);
}

void func()
{
    int a=0,b=0;
    struct foo *ptf;
    ptf=(foo*)malloc(sizeof(foo));
    ptf->fun(ptf,a,b);//这不就像是成员函数调用一样
}
