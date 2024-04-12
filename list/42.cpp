#include <cstdio>
#include <cstring>
#include <iostream>

static const int LEN = 1004;
int a[LEN], b[LEN];
using namespace std;

void clear(int a[])
{
    for (int i = 0; i < LEN; ++i)
        a[i] = 0;
}

void read(int a[])
{
    static char s[LEN + 1];
    scanf("%s", s);
    clear(a);
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
        a[len - i - 1] = s[i] - '0';
}

int main (void)
{
    read(a);
    for(int i=0;i<10;i++)
    cout<<a[i]<<' ';
    int x;
    cin>>x;
    return 0;
}