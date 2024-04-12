#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int nums;
    cin>>nums;
    while(nums--)
    {
        vector<int> array(3);
        cin>>array[0]>>array[1]>>array[2];
        sort(array.begin(),array.end(),greater<int>());
        cout<<array[1]<<endl;
    }
    return 0;
}