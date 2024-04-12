#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

using namespace std;
typedef struct stu{
    string name;
    string year;
    int mouth;
    int day;
}stu;

bool cmd(stu a,stu b)
{
    int ya=stoi(a.year);
    int yb=stoi(b.year);
    if(ya==yb)
    {
        if(a.mouth==b.mouth)
        {
            if(a.day==b.day)
            {
                if(a.name.size()>b.name.size())
                return true;
                if(a.name.size()<b.name.size())
                return false;
                else
                {
                    if(strcmp(a.name.c_str(),b.name.c_str())>=0)
                    return true;
                    else
                    return false;
                }
            }
            else
            return a.day<=b.day;
        }
        else
        return a.mouth<=b.mouth;
    }
    else
    return ya<=yb;
}
bool cmdd(stu a,stu b)
{
    int ya=stoi(a.year.c_str());
    int yb=stoi(b.year.c_str());
    if((ya==yb)&&(a.mouth==b.mouth)&&(a.day==b.day))
    return true;
    else
    return false;
}

int main (void)
{
    bool none=true;
    int num;
    cin>>num;
    stu stus[num];
    int flag[num];
    for(int i=0;i<num;i++){
        cin>>stus[i].name>>stus[i].year>>stus[i].mouth>>stus[i].day;
        flag[i]=0;
    }
    sort(stus,stus+num,cmd);
    for(int i=0;i<num;i++)
    {
        int temp;
        for(int j=i+1;j<num;j++)
        {
            if(cmdd(stus[i],stus[j]))
            {
                flag[i]++;
                temp=j;
            }
            else
            {
                temp=j;
                break;
            }
        }
        if(!flag[i]) continue;
        else i=temp-1;
    }
    for(int i=0;i<num;i++)
    {
        if(flag[i])
        {
            cout<<stus[i].year<<' '<<stus[i].mouth<<' '<<stus[i].day<<' ';
            for(int j=flag[i];j>=0;j--)
            {
                cout<<stus[i+j].name;
                if(j!=0)
                cout<<' ';
            }
            cout<<endl;
            none=false;
        }
        i=i+flag[i];
    }
    if(none) cout<<"No"<<endl;
    int x;
    cin>>x;
    return 0;
}