#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long 
#define ios ios::sync_with_stdio(false),cin.tie(nullptr)

using namespace std;
int main (void)
{
    ios;
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> sum(n+1);
    vector<int> f(7,-1);
    vector<int> e(7,-1);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum[i+1]=(sum[i]+arr[i])%7;//这里用了一个定理
        //(a-b)mod c==0 -->amodc==bmodc
    }
    for(int i=n-1;i>=0;i--)
    f[sum[i]]=i;
    for(int i=0;i<n;i++)
    e[sum[i]]=i;
    int ans=0;
    for(int i=0;i<7;i++)
    {
        if(f[i]!=-1&&e[i]!=-1)
        ans=max(ans,e[i]-f[i]);
    }
    cout<<ans<<endl;
    return 0;
}