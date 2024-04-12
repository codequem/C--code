#include <iostream>
#include <cmath>

using namespace std;


int main (void)
{   ios::sync_with_stdio(false);
    int l,r;
    while(cin.peek()!=EOF)
    {
        cin>>l>>r;
        bool flag=false;
        for(int i=l;i<=r;i++)
        for(int j=i;j<=r&&(i+j>r||i+r>j);j++)
        {
            double record=i*i+j*j;
            double sss=sqrt(record);
            if(sss>r)
            break;
            int ss=(int)sss;
            if(sss==ss&&ss<=r)
            {
                cout<<i<<' '<<j<<' '<<ss<<endl;
                flag=true;
            }
        }
        if(!flag)
        cout<<"NO"<<endl;
    }
    return 0;
}