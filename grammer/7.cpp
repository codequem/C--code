/*2022年10月26日15:43:52
介绍使用取整函数
floor函数，ceil函数，round函数*/
#include <math.h>
#include <iostream>
#include <cstdio>

using namespace std;
int main(void)
{
    double a, b, c, d;
    puts("请输入一个数");
    cin >> a ;
    cout << "不大于这个数的最大整数为：" << floor(a) << endl;
    cout << "不小于这个数的最小整数为：" << ceil(a) << endl;
    cout << "四舍五入这个数为：" << round(a) << endl;
    //cout << "向零取整得到的整数为：" << fix(d) << endl;
    //c的数学库中没有这个函数
    return 0;
}