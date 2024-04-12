/*2023年1月7日11:15:21
链表的数组模拟实现*/
//tmd不写了，就是评价是不如stl
#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

int main (void)
{
    int data[100]={0,1,2,3,4,5,6};
    int posi[100]={1,2,3,4,5,6};//posi[i]存储了data[i]后面一个元素的数组下标
    //这里演示插入一个2在2号节点后
    //以下代码是错误的，下标太tm难处理了
    data[6]=2;
    posi[6]=posi[2];
    posi[2]=7;
    for(int i=0;i<8;i++)
    {
        cout<<data[posi[i]]<<' ';
        i=posi[i];
    }
    system("pause");
    return 0;
}