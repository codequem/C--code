#include <iostream>
#include <windows.h>
#define elem int
using namespace std;

typedef struct node{
    elem val;
    node *next;
}node;

typedef struct circular_list
{
    node* tail;
    circular_list()
    {
        node* head=new node;
        tail=head;
        head->next=head;
        head->val=INT16_MIN;
    }
}circular_list;
typedef circular_list queue;

void push(elem val,circular_list& list);
elem pop(circular_list& list);
bool Is_empty(circular_list list);
void del_que(circular_list list);
void print(circular_list list);


int main (void)
{
    queue q;
    for(int i=0;i<10;i++)
    {
        int val;
        cin>>val;
        push(val,q);
    }
    print(q);
    pop(q);
    int val;
    cin>>val;
    push(val,q);
    print(q);
    pop(q);
    cin>>val;
    push(val,q);
    print(q);
    pop(q);
    cin>>val;
    push(val,q);
    print(q);
    pop(q);
    cin>>val;
    push(val,q);
    print(q);
    pop(q);
    cin>>val;
    push(val,q);
    print(q);
    system("pause");
}

bool Is_empty(circular_list list)
{
    return list.tail->next==list.tail;
}

void print(circular_list list)
{
    if(Is_empty(list)) return;
    node *temp=list.tail->next->next;
    while(temp!=list.tail)
    {
        cout<<temp->val<<' ';
        temp=temp->next;
    }
    cout<<temp->val<<endl;
}

void push(elem val,circular_list& list)
{
    node *temp=new node;
    temp->val=val;
    temp->next=list.tail->next;
    list.tail->next=temp;
    list.tail=temp;
}

elem pop(circular_list& list)
{
    if(Is_empty(list))
    {
        cout<<"The queue is empty!!!"<<endl;
        return -1;
    }
    else
    {
        node* temp=list.tail->next;
        node* p=temp->next;
        temp->next=p->next;
        elem ans=p->val;
        delete p;
        return ans;
    }
}

void del_que(circular_list& list)
{
    node *temp=list.tail->next;
    while(temp!=list.tail)
    {
        node * p=temp;
        temp=temp->next;
        delete p;
    }
    delete temp;
}