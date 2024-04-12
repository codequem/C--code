// DataStructure Test
//���ݽṹ
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

/*!!!
�ύ��ʱ���뽫���ļ�����Ϊ"���ѧ��.c"������"E01010001.c"
*/
string name = "��һ��";
string id = "E22214111";

//��һ���֣�������20�֣�
//ʵ��KMP�㷨�е�next�������ο��α�pp83��get_next����
void Next(char T[], int next[])
{
    next[0]=0;
    next[1]=0;
    for(int i=1,k=0;i<strlen(T);i++)
    {
        while(k&&T[k]!=T[i]) k=next[k-1];//������ƥ���һֱ����
        if(T[k]==T[i]) k++;
        next[i]=k;//ƥ��ͽ��Ų�ѯ��һλ
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
//�ڶ�����:ѭ������(��20��)
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

//Ԫ����ӣ�10�֣�
bool EnQueue(Queue *Q, char e)
{
    if (Q == 0 || IsFull(Q))
        return false;
    //�������油����Ĵ���
    Q->elem[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return true;
}

//Ԫ�س��ӣ�10�֣�
bool DeQueue(Queue *Q, char * e)
{
    if (Q == 0 || IsEmpty(Q))
        return false;
    //�������油����Ĵ���
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

//�������֣�ջ����50�֣�
//ʵ��˳��ջ���ο��α�pp46-49
#define MAX_ELEMENTS 100
typedef struct
{
    char *base;
    char *top;
    int size;
} SqStack;
//����һ����ջ�������ڴ棬�������Ԫ�صĳ�ֵ����10�֣�
bool InitStack(SqStack *S)
{
    if (S == 0)
        return false;
    //�������油����Ĵ���
    S->base = (char *)malloc(MAX_ELEMENTS * sizeof(char));
    if (S->base == 0)
        return false;
    S->top = S->base;
    S->size = MAX_ELEMENTS;
    return true;
}
//����һ��ջ���ͷ�����Ԫ�ص��ڴ棬���޸�����������ֵ
bool DestroyStack(SqStack S)
{
    free(S.base);
    S.top = 0;
    S.base = 0;
    return true;
}
//���վ��Ԫ�أ����ͷ��ڴ档
bool ClearStack(SqStack *S)
{
    if (S == 0)
        return false;
    S->top = S->base;
    return true;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S)
{
    return S.top == S.base;
}
//ȡջ��Ԫ�ص�ֵ
bool GetTop(SqStack S, char *data)
{
    if (S.top == S.base)
        return false;
    *data = *(S.top - 1);
    return true;
}
//Ԫ����ջ��10�֣�
//ע�⣬�˴�����Ҫ���·����ڴ档
//���ջ��Ԫ���Ѿ��ﵽ�����ĿMAX_ELEMENTS��
//�ͷ���false����ִ���κ���������
bool Push(SqStack *S, char data)
{
    if (S->top - S->base >= S->size)
        return false;
    //�������油����룬����Ԫ��data����ջ��
    if (S->top-S->base == MAX_ELEMENTS)
        return false;
    *S->top++ = data;
    S->size++;
    return true;
}
//Ԫ�س�ջ��10�֣�
bool Pop(SqStack *S, char *data)
{
    if (S == 0 || S->top == S->base)
        return false;
    //�������油����룬��ջ��Ԫ��ֵ����data��
    *data = *--S->top;
    S->size--;
    return true;
}
//����ƥ����飨20�֣����α�pp49��
//����ǰ���ջ��������Ŵ�s�е������Ƿ�ƥ��
// s�е�������(),[],{}����
bool Check(char *s)
{
    if (s == 0)
        return false;
    SqStack T;
    InitStack(&T);
    bool result = true;
    //��һ��������ջ
    Push(&T, s[0]);
    putchar(s[0]);
    char e, v;
    for (int j = 1; j < strlen(s); j++)
    {
        putchar(s[j]);
        //�ӵڶ������ſ�ʼ������Ƿ�ƥ��
        if (s[j] == '(' || s[j] == '[' || s[j] == '{')
        {
            //���s[j]Ϊ�����ţ�ֱ����ջ
            //�������油����ջ����
            Push(&T, s[j]);
        }
        else
        {
            //���s[j]Ϊ�����ţ���Ҫ��ջ��Ԫ�ؽ���ƥ�䣬
            //���ƥ��ɹ������������һ�����š�
            //�������"Error"����ֹͣ�����һ������,ͬʱ��result��ֵΪfalse
            //�������油����Ĵ���
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
    //��һ���֣���
    printf("\n================================\n��(��20��)\n");
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
        printf("����\n");
    else
    {
        printf("��ȷ\n");
        score += 20;
    }

    //�ڶ����֣�����
    printf("\n================================\n����(��30��)\n");
    Queue Q;
    InitQueue(&Q);

    printf("\n���(15��)");
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
        printf("��ȷ\n");
        score += 15;
    }
    else
        printf("����\n");

    printf("\n����(15��)");
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
        printf("��ȷ\n");
        score += 15;
    }
    else
        printf("����\n");

    //�������֣�ջ
    printf("\n================================\nջ(��50��)\n");
    printf("\n��ʼ��(10��)");
    SqStack T;
    InitStack(&T);
    if (!T.base || T.top != T.base || T.size != MAX_ELEMENTS)
        printf("����\n");
    else
    {
        score += 10;
        printf("��ȷ\n");
    }

    printf("\n��ջ(10��)");
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
        printf("����\n");
    else
    {
        printf("��ȷ\n");
        score += 10;
    }

    printf("\n��ջ(10��)");
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
        printf("����\n");
    else
    {
        printf("��ȷ\n");
        score += 10;
    }
    DestroyStack(T);

    printf("\n����ƥ�����(20��)\n");
    error = 1;
    if (true == Check("(){([][])[(([]))]}"))
    {
        error = 0;
        printf("  ��ȷ\n");
    }
    else
    {
        printf("����\n");
    }
    if (false == Check("{[][]([](])}"))
    {
        error = 0;
        printf("  ��ȷ\n");
    }
    else
    {
        printf("����\n");
    }
    if (error == 0)
        score += 20;
    cout << endl << name << ',' << id << ',';
    printf("�ܷ�=%d\n\n", score);
    getchar();
    return 1;
}
