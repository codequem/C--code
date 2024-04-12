//create the pers and debts namespace 

//作为头文件，运用名称空间的知识，包含了常量，结构定义和函数原型
namespace pers
{
    const int len=40;//常量

    struct person{
        char fname[len];
        char lname[len];
    };//结构定义

    void getperson(person&);
    void showperson(const person&);//函数原型
}

namespace debts{
    using namespace pers;

    struct debt{
        person name;
        double amount;
    };

    void getdebt(debt&);
    void showdebt(const debt &);
    double sumdebts(const debt ar[],int n);
}