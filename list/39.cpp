#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
set<int> us;
void f(int a,int b)
{
    if(us.find(a)==us.end()&&a<=1000000)
    {
        us.insert(a);
        f(a*2+1,a*3+1);
    }
    if(us.find(b)==us.end()&&b<=1000000)
    {
        us.insert(b);
        f(b*2+1,b*3+1);
    }
    return;
};
int main (void)
{
    int k,x;
    char w;
    cin>>k>>w>>x;
    f(k,k);
    if(us.find(k)!=us.end())
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}