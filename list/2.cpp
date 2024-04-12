/*2022年11月27日15:13:33
对二维数组依据某一项排序*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct input{
    int l;
    int r;
    int length;
}input;

int cmp(const input&a,const input&b);

int main (void)
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    int record=t;
    int answer=0;
    input inputs[record];
    for(int i=0;i<record;i++)
    {
        cin>>inputs[i].l>>inputs[i].r;
        inputs[i].length=inputs[i].r-inputs[i].l;
    }
    sort(inputs,inputs+record,cmp);
    bool time[10000];
    for(int i=0;i<=10000;i++)
    time[i]=false;
    for(int i=0;i<record;i++)
    {
        bool flag=true;
        for(int k=inputs[i].l;k<inputs[i].r;k++)
        {
            if(time[k])
            {
                flag=false;break;
            }
        }
        if(flag)
        {
            for(int j=inputs[i].l;j<inputs[i].r;j++)
            time[j]=true;
            answer++;
        }
    }
    cout<<answer<<endl;
    return 0;
}

int cmp(const input&a,const input&b)
{
    return (a.length<b.length);
}