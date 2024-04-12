#include <iostream>
#include <string>

using namespace std;

typedef struct Trie
{
    Trie* next[26]={nullptr};
    bool flag=false;
}Trie;

void insert(string in,Trie& T);
bool serach(string in,Trie& T);

int main (void)
{
    string in,q;
    int n,q_n;
    Trie T1,T2;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>in;
        insert(in,T1);
    }
    cin>>q_n;
    for(int i=0;i<q_n;i++)
    {
        cin>>q;
        if(serach(q,T1))
        {
            if(serach(q,T2))
            {
                cout<<"REPEAT"<<endl;
            }
            else
            {
                cout<<"OK"<<endl;
            }
            insert(q,T2);
        }
        else
        {
            cout<<"WRONG"<<endl;
        }
    }
    return 0;
}

void insert(string in,Trie& T)
{
    Trie* S=&T;
    for(int i=0;i<in.length();i++)
    {
        char ch=in[i];
        if(S->next[ch-'a']==nullptr)
        {
            S->next[ch-'a']=new Trie;
        }
        S=S->next[ch-'a'];
    }
    S->flag=true;
}

bool serach(string in,Trie& T)
{
    Trie* S=&T;
    for(int i=0;i<in.length();i++)
    {
        char ch=in[i];
        if(S->next[ch-'a']==nullptr)
        return false;
        S=S->next[ch-'a'];
    }
    return (S->flag);
}