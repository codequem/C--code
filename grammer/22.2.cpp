/*2022年11月13日11:25:56
使用类*/

#include <iostream>
#include "22.h"
#include <windows.h>

int main (void)
{
    using std::cout;
    using std::ios_base;
    stock stock1;
    stock stock2("kank",3,4);//调用构造函数，但是构造函数不可以通过对象调用，因为在构造函数构造出对象之前，对象是不存在的
    //调用构造函数的另一种方式
    stock *pstock=new stock("liziqi",10,100);//该种情况下，对象没有名称，但是可以使用指针管理对象
    stock sticks[5];//要创建类对象数组，则这个类必须要有默认构造函数，最好要有默认参数，否则你得全初始化了
    stock1.acquire("nanosmart",20,12.50);
    cout.setf(ios_base::fixed);
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    stock1.show();
    stock1.buy(15,18.25);
    stock1.show();
    stock1.sell(400,20.00);
    stock1.show();
    system("pause");
    return 0;
}