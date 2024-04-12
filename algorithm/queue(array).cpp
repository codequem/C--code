/*2023年1月6日23:57:03
队列的数组模拟实现*/
//现在实际实现的是循环队列
#include <iostream>
#include <cmath>
#include <Windows.h>
const int maxn=/* 1e5+ */5;

using std::cout;
using std::endl;
using std::cin;

template<typename T>//结构体模板不可以用typedef定义别名
struct queue{
    T data[maxn];
    int head=0;
    int tail=0;
};

template<typename T>
T pop(struct queue<T>& q);//出队
template<typename T>
void push(struct queue<T>& q,T x);//入队
template<typename T>
int QueLength(struct queue<T> q);//查询队列长度
template<typename T> 
void print(struct queue<T> q);//打印队列

int main(void)
{
    struct queue<int> q;
    for(int i=0;i<6;i++)
    {
        int x;
        cin>>x;
        push(q,x);
    }
    for(int i=0;i<3;i++)
    pop(q);
    for(int i=0;i<6;i++)
    {
        int x;
        cin>>x;
        push(q,x);
    }
    for(int i=0;i<2;i++)
    pop(q);
    cout<<QueLength(q)<<endl;
    print(q);
    system("pause");
    return 0;
}

template<typename T>
T pop(struct queue<T>& q)
{
    if(q.head==q.tail)
    {
        cout<<"the queue is empty!!!"<<endl;
        return -1;
    }
    T temp=q.data[q.head++];
    q.head%=maxn;
    return temp;
}

template<typename T>
int QueLength(struct queue<T> q)
{
    return fabs(q.head-q.tail);
}

template<typename T>
void push(struct queue<T>& q,T x)
{
    if(q.tail+1==q.head)
    {
        cout<<"the queue is full"<<endl;
        return;
    }
    q.data[q.tail++]=x;
    q.tail%=maxn;
}

template<typename T> 
void print(struct queue<T> q)
{
    int temp=q.head;
    for(int i=0; i<QueLength(q);i++)
    {
        cout<<q.data[temp--]<<endl;
        if(temp<0)
        temp=maxn-1;
    }
}