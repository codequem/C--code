#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
int getnum(char x)
{
    if (x >= 'A' && x <= 'Z')
        return x - 'A';
    else if (x >= 'a' && x <= 'z')
        return x - 'a' + 26;
    else
        return x - '0' + 52;
}
typedef struct Trie//字典树
{
    bool flag=false;
    Trie *next[62]={nullptr};
    int prefix_num=0;//第一层，也就是空节点这层表示存入的单词数，之后的层代表具有特定前缀的单词数
}Trie;
void insert (string word,Trie& T);//向树里插入单词
bool serach (string word,Trie& T);//查询某个单词是否存在
int prefix_num (string prefix,Trie &T);//查询某个前缀根下有多少词汇

int main (void)
{
    //ios::sync_with_stdio(false),cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        Trie T;
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            string in;
            cin>>in;
            insert(in,T);
        }
        for(int i=0;i<q;i++)
        {
            string in;
            cin>>in;
            cout<<prefix_num(in,T)<<endl;
        }
    }
}

void insert (string word,Trie& T)
{
    Trie *temp=&T;
    for(int i=0;i<word.length();i++)
    {
        char c=word[i];
        if(temp->next[getnum(c)]==nullptr) temp->next[getnum(c)]=new Trie;
        temp->prefix_num++;
        temp=temp->next[getnum(c)];
    }
    temp->flag=true;
    temp->prefix_num++;
}

bool serach (string word,Trie& T)
{
    Trie* temp=&T;
    for(int i=0;i<word.length();i++)
    {
        char ch=word[i];
        if(temp->next[getnum(ch)]==nullptr) return false;
        temp=temp->next[getnum(ch)];
    }
    return temp->flag?true:false;
}

int prefix_num (string prefix,Trie &T)
{
    Trie *temp=&T;
    int sum=0;
    for(int i=0;i<prefix.length();i++)
    {
        char ch=prefix[i];
        if(temp->next[getnum(ch)]==nullptr) return 0;
        temp=temp->next[getnum(ch)];
    }
    return temp->prefix_num;
}
