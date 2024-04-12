#include <iostream>
#include <windows.h>
#include "21.h"


//vsc不知道能不能多文件编译，但是我可以自己多文件编译，用编译指令就行了
void other(void);
void another(void);

int main(void)
{
    using debts::debt;//这里注意，using指令只使用名称，所以如果函数被重载，则这个声明将会导入所有的版本
    using debts::showdebt;
    debt golf={{"cyf","kank"},120.0};
    showdebt(golf);
    other();
    another();
    system("pause");
    return 0;
}

void other(void)
{
    using std::cout;
    using std::endl;
    using namespace debts;
    person dg={"doodles","glister"};
    showperson(dg);
    cout<<endl;
    debt zippy[3];
    int i;
    for(i=0;i<3;i++)
        getdebt(zippy[i]);
    for(i=0;i<3;i++)
        showdebt(zippy[i]);
    cout<<"total debt: $"<<sumdebts(zippy,3)<<endl;
    return;
}

void another(void)
{
    using pers::person;
    person collector={"milo","rightshift"};
    pers::showperson(collector);
    std::cout<<std::endl;
}