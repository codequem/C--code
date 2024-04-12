#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;
int main (void)
{
    set<int,greater<int>> s1;
    set<int> s2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        if(t&1) s1.insert(t);
        else s2.insert(t);
    }
    for(auto k=s1.begin();k!=s1.end();k++)
    cout<<*k<<' ';
    for(auto k=s2.begin();k!=s2.end();k++)
    cout<<*k<<' ';
    return 0;
}