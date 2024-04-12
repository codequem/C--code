// 写程序计算给定多项式f(x)= sum(9 i=0)i*x^i在给定点x=1.1处的值f(1.1)
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MaxN 10  // 多项式最大项数，即多项式阶数+1
#define MaxK 11 // 被测函数最大被调用次数

clock_t start, stop;
double duration;
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);
int i;

// 第一次运行结果都是零，因为程序运行太快，不到一个tick
// 利用重复，多跑几次测tick

double f1(int n, double a[], double x)
{
    double p = a[0];
    for (i = 1; i <= n; i++)
        p += (a[i] * pow(x, i));
    return p;
}

double f2(int n, double a[], double x)
{
    double p = a[n];
    for (i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    return p;
}

int main(void)
{
    // int i;
    double a[MaxN];
    for (i = 0; i < MaxN; i++)
    {
        a[i] = (double)i;
        printf("%d",i);
    }
        

    start = clock();
    for (i = 0; i < MaxK; i++)
        // 重复调用函数函数以获得充分多的时钟打点数
        f1(MaxN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MaxK;
    printf("tick1 = %f\n", (double)(stop - start));
    printf("duration1= %6.2e\n", duration);

    start = clock();
    for (i = 0; i < MaxK; i++)
        // 重复调用函数函数以获得充分多的时钟打点数
        f2(MaxN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MaxK;
    printf("tick2 = %f\n", (double)(stop - start));
    printf("duration2 = %6.2e\n", duration);

    return 0;
}
