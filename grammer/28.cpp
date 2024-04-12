/*类对象中再谈new和delete*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main (void)
{
    
}

//在下述情况下析构函数将被调用
//1.如果对象是动态变量，则当执行完定义该对象的程序块时将调用该对象的析构函数
//2.如果对象是静态变量，则当执行完整个程序是将调用该对象的析构函数
//3.如果对象是用new创建的，当且仅当您显式的使用delete函数删除对象时，其析构函数才会被调用

