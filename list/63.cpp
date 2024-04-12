#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <set>

using namespace std;

void read();
void write();
void halfSet(int,set<string>&,string);
int N=0;
set<string> s;

int main()
{
    char *str = new char[3];
    read();
    if(N > 1000){
        cout<<"数据超范围！";
        exit(0);
    }
    halfSet(N,s,string(itoa(N,str,10)));
    write();
    return 0;
}

void read()
{
    ifstream ifs;
    ifs.open("C:\\Users\\cyf\\Desktop\\in.txt", ios::in);
    ifs>>N;
    ifs.close();
}

void write()
{
    ofstream ofs;
    ofs.open("C:\\Users\\cyf\\Desktop\\out.txt", ios::out);
    for(auto i = s.begin();i!=s.end();i++)
    ofs << *i << endl;
    ofs << N << endl;
    ofs.close();
}

void halfSet(int n,set<string> &s,string str){
    char *strs = new char[3];
    string mStr;

    for(int i=1;i<=n/2;i++){
        mStr = string(itoa(i,strs,10)) + str;
        s.insert(mStr);
        halfSet(i,s,mStr);
    }
}
