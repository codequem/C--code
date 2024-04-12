#include <iostream>
#include <algorithm>

using namespace std;

int depth,ans[100];
int maxn=1;

void dfs(int target);
void dfs(int target)
{
    if(target<=0&&depth!=1)
    {
        for(int i=0;i<depth;i++)
        {
            if(i==0)
            {
                cout<<ans[i];
                continue;
            }
            cout<<'+'<<ans[i];
            if(i==depth-1)
            cout<<endl;
        }
        return;
    }
    for(int i=maxn;i<=target;i++)
    {
        int re=maxn;
        maxn=max(maxn,i);
        ans[depth++]=i;
        dfs(target-i);
        maxn=re;
        depth--;
    }
};

int main (void)
{
    int n;
    cin>>n;
    dfs(n);
    return 0;
}