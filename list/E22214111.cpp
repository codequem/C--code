// DataStructure Test
//数据结构
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

/*!!!
提交的时候请将本文件更名为"你的学号.c"，比如"E01010001.c"
*/
string name = "程一帆";
string id = "E22214111";

//第一部分：串（共20分）
//实现KMP算法中的next函数，参考课本pp83：get_next函数
void Next(char T[], int next[])
{
    next[0]=0;
    next[1]=0;
    for(int i=1,k=0;i<strlen(T);i++)
    {
        while(k&&T[k]!=T[i]) k=next[k-1];//如若不匹配就一直回退
        if(T[k]==T[i]) k++;
        next[i]=k;//匹配就接着查询下一位
    }
    int temp[100];
    for(int i=0;i<strlen(T);i++)
    temp[i]=next[i];
    for(int i=0;i<strlen(T);i++)
    next[i+2]=temp[i]+1;
    for (int i = 1; i < strlen(T); i++)
    {
        printf("%d", next[i]);
    }
}
//第二部分:循环队列(共20分)
#define MAXQSIZE 30
typedef struct
{
    char elem[MAXQSIZE];
    int front;
    int rear;
} Queue;

void InitQueue(Queue *Q)
{
    if (Q)
    {
        Q->rear = 0;
        Q->front = 0;
    }
}
bool IsEmpty(Queue *Q)
{
    if (Q)
        return Q->rear == Q->front;
    return true;
}
bool IsFull(Queue *Q)
{
    if (Q)
        return (Q->rear + 1) % MAXQSIZE == Q->front;
    return false;
}

//元素入队（10分）
bool EnQueue(Queue *Q, char e)
{
    if (Q == 0 || IsFull(Q))
        return false;
    //请在下面补充你的代码
    Q->elem[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return true;
}

//元素出队（10分）
bool DeQueue(Queue *Q, char * e)
{
    if (Q == 0 || IsEmpty(Q))
        return false;
    //请在下面补充你的代码
    *e = Q->elem[Q->front];
    Q->front=(Q->front+1)%MAXQSIZE;
    return true;
}
void PrintQueue(Queue *Q)
{
    if (!Q || IsEmpty(Q))
        return;
    for (int k = Q->front; k != Q->rear; k = (k + 1) % MAXQSIZE)
    {
        putchar(Q->elem[k]);
    }
}

//第三部分：栈（共50分）
//实现顺序栈。参考课本pp46-49
#define MAX_ELEMENTS 100
typedef struct
{
    char *base;
    char *top;
    int size;
} SqStack;
//构造一个空栈，分配内存，设置相关元素的初值。（10分）
bool InitStack(SqStack *S)
{
    if (S == 0)
        return false;
    //请在下面补充你的代码
    S->base = (char *)malloc(MAX_ELEMENTS * sizeof(char));
    if (S->base == 0)
        return false;
    S->top = S->base;
    S->size = MAX_ELEMENTS;
    return true;
}
//销毁一个栈，释放所有元素的内存，并修改相关数据域的值
bool DestroyStack(SqStack S)
{
    free(S.base);
    S.top = 0;
    S.base = 0;
    return true;
}
//清除站内元素，不释放内存。
bool ClearStack(SqStack *S)
{
    if (S == 0)
        return false;
    S->top = S->base;
    return true;
}
//判断栈是否为空
bool StackEmpty(SqStack S)
{
    return S.top == S.base;
}
//取栈顶元素的值
bool GetTop(SqStack S, char *data)
{
    if (S.top == S.base)
        return false;
    *data = *(S.top - 1);
    return true;
}
//元素入栈（10分）
//注意，此处不需要重新分配内存。
//如果栈内元素已经达到最大数目MAX_ELEMENTS，
//就返回false，不执行任何其它操作
bool Push(SqStack *S, char data)
{
    if (S->top - S->base >= S->size)
        return false;
    //请在下面补充代码，将新元素data放入栈顶
    if (S->top-S->base == MAX_ELEMENTS)
        return false;
    *S->top++ = data;
    S->size++;
    return true;
}
//元素出栈（10分）
bool Pop(SqStack *S, char *data)
{
    if (S == 0 || S->top == S->base)
        return false;
    //请在下面补充代码，将栈顶元素值放入data中
    *data = *--S->top;
    S->size--;
    return true;
}
//括号匹配检验（20分）（课本pp49）
//利用前面的栈，检查括号串s中的括号是否匹配
// s中的括号有(),[],{}三种
bool Check(char *s)
{
    if (s == 0)
        return false;
    SqStack T;
    InitStack(&T);
    bool result = true;
    //第一个括号入栈
    Push(&T, s[0]);
    putchar(s[0]);
    char e, v;
    for (int j = 1; j < strlen(s); j++)
    {
        putchar(s[j]);
        //从第二个括号开始，检查是否不匹配
        if (s[j] == '(' || s[j] == '[' || s[j] == '{')
        {
            //如果s[j]为左括号，直接入栈
            //请在下面补充入栈代码
            Push(&T, s[j]);
        }
        else
        {
            //如果s[j]为右括号，需要与栈顶元素进行匹配，
            //如果匹配成功，继续检查下一个括号。
            //否则，输出"Error"，并停止检查下一个括号,同时将result赋值为false
            //请在下面补充你的代码
            if (StackEmpty(T))
            {
                result = false;
                printf("Error");
                break;
            }
            char v;
            GetTop(T, &v);
            if (s[j] == ')' && v == '(' || s[j] == ']' && v == '[' || s[j] == '}' && v == '{')
            {
                Pop(&T, &e);
            }
            else
            {
                result = false;
                printf("Error");
                break;
            }
        }
    }
    if (StackEmpty(T))
    {
        result = true;
        printf("Correct!");
    }
    DestroyStack(T);
    return result;
}

int main(int argc, char *argv[])
{
    cout << name << endl
         << id << endl;

    int score = 0;
    int error = 0;
    //第一部分：串
    printf("\n================================\n串(共20分)\n");
    char *pat = "abcaabbabcabaacbacba";
    int next[60];
    Next(pat, next);
    error = 0;
    if (next[next[5]] != next[next[6]])
        error = 1;
    if (next[next[9]] != next[next[10]])
        error = 1;
    if (next[next[11]] != next[next[10]])
        error = 1;
    if (error == 1)
        printf("错误\n");
    else
    {
        printf("正确\n");
        score += 20;
    }

    //第二部分：队列
    printf("\n================================\n队列(共30分)\n");
    Queue Q;
    InitQueue(&Q);

    printf("\n入队(15分)");
    char *data = "abcde";
    EnQueue(&Q, data[0]);
    EnQueue(&Q, data[1]);
    EnQueue(&Q, data[2]);
    EnQueue(&Q, data[3]);
    EnQueue(&Q, data[4]);
    PrintQueue(&Q);
    error = 0;
    int P = Q.front;
    for (int j = 0; j < strlen(data) && P != Q.rear; j++)
    {
        if (Q.elem[P] != data[j])
        {
            error = 1;
            break;
        }
        P = (P + 1) % MAXQSIZE;
    }
    if (error == 0)
    {
        printf("正确\n");
        score += 15;
    }
    else
        printf("错误\n");

    printf("\n出队(15分)");
    char w;
    char *data1 = "dexyz";
    DeQueue(&Q, &w);
    DeQueue(&Q, &w);
    EnQueue(&Q, 'x');
    EnQueue(&Q, 'y');
    DeQueue(&Q, &w);
    EnQueue(&Q, 'z');
    PrintQueue(&Q);
    error = 0;
    for (int j = 0; j < strlen(data1); j++)
    {
        if (false == DeQueue(&Q, &w) || w != data1[j])
        {
            error = 1;
            break;
        }
    }
    if (true == DeQueue(&Q, &w))
        error = 1;
    if (error == 0)
    {
        printf("正确\n");
        score += 15;
    }
    else
        printf("错误\n");

    //第三部分：栈
    printf("\n================================\n栈(共50分)\n");
    printf("\n初始化(10分)");
    SqStack T;
    InitStack(&T);
    if (!T.base || T.top != T.base || T.size != MAX_ELEMENTS)
        printf("错误\n");
    else
    {
        score += 10;
        printf("正确\n");
    }

    printf("\n入栈(10分)");
    char *s = "abcde";
    for (int j = 0; j < strlen(s); j++)
        Push(&T, s[j]);
    error = 0;
    for (int j = 0; j < strlen(s); j++)
    {
        putchar(T.base[j]);
        if (T.base[j] != s[j])
            error = 1;
    }
    if (error == 1)
        printf("错误\n");
    else
    {
        printf("正确\n");
        score += 10;
    }

    printf("\n出栈(10分)");
    char c;
    error = 0;
    for (int j = 0; j < 6; j++)
    {
        if (true == Pop(&T, &c))
        {
            putchar(c);
            if (c != s[4 - j])
                error = 1;
        }
        else
        {
            putchar('@');
            if (j != 5)
                error = 1;
        }
    }
    if (error == 1)
        printf("错误\n");
    else
    {
        printf("正确\n");
        score += 10;
    }
    DestroyStack(T);

    printf("\n括号匹配检验(20分)\n");
    error = 1;
    if (true == Check("(){([][])[(([]))]}"))
    {
        error = 0;
        printf("  正确\n");
    }
    else
    {
        printf("错误\n");
    }
    if (false == Check("{[][]([](])}"))
    {
        error = 0;
        printf("  正确\n");
    }
    else
    {
        printf("错误\n");
    }
    if (error == 0)
        score += 20;
    cout << endl << name << ',' << id << ',';
    printf("总分=%d\n\n", score);
    getchar();
    return 1;
}
