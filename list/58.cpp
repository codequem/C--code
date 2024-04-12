#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void Next(char T[], int next[]);

int main (void)
{
    char *pat = "1abcaabbabcabaacbacba";
    int next[60];
    Next(pat, next);
    int x;
    cin>>x;
    return 0;
}
void Next(char T[], int next[])
{
    int i = 1;
    int k = 0;
    next[0] = 0;
    while (i < strlen(T))
    {
        //请在下面补充代码
        while (k && T[k] != T[i])
            k = next[k - 1]; //如若不匹配就一直回退
        if (T[k] == T[i])
            k++;
        next[i] = k; //匹配就接着查询下一位
        i++;
    }
    for (i = 1; i < strlen(T); i++)
    {
        printf("%d", next[i]);
    }
}