/*2023年4月14日17:37:50
高精度计算*/
#include <iostream>
#include <cstdio>
#include <cstring>

static const int LEN = 1004;
int a[LEN], b[LEN], c[LEN];

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

void print(int a[])
{
    int i;
    for (i = LEN - 1; i >= 1; --i)
        if (a[i] != 0)
            break;
    for (; i >= 0; --i)
        putchar(a[i] + '0');
    putchar('\n');
}

void sub(int a[], int b[], int c[]) //高精度减法，只能处理减数a大于被减数b时的情况，但是这个缺点可以很方便的通过加一个负号解决
{
    clear(c);
    for (int i = 0; i < LEN - 1; ++i)
    {
        c[i] += a[i] - b[i];
        if (c[i] < 0)
        {
            c[i + 1] -= 1;
            c[i] += 10;
        }
    }
}

void add(int a[], int b[], int c[]) //高精度加法
{
    clear(c);
    for (int i = 0; i < LEN - 1; ++i)
    {
        c[i] += a[i] + b[i];
        if (c[i] >= 10)
        {
            c[i + 1] += 1;
            c[i] -= 10;
        }
    }
}

void mul_short(int a[], int b, int c[])//高精度-单精度乘法
{
    clear(c);
    for (int i = 0; i < LEN - 1; ++i)
    {
        // 直接把 a 的第 i 位数码乘以乘数，加入结果
        c[i] += a[i] * b;
        if (c[i] >= 10)
        {
            // 处理进位
            // c[i] / 10 即除法的商数成为进位的增量值
            c[i + 1] += c[i] / 10;
            // 而 c[i] % 10 即除法的余数成为在当前位留下的值
            c[i] %= 10;
        }
    }
}