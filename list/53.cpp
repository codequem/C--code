//--------------------利用二叉树的链式存储结构实现树的先序、中序、后续遍历------------------------------------
#include <iostream>
#include <stdlib.h>
#include "Timer.cpp"
#include <stack>
#include <string.h>
#include <string>
#include <windows.h>

using namespace std;
//改成自己的名字和学号
string name = "程一帆";
string id = "E22214111" ;

//二叉树的二叉链表存储表示
typedef struct BiTNode//参考书Pg. 127 
{
	char data;//结点元素
	struct BiTNode * lchild,*rchild;//左右孩子节点
}BiTNode,*BiTree;

//将中缀表达式转换为后缀表达式,注意运算符有优先级
void TransLate(string& In,string& Post)
{
    stack<char> S;
    for(int i=0;i<In.length();i++)
    {
        if(isalpha(In[i]))
        {
            Post+=In[i];
        }
        else
        {
            if(In[i]=='(')
            {
                S.push(In[i]);
            }
            else if(In[i]==')')
            {
                while(S.top()!='(')
                {
                    Post+=S.top();
                    S.pop();
                }
                S.pop();
            }
            else if(In[i]=='+'||In[i]=='-')
            {
                while(!S.empty()&&S.top()!='(')
                {
                    Post+=S.top();
                    S.pop();
                }
                S.push(In[i]);
            }
            else if(In[i]=='*'||In[i]=='/')
            {
                while(!S.empty()&&S.top()!='('&&S.top()!='+'&&S.top()!='-')
                {
                    Post+=S.top();
                    S.pop();
                }
                S.push(In[i]);
            }
        }
    }
    while(!S.empty())
    {
        Post+=S.top();
        S.pop();
    }
}

//根据后缀表达式建立二叉树T
bool CreateInBiTree(BiTree &T,string Post)
{
    stack<BiTree> S;
    for(int i=0;i<Post.length();i++)
    {
        //如果不是运算符，就为它建立一个节点，加入栈中
        if(isalpha(Post[i]))
        {
            BiTree p=(BiTree)malloc(sizeof(BiTNode));
            p->data=Post[i];
            p->lchild=NULL;
            p->rchild=NULL;
            S.push(p);
        }
        //如果是运算符，就从栈中取出两个节点，作为它的左右孩子，然后再将它加入栈中
        else
        {
            BiTree p=(BiTree)malloc(sizeof(BiTNode));
            p->data=Post[i];
            p->rchild=S.top();
            S.pop();
            p->lchild=S.top();
            S.pop();
            S.push(p);//这里加入的时机上就是一个小表达式树了
        }
    }
    T=S.top();//最后在栈顶的就是根节点
    return true;
}

//先序遍历二叉树T，输出T的先序序列
bool PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return false;
    cout<<T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return true;
}

//中序遍历二叉树T，输出T的中序序列
bool InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return false;
    InOrderTraverse(T->lchild);
    cout<<T->data;
    InOrderTraverse(T->rchild);
    return true;
}

//后序遍历二叉树T，输出T的后序序列
bool PostOrderTraverse(BiTree T)
{
    if(T==NULL)
        return false;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout<<T->data;
    return true;
}

//销毁二叉树T
bool DestroyBiTree(BiTree &T)
{
    if(T==NULL)
        return false;
    if(T->lchild!=NULL)
        DestroyBiTree(T->lchild);
    if(T->rchild!=NULL)
        DestroyBiTree(T->rchild);
    free(T);
    return true;
}
//以下可以根据需要定义自己的函数

//主函数
int main(int argc,char* argv[])
{
    Timer t;
	//输出你的姓名和学号
	cout<<name<<endl<<id<<endl;
	BiTree T;
	//请补充你的代码：初始化T， 建立一个如参考书Pg.129 图6.9的二叉树，其中序序列为：a+b*(c-d)-e/f
    cout<<"请输入二叉树的中序序列:";
    string InOrder;
    cin>>InOrder;
    string PostOrder;
    TransLate(InOrder,PostOrder);
    CreateInBiTree(T,PostOrder);
	//请补充你的代码：请按先序遍历T，并且在屏幕上输出T的先序序列：- + a * b - c d / e f
	cout<<"先序遍历为:";
    PreOrderTraverse(T);
    cout<<endl;
	//请补充你的代码：请按中序遍历T，并且在屏幕上输出T的中序序列：a + b * c - d - e / f
    cout<<"中序遍历为:";
    InOrderTraverse(T);
    cout<<endl;
	//请补充你的代码：请按后序遍历T，并且在屏幕上输出T的后序序列：a b c d - * + e f / -
    cout<<"后序遍历为:";
    PostOrderTraverse(T);
    cout<<endl;
	//请补充你的代码：释放T
    DestroyBiTree(T);

    system("pause");
	return 1;
}
