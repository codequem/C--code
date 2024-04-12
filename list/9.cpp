#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int find_min(long long x,const vector<long long>&);
int find_max(long long x,const vector<long long>&);

int main (void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,c;
    cin>>n>>c;
    int sum=0;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        int te_1=find_min(arr[i]+c,arr);
        int te_2=find_max(arr[i]+c,arr);
        if(te_1==-1)
        continue;
        else
        sum+=te_2-te_1+1;
    }
    cout<<sum<<endl;
    return 0;
}

int find_min(long long x,const vector<long long>& arr)
{
    int l=0,r=arr.size()-1;
    while(l<r)
    {
        int mid=l+(r-l)/2;//以防r+l越界
        if(arr[mid]>=x)
        r=mid;
        else
        l=mid+1;
    }
    if(arr[l]==x)
    return l;
    else
    return -1;
}

int find_max(long long x,const vector<long long>& arr)
{
    int l=0,r=arr.size()-1;
    while(l<r)
    {
        int mid=l+(r-l+1)/2;//同上
        if(arr[mid]>x)
        r=mid-1;
        else
        l=mid;
    }
    if(arr[r]==x)
    return r;
    else
    return -1;
}