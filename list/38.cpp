#include <iostream>
#include <windows.h>
#define Max 1000
using namespace std;

typedef struct node{
    int element;
    struct node* next;
}node;
typedef node* List;
int record[Max];

void ini(List& L)
{
    L=new node;
    L->next=nullptr;
    return; 
}

void del(List& L)
{
    node *p;
    p=L;
    while(L->next!=nullptr)
    {
        p=L->next;
        delete L;
        L=p;
    }
    delete L;
    return;
}

void delvalue(List& L,int check)
{
    node *p=L->next;
    node *q=L;
    if(L->next==nullptr)
    return;
    while(p->next!=nullptr)
    {
        if(p->element==check)
        {
            q->next=p->next;
            delete(p);
            p=q->next;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
    if(p->element==check)
    {
        q->next=nullptr;
        delete(p);
    }
}

void crelist(List &L,int n)
{
    node * f,* s;
    int ele;
    f=L->next,
    s=L;
    for(int i=0;i<n;i++)
    {
        f=new node;
        f->next=nullptr;
        cin>>ele;
        f->element=ele;
        s->next=f;
        s=f;
        f=f->next;
    }
    return;
}

void print(List L)
{
    int num=0;
    node * p=L;
    while(p->next!=nullptr)
    {
        cout<<(++num)<<":->"<<p->next->element<<endl;
        p=p->next;
    }
}

void merge_list(List &La,List &Lb)
{
    if(La->next==nullptr||Lb->next==nullptr)
    return;
    node * p,*q;
    p=La->next;q=Lb->next;
    while(p->next!=nullptr)
    {
        delvalue(Lb,p->element);
        p=p->next;
    }
    delvalue(Lb,p->element);
    p=La->next;
    if(Lb->next==nullptr)
    return;
    while(p!=nullptr&&q!=nullptr)
    {
        if(p->element<q->element)
        {
            while(p->next!=nullptr&&p->next->element<q->element)
            p=p->next;
            {
                node *temp=q->next;
                q->next=p->next;
                p->next=q;
                q=temp;
            }
        }
        else
        {
            while(q->next!=nullptr&&q->next->element<q->element)
            q=q->next;
            node *temp=p->next;
            p->next=q->next;
            q->next=p;
            p=temp;
        }
    }
}

void x_and_y(List &La,List Lb)
{
    int count=0;
    if(Lb->next==nullptr||La->next==nullptr)
    {
        del(La);
        return;
    }
    Lb=Lb->next;
    node *p=La->next;
    while(Lb!=nullptr)
    {
        while(p!=nullptr)
        {
            if(Lb->element==p->element)
            {
                record[count++]=Lb->element;
            }
            p=p->next;
        }
        Lb=Lb->next;
        p=La->next;
    }
    p=La->next;
    int i=0;
    node *q=La;
    while(p!=nullptr)
    {
        if(p->element!=record[i])
        {
            delvalue(La,p->element);
            p=q->next;
        }
        else
        {
            p=p->next;
            q=q->next;
            i++;
        }
    }
}

void reverse(List &L)
{
    if(L->next==nullptr||L->next->next==nullptr)
    return;
    node*p,*q;
    p=L->next,q=p->next;
    p->next=nullptr;
    while(q!=nullptr)
    {
        if(q->next!=nullptr)
        {
            node* temp=q->next;
            q->next=p;
            p=q;
            q=temp;
        }
        else
        {
            q->next=p;
            L->next=q;
            q=nullptr;
        }
    }
}

int main (void)
{
    List La,Lb;
    ini(La);
    ini(Lb);
    crelist(La,5);
    crelist(Lb,5);
    print(La);
    print(Lb);
    /* x_and_y(La,Lb);
    print(La); */
    merge_list(La,Lb);
    print(La);
    /* reverse(La);
    print(La); */
    //system("pause");
    return 0;
}