/*2022年10月21日23:29:53
使用两种方法的指针指向string类对象*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main (void)
{
    string *pt;//指向string类的指针
    string animal="hahaha";
    char *pr;
    pr=&animal[0];//指向首字母的地址
    pt=&animal;
    cout<<pr<<endl;
    cout<<pt<<endl;//pt虽然确实存的是地址，但是cout除了char*型指针，都打印地址，而不是字符串
    printf("%p",pt);//printf也打印不出来字符串，但是也可以打印地址，确切的说，是对于string*型的指针打印出来的是地址
    return 0;
}