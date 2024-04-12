/*2023年4月18日15:54:36*/
#include <iostream>
#include <windows.h>
#define SElemType int

using namespace std;

typedef struct DblStack
{
    int top[2], bot[2]; //栈顶和栈底指针
    SElemType *V;       //栈数组
    int m;              //栈最大可容纳元素个数
    DblStack(int m = 0) : m(m)
    {
        top[0] = bot[0] = -1;
        top[1] = bot[1] = m;
        V = new SElemType[m];
    }
    bool is_empty()
    {
        return (top[0] == -1 && top[1] == m);
    }
    bool is_full()
    {
        return top[0] + 1 == top[1];
    }
} DblStack;

void push_left(SElemType val, DblStack &DS);
void push_right(SElemType val, DblStack &DS);
SElemType pop_left(DblStack &DS);
SElemType pop_right(DblStack &DS);
void print_left(DblStack DS);
void print_right(DblStack DS);

int main(void)
{
    DblStack test(10);
    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        push_left(n, test);
    }
    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        push_right(n, test);
    }
    print_left(test);
    print_right(test);
    for(int i=0;i<2;i++)
    {
        cout<<pop_left(test)<<endl;
        print_left(test);
        cout<<pop_right(test)<<endl;
        print_right(test);
    }
    system("pause");
    return 0;
}

void push_left(SElemType val, DblStack &DS)
{
    if (DS.is_full())
    {
        cout << "The DblStack is full" << endl;
        return;
    }
    else
        DS.V[++DS.top[0]] = val;
}

void push_right(SElemType val, DblStack &DS)
{
    if (DS.is_full())
    {
        cout << "The DblStack is full" << endl;
        return;
    }
    else
        DS.V[--DS.top[1]] = val;
}

SElemType pop_left(DblStack &DS)
{
    if (DS.is_empty())
    {
        cout << "The DblStack is empty" << endl;
        return -1;
    }
    else
        return DS.V[DS.top[0]--];
}

SElemType pop_right(DblStack &DS)
{
    if (DS.is_empty())
    {
        cout << "The DblStack is empty" << endl;
        return -1;
    }
    else
        return DS.V[DS.top[1]++];
}

void print_left(DblStack DS)
{
    for (int i = DS.bot[0] + 1; i <= DS.top[0]; i++)
        i == DS.top[0] ? (cout << DS.V[i] << endl) : (cout << DS.V[i] << ' ');
}

void print_right(DblStack DS)
{
    for (int i = DS.bot[1]-1; i >=DS.top[1]; i--)
        i == DS.top[1] ? (cout << DS.V[i] << endl) : (cout << DS.V[i] << ' ');
}