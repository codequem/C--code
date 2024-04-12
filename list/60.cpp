#include <iostream>
#include <string.h>

using namespace std;
int main (void)
{
    //在C++中，你可以将void*转换为int*，但是你需要使用静态转换（static_cast），而不是C风格的强制转换。
    //此外，你不能直接获取转换后的地址，因为转换后的结果是一个右值（rvalue），而一元'&'运算符需要一个左值（lvalue）。
    int num = 0;
    void* p = &num; // 将 num 的地址赋给 p
    int* intPtr = static_cast<int*>(p); // 将 void* 转换为 int*
    cout << intPtr << endl; // 打印 intPtr 的值（也就是 num 的地址）
}