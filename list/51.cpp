//--------------------利用堆实现串的相关操作------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <windows.h>
#define N 1000005

using namespace std;

//改成自己的名字和学号
char *name = "程一帆";
char *id = "E22214111";

typedef int Status;

#define OK 1
#define ERROR 0

int Next[N];
//串的堆分配存储表示
typedef struct //参考书Pg. 75
{
    char *ch = NULL; //若串是非空，则按照串长分配存储区，否者ch为NULL
    int length = 0;  //串长度

} HString;

Status StrAssign(HString &T, char *Str)
{ //请补充你的代码:生成一个其值等于Str的串T
    T.ch = new char[strlen(Str) + 1];
    strcpy(T.ch, Str);
    T.length = strlen(Str);
    return OK;
}

Status StrAssign(HString &T, int len)
{ //请补充你的代码:生成一个其值等于Str的串T
    T.ch = new char[len + 1];
    T.length = len;
    return OK;
}

Status ClearString(HString &T)
{ //请补充你的代码:将S清空为空串
    delete[] T.ch;
    T.ch = NULL;
    return OK;
}

Status Concat(HString &T, HString &S1, HString &S2)
{ //请补充你的代码:用T返回S1和S2联接而成的新串
    char *ptr = S1.ch;
    S1.ch = (char *)malloc((S1.length + S2.length + 1) * sizeof(char));
    strcpy(S1.ch, ptr);
    StrAssign(T, strcat(S1.ch, S2.ch));
    return OK;
}

Status SubString(HString &Sub, HString S, int pos, int len)
{ //请补充你的代码:用Sub返回串S的第pos个字符起长度为len的子串
    StrAssign(Sub, len);
    strncpy(Sub.ch, S.ch + (pos - 1), len);
    Sub.ch[len] = '\0';
    return OK;
}

void getNext(HString &P)
{
    //指针k具有很重要的意义，它代表目前匹配到的最长相同前缀
    //而指针i的意义则是目前索引到的最长字符串
    for (int i = 1, k = 0; i < P.length; i++)
    {
        while (k && P.ch[k] != P.ch[i])
            k = Next[k - 1]; //如若不匹配就一直回退
        if (P.ch[k] == P.ch[i])
            k++;
        Next[i] = k; //匹配就接着查询下一位
    }
}

void Index_KMP(HString &S, HString &P, int pos) //主函数，参考课本 Pg 82
{                                               //请补充你的代码: 实现KMP算法，返回子串T在主串S中第pos个字符之后的位置。
                                                //若不存在，则函数值为0，其中，T非空，1<=pos<=StrLength(S)
    bool succ = false;
    getNext(P);
    for (int i = pos, k = 0; i < S.length; i++)
    {
        while (k && P.ch[k] != S.ch[i])
            k = Next[k - 1]; //如若不匹配就一直回退
        if (P.ch[k] == S.ch[i])
            k++;
        if (k == P.length)
        {
            succ = true;
            cout << i - P.length + 2 << endl;
            // k=Next[k-1];//为了得到所有匹配的位置
        }
    }
    if (!succ)
        cout << -1 << endl;
}
//以下可以根据需要定义自己的函数

//主函数
int main(int argc, char *argv[])
{
    //输出你的姓名和学号
    cout<<name<<endl<<id<<endl;

    char *str1 = "I am from Anhui University.";
    char *str2 = "I am 20 years old!";
    HString S1, S2, S3, Sub;

    //请补充你的代码: 调用StrAssign()，用str1赋值给S1，str2赋值给S2，并且屏幕输出S1和S2 (S1:I am from Anhui University. S2: I am 20 years old! )
    StrAssign(S1, str1);
    StrAssign(S2, str2);
    cout << "S1:" << S1.ch << endl;
    cout << "S2:" << S2.ch << endl;
    //请补充你的代码：调用Concat()，联接S1和S2，生成S3，并且屏幕输出S3 (S3:I am from Anhui University. I am 20 years old!)
    Concat(S3, S1, S2);
    cout << "S3:" << S3.ch << endl;
    //请补充你的代码：调用SubString(Sub,S1,11,5),屏幕输出Sub (Sub: Anhui)
    SubString(Sub, S1, 11, 5);
    cout << "Sub:" << Sub.ch << endl;
    //请补充你的代码：调用Index_KMP（S3,Sub,1）,屏幕输出Sub在S3出现的位置 （11）
    cout << "pos:";
    Index_KMP(S3, Sub, 1);
    //请补充你的代码：调用ClearString，释放S1,S2,S3,Sub
    ClearString(S1);
    ClearString(S2);
    ClearString(S3);

    system("pause");
    return 1;
}
