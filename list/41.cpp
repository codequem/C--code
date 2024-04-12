#include <iostream>
#include <algorithm>

using namespace std;
int ans=10000000;
int ranks[5];
int give[5];
bool use[5];
void dfs(int n)
{
    if(n==5)
    {
        int temp;
        if(ranks[0]!=0&&ranks[3]!=0)
        {
            int first=ranks[0]*100+ranks[1]*10+ranks[2];
            int second=ranks[3]*10+ranks[4];
            int temp=first*second;
            ans=min(ans,temp);
        }
        return;
    }
    for(int i=0;i<5;i++)
    {
        if(!use[i])
        {
            use[i]=true;
            ranks[n]=give[i];
            dfs(n+1);
            use[i]=false;
        }
    }
}

int main(void)
{

    for(int i=0;i<5;i++)
    {
        cin>>give[i];
        use[i]=false;
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}