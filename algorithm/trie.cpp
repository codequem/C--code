/*2022年12月25日11:38:44
字典树的构建，查询*/
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

typedef struct Trie//字典树
{
    bool flag=false;
    Trie *next[26]={nullptr};
    int prefix_num=0;//第一层，也就是空节点这层表示存入的单词数，之后的层代表具有特定前缀的单词数
}Trie;
void insert (string word,Trie& T);//向树里插入单词
bool serach (string word,Trie& T);//查询某个单词是否存在
int prefix_num (string prefix,Trie &T);//查询某个前缀根下有多少词汇

int main (void)
{
    Trie T;
    int n;
    cin>>n;
    int m=n;
    while(m--)
    {
        string in;
        cin>>in;
        insert(in,T);
    }
    m=n;
    while(m--)
    {
        string in;
        cin>>in;
        cout<<serach(in,T)<<endl;
    }
    m=n;
    while(m--)
    {
        string in;
        cin>>in;
        cout<<prefix_num(in,T)<<endl;
    }
}

void insert (string word,Trie& T)
{
    Trie *temp=&T;
    for(int i=0;i<word.length();i++)
    {
        char c=word[i];
        if(temp->next[c-'a']==nullptr) temp->next[c-'a']=new Trie;
        temp->prefix_num++;
        temp=temp->next[c-'a'];
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
        if(temp->next[ch-'a']==nullptr) return false;
        temp=temp->next[ch-'a'];
    }
    return temp->flag?true:false;
}

int prefix_num (string prefix,Trie &T)
{
    Trie *temp=&T;
    int sum=0;
    for(int i=0;i<prefix.length();i++)
    {
        if(temp->next[prefix[i]-'a']==nullptr) return 0;
        temp=temp->next[prefix[i]-'a'];
    }
    return temp->prefix_num;
}
