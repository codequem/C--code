#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ios ios::sync_with_stdio(false),cin.tie(nullptr)
#define ll long long

int main (void)
{
    ios;
    ll n,c;
    cin>>n>>c;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll sum=0; 
    for(int i=0;i<n;i++)
    {
        ll l=0,r=n-1;
        ll ans=-1,anss=-1;
        ll target=arr[i]+c;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(arr[mid]==target)
            {
                ans=mid;
                r=mid-1;
            }
            else if(arr[mid]<target)
            l=mid+1;
            else if(arr[mid]>target)
            r=mid-1;
        }
        l=0,r=n-1;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(arr[mid]>target)
            {
                anss=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        if(ans==-1)
        continue;
        if(ans!=-1&&anss==-1)
        {
            sum+=(n-ans);
            continue;
        }
        if(ans!=-1&&anss!=-1)
        {
            sum+=(anss-ans);
            continue;
        }
    }
    cout<<sum<<endl;
    return 0;
}