/*2022年11月7日15:37:43
默认参数和函数重载（多态）*/

//默认参数指的是当函数调用时省略了实参时自动使用的一个值
//默认参数能够让你使用不同数目的参数调用同一个参数
//函数重载能够让你可以构造多个同名的函数
//仅当函数基本上执行相同的任务，但是使用不同类型的数据时才应使用函数重载，不要滥用
//设置默认值必须通过函数原型
#include <iostream>

using namespace std;

void print(const char name[]="cyf");//这里把一个常值（字符串常量）的地址给char指针（设置默认参数），所以char指针必须设为const型\
//对于带有参数列表的函数，必须从右到左添加默认值，也就是说，要为某个参数设置默认值，则必须为它右边的所有参数提供默认值
int sum(int a=0,int b=0,int c=0,int d=0);

//下面的函数名字一样但是他们的特征标不相同
//即：参数数目，类型，排列，当两个函数的参数数目，类型，排列都相同时，它们的特征标相同
//但是变量名不影响特征标，而且要注意，编译器将把类型引用和类型本身看做同一个特征标
//但是const和非const不是同一个特征标
void print(int a);
//void print(int &a);//这个函数引用int型的数据，而前面已经有了一个使用int本身的函数了，因此他们的特征标相同，不合法
void print(double b);
void print(int a,char c);
double print(int a,char c);//非法，特征标相同，函数类型不同是不能重载的
double print(int a,int b);//合法，归根结底还是要特征标不同

int main (void)
{
    print();//当省略实参时，就将实参设定为默认的参数
    print("hahaha");
    print(5);//编译器将会根据实参来选择使用哪个函数定义
    print(5,'c');
    //现在的sum允许调用它时，提供0,1,2,3,4个参数
    sum();
    sum(1,2);
    sum(1,3,4);
    //sum(1,,4);//这样是非法的，不允许跳过任何参数，实参按从左到右的顺序依次被赋给相应的形参
    return 0;
}

//函数定义与没有默认参数的时候完全一致
void print(const char name[])
{
    cout<<name<<endl;
}
int sum(int a,int b,int c,int d)
{
    cout<<a+b+c+d<<endl;
    return a+b+c+d;
}
void print(int a)
{
    cout<<a<<endl;
}
void print(int a,char c)
{
    for(int i=0;i<a;i++)
    cout<<c;
    cout<<endl;
}