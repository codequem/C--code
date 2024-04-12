/*2022年12月29日18:32:43
字典树的构建，查询（数组实现）*/
#include <iostream>
#include <string>

using namespace std;

const int N = 100050;//这个值决定的这个字典能存多少字母
int trie[N][26];//实际上数组形式的树每一层都只存了一个字母
//trie[上节点编号][下方连接的字母]=下方连接的字符的节点编号
int cnt[N];//记录每一个词的结束节点id
int prefix_num[N];//记录每一个前缀后面跟了多少单词数
int id;//记录现在已经使用到的节点id

void insert(string s)
{
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int x = s[i] - 'a';
		if (trie[p][x] == 0) trie[p][x] = ++id;
		p = trie[p][x];
        prefix_num[p]++;
	}
	cnt[p]++;
}

int find(string s)
{
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int x = s[i] - 'a';
		if (trie[p][x] == 0)return 0;
		p = trie[p][x];
	}
	return cnt[p];
}

int find_prefix_nums(string s)
{
    int p=0;
    for (int i = 0; i < s.size(); i++)
	{
		int x = s[i] - 'a';
		if (trie[p][x] == 0)return 0;
		p = trie[p][x];
	}
    return prefix_num[p];
}

int main (void)
{
    for(int i=0;i<5;i++)
    {
        string in;
        cin>>in;
        insert(in);
    }
    for(int i=0;i<5;i++)
    {
        string in;
        cin>>in;
        cout<<find(in)<<endl;
    }
    for(int i=0;i<5;i++)
    {
        string prefix;
        cin>>prefix;
        cout<<find_prefix_nums(prefix)<<endl;
    }
    return 0;
}
//我们先后插入单词"abc",“abb”,“bca”,“bc”，那编号就是这样
/*
trie[0][0]=1;trie[0][1]=5;//0号节点指向代表字符‘a'的节点1，和字符‘b’的节点2
trie[1][1]=2;//代表字符‘a'的节点1指向代表字符‘b’的节点2
trie[2][1]=4;trie[2][2]=3;//代表字符‘b’的节点2指向代表字符‘b’的节点4，和字符‘c’的节点3//至此abc,abb存储完毕
trie[5][2]=6;
trie[6][0]=7;
其余trie[i][j]都为0，即空节点；
cnt[4]=cnt[3]=cnt[6]=cnt[7]=1;*///节点3是abc的结束，节点4是abb的结束