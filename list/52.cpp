#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <windows.h>

#define Ele_Type char

using namespace std;

vector<Ele_Type> v;

typedef struct Binary_Tree_Node
{
    Binary_Tree_Node *left;
    Binary_Tree_Node *right;
    Ele_Type data;

} Binary_Tree_Node;

typedef Binary_Tree_Node *Binary_Tree;
typedef Binary_Tree_Node *Position;

void Ini(Binary_Tree &Tree)
{
    Tree = (Binary_Tree_Node *)malloc(sizeof(Binary_Tree_Node));
    Tree->left = Tree->right = nullptr;
    Tree->data = '#';
}

void Init(Binary_Tree &Tree, Ele_Type value)
{
    Tree = (Binary_Tree_Node *)malloc(sizeof(Binary_Tree_Node));
    Tree->left = Tree->right = nullptr;
    Tree->data = value;
}

void Insert(Binary_Tree &Tree, Ele_Type value)
{
    if (Tree == nullptr)
        Init(Tree, value);
    else if (Tree->left == nullptr)
        Insert(Tree->left, value);
    else
        Insert(Tree->right, value);
}

int count_child(Binary_Tree &Tree)
{
    if (Tree == nullptr)
        return 0;
    if (Tree->left == nullptr && Tree->right == nullptr)
        return 1;
    return count_child(Tree->left) + count_child(Tree->right);
}

void Print_route(Binary_Tree_Node *Tree, Ele_Type value,string& ans)
{
    string t=" -> ";
    if(Tree==nullptr)
    {
        return;
    }
    if(Tree->data==value)
    {
        ans.erase(ans.length()-4);
        cout<<ans<<endl;
        return;
    }
    else
    {
        if(Tree->left!=nullptr)
        {
            string tem=ans;
            ans+=Tree->left->data;
            ans+=t;
            Print_route(Tree->left,value,ans);
            ans=tem;
        }
        if(Tree->right!=nullptr)
        {
            string tem=ans;
            ans+=Tree->right->data;
            ans+=t;
            Print_route(Tree->right,value,ans);
            ans=tem;
        }
    }
}

void Destory(Binary_Tree &Tree)
{
    if (Tree != nullptr)
    {
        Destory(Tree->left);
        Destory(Tree->right);
        free(Tree);
    }
}

void PreOrder(Binary_Tree_Node *Tree)
{
    if (Tree == nullptr)
        return;
    v.push_back(Tree->data);
    PreOrder(Tree->left);
    PreOrder(Tree->right);
}

bool compare(Binary_Tree_Node*  th,Binary_Tree_Node *comp) //判断两棵树是否相等
{//先序遍历一样就相同
    PreOrder(th);
    vector<Ele_Type> temp(v);
    v.clear();
    PreOrder(comp);
    bool res = true;
    for (auto i = v.begin(), j = temp.begin(); i != v.end() && j != temp.end(); i++, j++)
    {
        if (*i == (*j))
            continue;
        else
        {
            res = false;
            break;
        }
    }
    return res;
};

void InOrder(Binary_Tree_Node *root, string &In)
{
    if (root)
    {
        InOrder(root->left, In);
        In += root->data;
        InOrder(root->right, In);
    }
}
void Print_Tree(Binary_Tree_Node *Tree)
{
    queue<Binary_Tree> q;
    q.push(Tree);
    string InOrd;
    InOrder(Tree, InOrd); //获得中序遍历序列
    while (!q.empty())
    {
        vector<Binary_Tree> cache;
        //把处在同一行的节点拉出来
        while (!q.empty())
        {
            cache.push_back(q.front());
            q.pop();
        }
        string line = "                           ";
        for (auto p : cache)
            if (p)
            {
                //找当前节点中序遍历位置
                line[InOrd.find(p->data) + 4] = p->data;
                //孩子节点入队
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        cout << line << endl;
    }
}
int main(void)
{
    Binary_Tree T1 = nullptr, T2 = nullptr;
    for (int i = 10; i != 0; i--)
    {
        Insert(T1, 'A' + i);
        Insert(T2, 'A' + i);
    }
    Print_Tree(T1);
    cout << endl;
    Print_Tree(T2);
    cout << endl;
    cout << count_child(T1) << endl;
    cout << count_child(T2) << endl;
    cout << "equal:" << boolalpha << compare(T1,T2) << endl;
    string s="";
    s+=T1->data;
    s+=" -> ";
    Print_route(T1,'D',s);
    system("pause");
    return 0;
}