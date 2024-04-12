/*2023年1月7日10:15:14
栈的数组模拟实现*/
#include <iostream>
#include <windows.h>
const int maxn=1e5+5;

using std::cout;
using std::cin;
using std::endl;

template<typename T>
struct stack{
    T data[maxn];
    int top=-1;//指向栈顶 
};
template<typename T>
T pop(struct stack<T>& s);//出栈
template<typename T>
void push(struct stack<T>& s,T x);//入栈

int main (void)
{
    struct stack<int> s;
    for(int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        push(s,x);
    }
    for(int i=0;i<3;i++)
    pop(s);
    for(int i=s.top;i!=-1;i--)
    cout<<s.data[i]<<' ';
    system("pause");
    return 0;
}

template<typename T>
T pop(struct stack<T>& s)
{
    return s.data[--s.top];
}

template<typename T>
void push(struct stack<T>& s,T x)
{
    s.data[++s.top]=x;
}