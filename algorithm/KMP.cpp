/*2022年12月25日11:39:22
KMP算法*/
#include <iostream>
#include <string>
#define N 1000005
using namespace std;

int Next[N];
void getNext(const string& P);
void KMP(const string &S,const string &P);

int main (void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    string in,test;
    cin>>in;
    cin>>test;
    KMP(in,test);
    for(int i=0;i<test.length();i++)
    cout<<Next[i]<<' ';
    int x;
    cin>>x;
    return 0;
}

void getNext(const string& P)
{
    //指针k具有很重要的意义，它代表目前匹配到的最长相同前缀
    //而指针i的意义则是目前索引到的最长字符串
    for(int i=1,k=0;i<P.length();i++)
    {
        while(k&&P[k]!=P[i]) k=Next[k-1];//如若不匹配就一直回退
        if(P[k]==P[i]) k++;
        Next[i]=k;//匹配就接着查询下一位
    }
}
void KMP(const string &S,const string &P)
{
    bool succ=false;
    getNext(P);
    for(int i=0,k=0;i<S.length();i++)
    {
        while(k&&P[k]!=S[i]) k=Next[k-1];//如若不匹配就一直回退
        if(P[k]==S[i]) k++;
        if(k==P.length()) 
        {
            succ=true;
            cout<<i-P.length()+1<<endl;
            k=Next[k-1];//为了得到所有匹配的位置
        }
    }
    if(!succ)
    cout<<-1<<endl;
}