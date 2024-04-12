/*智能指针 2024年1月29日10:53:21*/
#include <memory>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    // shared_ptr:允许多个指针指向同一个对象
    shared_ptr<string> ps1 = make_shared<string>("hello");
    shared_ptr<string> ps2 = make_shared<string>("world");
    shared_ptr<string> ps3 = ps2;
    shared_ptr<string> ps4 = ps2;
    string *str = new string("world!");
    if (true)
    {
        shared_ptr<string> ps5(str);                        //这样ps5和str管理的是同一个对象
        shared_ptr<string> ps6 = make_shared<string>(*str); //而这样，ps6实际上是使用str的值来利用string的构造函数创建了一个新的对象
        //所以ps5和str管理的是同一个对象，而ps6和str管理的是两个不同的对象,ps6被销毁，str还在
    }
    cout << *ps1 << " " << *ps2 << endl;
    cout << *str;
}