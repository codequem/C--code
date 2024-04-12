/*2022年12月4日21:15:46
贪心1*/

//这一题贪心的原则是
//每一次选择都选取结束时间较早的活动
//这样每一次选择都可以为剩下的活动留下最长的时间，在每次选择后最终得到的就是最优解

#include <iostream>
#include <algorithm>

using namespace std;

#define ios ios::sync_with_stdio(false),cin.tie(nullptr)

typedef struct act{
    long long int start;
    long long int end;
}act_;

int cmp(act x,act y);

int main (void)
{
    ios;
    int n;
    cin>>n;
    act_ act[n];
    for(int i=0;i<n;i++)
    cin>>act[i].start>>act[i].end;
    sort(act,act+n,cmp);
    int sum=1;
    int now=0;
    for(int i=1;i<n;i++)
    {
        if(act[i].start>=act[now].end)
        {
            sum++;
            now=i;
        }
    }
    cout<<sum;
    return 0;
}

int cmp(act x,act y){
    return x.end<y.end;
}