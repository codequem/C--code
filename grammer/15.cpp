/*2022年11月8日00:40:49
显式具体化(函数模板)和显式实例化
以及函数重载解析*/

#include <iostream>

using namespace std;

typedef struct job{
    char name[40];
    double salary;
    int floor;
}job;
//对于给定的函数名，可以有非模板函数，模板函数，显式具体化模板函数，以及他们的重载版本
//具体化将覆盖常规模板，而非模板函数将覆盖具体化和常规模板
//显式具体化的原型应该以template<>打头，并且通过名称来指出类型

//非模板函数（为了展示显式具体化因此不写非模板函数）
//void swap_(job &a,job &b);

//模板函数
template<typename T>
void swap_(T &a,T &b);

//显式具体化
template<>void swap_<job>(job &a,job &b);//或者是template <>void swap_(job &a,job &b);
//显式具体化的声明意为，不要使用swap_函数模板来生成函数定义，而是应该用独立的，专门的函数定义显式的为int类型生成函数定义

//在代码中包含函数模板本身并不会生成函数定义，他只是一个用于生成函数定义的方案
//编译器使用模板为特定类型生成函数定义时，得到的是模板实例，模板并非函数定义，但是使用int的模板是函数定义
//这种实例化方式称为隐式实例化
//而显式实例化允许编译器直接创建特定的实例，其句法是
template void swap_<int>(int &,int &);//这句声明意为使用swap_模板生成int类型的函数定义


//显式具体化和显式实例化的区别：显式具体化在关键字template后包含<>，而显式实例化没有
//显式具体化是重新做的一个函数，而显式实例化是通过模板生成一个函数
//如果同时在一个编程单元中使用同一种类型的显式实例和显式具体化将会出错


//隐式实例化，显式实例化和显式具体化统称为具体化，他们的共同点在于表示的都是使用具体类型的函数定义，而不是通用描述


//函数重载解析：简而言之，重载解析将寻找最匹配的函数，如果只存在一个这样的函数，则选择它，如果存在多个这样的函数
//但是其中只有一个是非模板函数，则选择该函数，如果存在多个合适的函数，并且他们都为模板函数
//但是其中有一个函数比其他函数更加具体，则选择该函数，这里指的更具体，是指实参转换到模板生成所需的形参的步数最少
//其余情况则会报错（因为函数调用存在歧义）
int main (void)
{
    job aaa,bbb;
    aaa.floor=1,aaa.salary=0,bbb.floor=0,bbb.salary=1;
    cin>>aaa.name>>bbb.name;
    swap_(aaa,bbb);
    int a=1,b=2;
    swap_(a,b);
    return 0;
}

template<typename T>
void swap_(T &a,T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<>void swap_<job>(job &a,job &b)
{
    job temp;
    temp.floor=a.floor;
    a.floor=b.floor;
    b.floor=temp.floor;
}