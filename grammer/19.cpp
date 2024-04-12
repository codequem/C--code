/*2022年11月10日22:12:52
布局new操作符（必须添加new头文件）*/


/* //辅示例
#include <iostream>
#include <new>

using namespace std;

struct chaff{
    char dross[20];
    int slag;
}

//通常，new负责在堆（heap）中找到一个能够满足要求的的内存块，但new还有另外一种变体
//称为布局new运算符，它能够让你指定要使用的位置

char buffer1[50];
char buffer2[100];
int main (void)
{
    chaff *p1,*p2;
    int *p3,*p4;
    //首先，常规的使用new
    p1=new chaff;//在堆中分配空间放置结构
    p3=new int[20];//在堆中分配空间放置int型数组
    //其次，两种新的形式来使用new（布局new）
    p2=new(buffer1) chaff;//将chaff结构放在buffer1中
    p4=new(buffer2) int [20];//将int数组放在buffer2中
} */

//主要示例
#include <iostream>
#include <new>//为了使用布局new操作符

using namespace std;
const int buf=512;
const int n=5;
char buffer[buf];//内存块
int main(void)
{
    double *pd1,*pd2;
    int i;
    cout<<"calling new and placement new:\n ";//调用new和placement new
    pd1=new double [n];//使用堆分配内存
    pd2=new (buffer)double[n];//使用buffer array来分配内存
    for(i=0;i<n;i++)
        pd2[i]=pd1[i]=1000+20.0*i;
    cout<<"buffer addresses:\n"<<"heap:"<<pd1<<"  static:"<<(void*)buffer<<endl;
    cout<<"buffer contents\n";
    //buffer数组的地址：
    //堆：           //静态数组buffer：
    //buffer数组的内容
    for(i=0;i<n;i++)
    {
        cout<<pd1[i]<<" at "<<&pd1[i]<<";";
        cout<<pd2[i]<<" at "<<&pd2[i]<<endl;
    }
    cout<<"\ncalling new and placement new a second time:\n";
    double *pd3,*pd4;
    pd3=new double[n];
    pd4=new (buffer)double[n];
    for(i=0;i<n;i++)
        pd4[i]=pd3[i]=1000+20.0*i;
    cout<<"buffer contents:\n";
    for(i=0;i<n;i++)
    {
        cout<<pd3[i]<<" at "<<&pd3[i]<<";";
        cout<<pd4[i]<<" at "<<&pd4[i]<<endl;
    }
    cout<<"\ncalling new and placement new a third time:\n";
    delete []pd1;
    pd1=new double [n];
    pd2=new (buffer+n*sizeof(double)) double[n];
    for(i=0;i<n;i++)
        pd2[i]=pd1[i]=1000+20.0*i;
    for(i=0;i<n;i++)
    {
        cout<<pd1[i]<<" at "<<&pd1[i]<<";";
        cout<<pd2[i]<<" at "<<&pd2[i]<<endl;
    }
    delete []pd1;
    delete []pd3;
    //只释放了常规new申请的内存
    return 0;
}

//这个程序有三点需要注意
//第一，布局new操作符确实将数组p2放在了数组buffer中，同时常规new操作把数组p1放在了堆中
//第二，第二个常规new查找一个新的内存块，而布局new操作符使用传递给他的地址，他不跟踪哪些内存单元已经使用过，也不查找未使用的内存块
//第三，delete只能管辖这样的指针：指向常规new操作符分配的堆内存，也就是说，静态变量buffer位于delete的管辖范围外
//如果delete[]p2将会re（running error）
//但是如果buffer是使用常规new操作符创建的，就可以使用常规delete来释放整个内存块