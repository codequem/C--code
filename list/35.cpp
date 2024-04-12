#include <iostream>
#define N 100005
int q[N],t[N];
using namespace std;
void merge_sort(int q[],int s,int e);
void merge_sort(int q[],int s,int e)
{
    if(e<=s) return;
    int mid=(e+s)>>1;
    merge_sort(q,s,mid),merge_sort(q,mid+1,e);//咱先给他分成一小块一小块
    
    int k=0,i=s,j=mid+1;
    while(i<=mid&&j<=e)
    {
        if(q[i]<=q[j])
        t[k++]=q[i++];
        else
        t[k++]=q[j++];
    }
    while(i<=mid)
    t[k++]=q[i++];
    while(j<=e)
    t[k++]=q[j++];
    for(int i=s,j=0;i<=e;i++,j++)
    q[i]=t[j];
}

int main (void)
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    cin>>q[i];
    merge_sort(q,0,num-1);
    for(int i=0;i<num;i++)
    cout<<t[i]<<' ';
    int x;
    cin>>x;
    return 0;
}