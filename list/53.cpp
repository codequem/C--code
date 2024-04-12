//--------------------���ö���������ʽ�洢�ṹʵ�������������򡢺�������------------------------------------
#include <iostream>
#include <stdlib.h>
#include "Timer.cpp"
#include <stack>
#include <string.h>
#include <string>
#include <windows.h>

using namespace std;
//�ĳ��Լ������ֺ�ѧ��
string name = "��һ��";
string id = "E22214111" ;

//�������Ķ�������洢��ʾ
typedef struct BiTNode//�ο���Pg. 127 
{
	char data;//���Ԫ��
	struct BiTNode * lchild,*rchild;//���Һ��ӽڵ�
}BiTNode,*BiTree;

//����׺���ʽת��Ϊ��׺���ʽ,ע������������ȼ�
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

//���ݺ�׺���ʽ����������T
bool CreateInBiTree(BiTree &T,string Post)
{
    stack<BiTree> S;
    for(int i=0;i<Post.length();i++)
    {
        //����������������Ϊ������һ���ڵ㣬����ջ��
        if(isalpha(Post[i]))
        {
            BiTree p=(BiTree)malloc(sizeof(BiTNode));
            p->data=Post[i];
            p->lchild=NULL;
            p->rchild=NULL;
            S.push(p);
        }
        //�������������ʹ�ջ��ȡ�������ڵ㣬��Ϊ�������Һ��ӣ�Ȼ���ٽ�������ջ��
        else
        {
            BiTree p=(BiTree)malloc(sizeof(BiTNode));
            p->data=Post[i];
            p->rchild=S.top();
            S.pop();
            p->lchild=S.top();
            S.pop();
            S.push(p);//��������ʱ���Ͼ���һ��С���ʽ����
        }
    }
    T=S.top();//�����ջ���ľ��Ǹ��ڵ�
    return true;
}

//�������������T�����T����������
bool PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return false;
    cout<<T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return true;
}

//�������������T�����T����������
bool InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return false;
    InOrderTraverse(T->lchild);
    cout<<T->data;
    InOrderTraverse(T->rchild);
    return true;
}

//�������������T�����T�ĺ�������
bool PostOrderTraverse(BiTree T)
{
    if(T==NULL)
        return false;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout<<T->data;
    return true;
}

//���ٶ�����T
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
//���¿��Ը�����Ҫ�����Լ��ĺ���

//������
int main(int argc,char* argv[])
{
    Timer t;
	//������������ѧ��
	cout<<name<<endl<<id<<endl;
	BiTree T;
	//�벹����Ĵ��룺��ʼ��T�� ����һ����ο���Pg.129 ͼ6.9�Ķ�����������������Ϊ��a+b*(c-d)-e/f
    cout<<"���������������������:";
    string InOrder;
    cin>>InOrder;
    string PostOrder;
    TransLate(InOrder,PostOrder);
    CreateInBiTree(T,PostOrder);
	//�벹����Ĵ��룺�밴�������T����������Ļ�����T���������У�- + a * b - c d / e f
	cout<<"�������Ϊ:";
    PreOrderTraverse(T);
    cout<<endl;
	//�벹����Ĵ��룺�밴�������T����������Ļ�����T���������У�a + b * c - d - e / f
    cout<<"�������Ϊ:";
    InOrderTraverse(T);
    cout<<endl;
	//�벹����Ĵ��룺�밴�������T����������Ļ�����T�ĺ������У�a b c d - * + e f / -
    cout<<"�������Ϊ:";
    PostOrderTraverse(T);
    cout<<endl;
	//�벹����Ĵ��룺�ͷ�T
    DestroyBiTree(T);

    system("pause");
	return 1;
}
