/*2022年12月28日22:13:41
树状数组*/
#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int c[N];

int lowbit(int x){return x & (-x)}; //求解一个数的最低位1的位置   01000100 返回 00000100
void update(int x, int y, int n)
{
    for (int i = x; i <= n; i += lowbit(i)) // x为更新的位置,y为更新后的数,n为数组最大值
        c[i] += y;
}
int getsum(int x)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main(void)
{
}