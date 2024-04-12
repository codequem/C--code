/*2022年11月15日22:06:02
操作符重载*/

//重载限制：
//多数c++操作符都可以重载，但有一些限制：
//1.重载后的操作符必须至少有一个操作数是用户定义的类型，这是为了防止用户为标准类型重载操作符（你把1+2表达为1-2的值明摆着脑子有问题）
//2.使用操作符时不能违反操作符原来的句法规则，也就是说二元操作符不能重载成一元
//3.不能定义新的操作符
//4.不能重载下面的操作符：1.（sizeof）---sizeof操作符 2.（.）---成员操作符 3.（.*）---成员指针操作符
//4.（：：）---作用域解析操作符 5.（？：）---条件操作符 ,还有的咱还没学，先不看
//5.下面的操作符只能通过成员函数进行重载：1.（=）---赋值操作符 2.（（））---函数调用操作符 3.（[]）---下标操作符
//4.（->）---通过指针访问类成员的操作符

#include <iostream>
#include <string>
    using std::string;
    using std::cout;
    using std::endl;
class test{
    private:

    static const int MAX=3;
    int array[MAX];
    string name;

    public:
    ~test(){};//析构函数
    test(string s="null",int n1=0,int n2=0,int n3=0)//构造函数
    {
        name=s;
        array[0]=n1,array[1]=n2,array[2]=n3;
    }
    //格式为：operator op(argumnet_list),
    //使用的时候是这样操作的      c=a+b;//假设a，b，c是用户自定义的类型
    //实质上为c=a.operator+(b);//当然原则上你也可以这么用加法，但是显然不如上面直观
    //因此操作符重载需要有返回，并且这个操作符显式使用对象b，并且隐式的使用了对象a，这点很重要 

    test operator +(const test& t)//这里就是操作符重载，为了使两个test对象相加更直观，而隐藏实现细节
    {//注意参数是引用，但是返回类型不是引用，参数是引用的原因是为了提高效率，而返回值不必是引用，类支持直接赋值
        this->name+=t.name;
        for(int i=0;i<MAX;i++)
        this->array[i]+=t.array[i];
        return *this;
    }
    void show_test()
    {
        cout<<"name: "<<name<<endl
        <<array[0]<<array[1]<<array[2];
    }
};

int main (void)
{
    test t1("hahaha",1,2,3);
    test t2("cyf",2,3,4);
    test t3;
    t3=t1+t2;
    t3.show_test();
    return 0;
}