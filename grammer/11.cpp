/*2022年11月4日21:23:39
动态分配内存——new和delete的使用*/
#include <iostream>

using namespace std;

typedef struct person{
    char name[10];
    int old;
}person;
int main (void)
{
    //使用new来分配内存
    int *pi=new int ;//此时new给pi分配了一个int类型数据的内存空间
    int *ptari= new int [10];
    //使用delete来释放内存
    delete pi;
    delete []ptari;//这里的方括号告诉delete，应该释放整个数组，而不仅仅是释放指针所指向的元素：ptari[0]
    //这将释放他们指向的内存，但是这不会删除这两个指针本身
    //注意：
    //1.不能释放已经释放过的内存块
    //2.不能释放声明变量获得的内存
    //3.只能用delete释放new分配的内存，但是对空指针使用delete是安全的，并且new必须和delete配对使用
    //4.一般来说不要创建两个指向同一个内存块的指针，因为这可能导致你释放同一个内存块两次
    //5.你不能使用sizeof来确定动态分配的数组包含的字节数
    //6.对于动态数组，直接可以把指针当成数组名来使用，但要注意，指针名是变量，数组名是常量
    //7.对数组名使用sizeof操作符得到的是数组的长度，而对指针名使用sizeof得到的是指针占用的字节数

    //new也可以创建动态结构
    person *ptp=new person;
}