/*2022年11月7日20:46:58
函数模板和重载函数模板定义
*/
//在代码中包含函数模板本身并不会生成函数定义，他只是一个用于生成函数定义的方案
#include <iostream>

using namespace std;
//template:英文，意为模板
template <class Any>//这一行指出，要建立一个模板，并且将类型，命名为Any，这里的类型名可以任意选择
//关键字template和class是必需的，除非可以使用关键字typename代替class，另外必须使用尖括号
//关键字typename是最近才添加到c嘎嘎里的，在上述情况下，可以替换关键字class，它使得参数Any表示类型这一点更为明显
void swap_(Any &a,Any &b);

//函数模板重载
template<class T,int N>//模板参数类型
void swap_(T (&a)[N],T (&b)[N]);//特征标不同即可
//这个函数也能这么写:void swap_(T *a,T *b,n)但是不如上面这种
//这说明了模板中并不是所有的参数都必须是模板参数类型

template <typename T>
void sum(T &a,T &b);

int main (void)
{
    int a=3,b=4;
    double c=2.2,d=3.3;
    cout<<"a="<<a<<endl<<"b="<<b<<endl<<"c="<<c<<endl<<"d="<<d<<endl;
    //同一个函数，但是支持不同的数据类型
    swap_(a,b);
    cout<<"a="<<a<<endl<<"b="<<b<<endl<<"c="<<c<<endl<<"d="<<d<<endl;
    swap_(c,d);
    cout<<"a="<<a<<endl<<"b="<<b<<endl<<"c="<<c<<endl<<"d="<<d<<endl;
    int arr1[5],arr2[5];
    for(int i=0;i<5;i++)
    cin>>arr1[i]>>arr2[i];
    swap_(arr1,arr2);
    for(int i=0;i<5;i++)
    cout<<arr1[i]<<arr2[i]<<endl;
    return 0;
}

//这里以下的部分描述了交换两个Any值的算法，模板并不创建任何函数，而只是告诉编译器如何定义函数
//需要交换int的函数时，编译器将会按模板模式创建这样的函数，并用int代替Any
template <class Any>
void swap_(Any &a,Any &b)
{
    Any temp;
    temp=a;
    a=b;
    b=temp;
}

template <class T,int N>
void swap_(T (&a)[N],T(&b)[N])
{
    T temp;
    for(int i=0;i<N;i++)
    {
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}

template <typename T>
void sum(T &a,T &b)
{
    a=a+b;
}