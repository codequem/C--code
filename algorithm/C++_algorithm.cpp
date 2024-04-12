/*2023年1月7日12:10:31
来看看C++中的算法函数库吧*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <windows.h>
#include <numeric>//numeric ：数字

using namespace std;
bool check=true;

int main (void)
{
    //函数1：partial_sum();用于计算前缀和,头文件为：<numeric>
    if(check)
    {
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int b[10];
        partial_sum(a, a + 10, b);//这个函数可以直接帮助我们来计算前缀和
        for (int i = 0; i < 10; i++)
            cout<<b[i]<<' ';
        cout<<endl;
    }

    
    system("pause");
    return 0;
}