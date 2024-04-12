6#include <iostream>
#include <cstdio>
#include <cstring>

int cmp_int(const void* _a , const void* _b);
using namespace std;

int main (void)
{
    int record[26];
    for(int i=0;i<26;i++)
    record[i]=0;
    char string[10000];
    gets(string);
    for(int i=0;i<strlen(string);i++)//strlen可以用while循环自己实现一个
    record[string[i]-'a']++;
    int rr[26];
    for(int i=0;i<26;i++)
    rr[i]=record[i];
    qsort(record,26,sizeof(int),cmp_int);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(record[i]==rr[j])
            {
                printf("%c:%d\n",'a'+j,record[i]);
                rr[j]=-1;
                break;
            }
        }
    }
    return 0;
}

int cmp_int(const void* _a , const void* _b)
{
    int* a = (int*)_a;
    int* b = (int*)_b;
    return *b - *a;
}