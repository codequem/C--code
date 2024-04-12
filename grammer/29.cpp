/*2023年5月6日18:25:23
来看看关键字*/
#include <iostream>

using namespace std;

int main (void)
{
    register int i;//register 变量必须是一个单个的值，并且其长度应小于或等于整型的长度。
    //且 register 变量可能不存放在内存中，所以不能用取址运算符“&”来获取 register 变量的地址
    //如果这个变量频发使用，可以让他在寄存器里待着。
}