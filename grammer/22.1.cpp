/*2022年11月13日00:42:30*/
//为类声明中的原型表示的成员函数提供定义：
//成员函数与常规函数定义非常相似，但是它们还有两个特殊的特征:1.定义成员函数时，使用作用域解析操作符来标识函数所属的类
//2.类方法可以访问类的private组件
//类方法的完整名称中包括类名，我们说stock::update()是函数的限定名，而简单的update是全名的缩写，只能在类作用域中使用
#include "22.h"
#include <cstring>
#include <iostream>


//类作用域：可以在不同的类中使用相同的类成员名称，不能从外部直接访问类的成员，要调用公有成员必须通过对象
//在类声明或者成员函数定义中，可以使用未修饰的成员名称，构造函数在被调用时才能被识别，因为它的名称和类名相同
//因此下面的函数定义都要使用作用域解析符,因为全都不在类的声明中

void stock::acquire(const char *co,int n,double pr)
{
    strncpy(company,co,29);//函数调用strncpy（s2,s1,n）将s1复制n个字符到s2，如果s1的字符不足n个，则添加空值字符以达到n个
    company[29]='\0';//在尾部放空字符以确保是字符串
    if(n<0)
    {
        std::cerr<<"number of shares can't be negative. "//cerr也是一个ostream对象，区别在于如果将程序重定向到文件
        //cout将不会在屏幕上显示，而cerr不受影响，cerr用于输出错误消息
        <<company<<" shares set to 0";
    }
    else
        shares=n;//这里使用类的shares成员，当这个成员函数被调用时，它将使用被用来调用它的对象的shares成员
        //依据类创建的每个新对象都有自己的储存空间，但他同一个类的对象共享同一组类方法
    share_val=pr;
    set_tot();
}

void stock::buy(int num,double price)
{
    if(num<0)
    {
        std::cerr<<"number of shares purchased can't be negative. "
        <<"transaction is aborted.\n";
    }
    else
    {
        shares+=num;
        share_val=price;
        set_tot();
    }
}

void stock::sell(int num,double price)
{
    using std::cerr;
    if(num<0)
    {
        cerr<<"number of shares sold can't be negative. "
        <<"transaction is aborted.\n";
    }
    else if(num>shares)
    {
        cerr<<"you can't sell more than you have! "
        <<"transaction is aborted.\n";
    }
    else
    {
        shares-=num;
        share_val=price;
        set_tot();
    }
}

void stock::update(double price)
{
    share_val=price;
    set_tot();
}

void stock::show()const
{
    using std::cout;
    using std::endl;
    cout<<"company: "<<company
    <<" shares: "<<shares<<endl
    <<" share price: $"<<share_val
    <<" total worth: $"<<total_val<<endl;
}

stock::stock(const char*co,int n,double pr)//这里也要用作用域解析符
//构造参数的参数表示的不是类成员，而是赋给类成员的值，因此，参数名不可以和类成员相同
//没有返回类型
{
    strncpy(company,co,29);
    company[29]='\0'; 
    if(n<0)
    {
        std::cerr<<"number of share can't be negative;"
        <<company<<" shares set to 0.\n";
        shares=0;
    }
    else
    {
        shares=n;
        share_val=pr;
    }
    set_tot();
}

stock::~stock()
{//这里stock类对象是声明的，没有使用new，因此这里的析构函数不用进行什么操作
//如果构造函数使用new来分配内存，那么析构函数将使用delete来释放这些内存
    using std::cout;
    cout<<"bye, "<<company<<"!\n";
}

const stock& stock::topval(const stock&s)const
{
    if(s.total_val>this->total_val)
        return s;
    else
        return *this;//this指针指向调用这个类方法的对象
}