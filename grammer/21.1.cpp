//提供了头文件中函数原型对应的定义

#include <iostream>
#include "21.h"

//这里就体现出名称空间开放性的用处了
namespace pers{
    using std::cin;//在名称空间中声明要使用到的函数
    using std::cout;
    void getperson(person&rp)
    {
        cout<<"enter first name:";
        cin>>rp.fname;
        cout<<"enter last name:";
        cin>>rp.lname;
    }

    void showperson(const person& rp)
    {
        cout<<rp.lname<<','<<rp.fname;
    }
}

namespace debts{
    void getdebt(debt&rd)
    {
        getperson(rd.name);
        std::cout<<"enter debt:";
        std::cin>>rd.amount;
    }
    void showdebt(const debt &rd)
    {
        showperson(rd.name);
        std::cout<<": $"<<rd.amount<<std::endl;
    }
    double sumdebts(const debt ar[],int n)
    {
        double total=0;
        for(int i=0;i<n;i++)
            total+=ar[i].amount;
        return total;
    }
}