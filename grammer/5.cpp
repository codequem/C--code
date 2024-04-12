/*2022年10月22日20:57:59
测试函数指针*/
#include <iostream>
using namespace std;
int sum(int a,int b);
int(*fun())(int,int);//这是一个返回函数指针的函数，去掉函数名，留下的是int(*)(int,int),也就是说返回值为一个返回int，接受
//两个int参数的函数指针
int(*funn(int,int))(int,int);
int main (void)
{
    int (*ptr)(int,int);//声明一个指向函数的指针，必须指定函数的返回类型和参数列表
    //此时ptr就是指向sum函数这种类型的一个指针了
    //注意优先级，如果写成int * ptr(int),那么ptr将会被认为是一个接受一个int参数，返回一个int*指针的函数
    ptr=sum;//函数名（不带括号的）就是函数的地址
    //这使得我们可以将函数地址传给需要这个参数的函数
    //当然我们也可以通过函数指针来调用函数
    //有两种格式
    int a=3,b=4,c;
    //虽然两种方式互相矛盾，但是两种方式在c++上都是合法的
    c=(*ptr)(a,b);
    c=ptr(a,b);
}

int sum(int a,int b)
{
    return a+b;
} 