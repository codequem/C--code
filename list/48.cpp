#include <iostream>
#include <string>
using namespace std;
int nextval[10000];
void get_nextval(string T,int nextval[]);

int main(void)
{   
    string test;
    cin>>test;
    get_nextval(test,nextval);
    for(int i=1;i<=10;i++)
        cout<<nextval[i]<<' ';
    int x;
    cin>>x;
    return 0;
}

void get_nextval(string T,int nextval[])
{
    int i=1,j=0;
    nextval[1]=0;
    while(i<T.length())
    {
        if((j==0)||T[i]==T[j])
        {
            ++i;++j;
            if(T[i]!=T[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
    }
}