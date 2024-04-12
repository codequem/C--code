/*2022年12月26日11:45:12
钢条切割问题*/
#include <bits/stdc++.h>
using namespace std;
int main (void)
{
    const int price[10]={1,5,8,9,10,17,17,20,24,30};
    int dp[11];
    for(int i=1;i<=10;i++)
    dp[i]=price[i-1];
    for(int i=2;i<10;i++)
    {
        for(int gap=1;gap<i;gap++)
        dp[i]=max(dp[gap]+dp[i-gap],dp[i]);//这里是分割的所有情况
        //当然dp中初始存放的是未经切割的数值，这也有可能是最大值
    }
    for(int i=1;i<11;i++)
    cout<<dp[i]<<endl;
}