#include <iostream>
#include <windows.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
LNode* CreateList(int num)
{
	LNode *head=NULL;
	LNode *tail=NULL;
	LNode *p;
	char c;
	for(int i=0;i<num;i++)
	{
		p=new LNode;
		scanf("%d",&p->data);
		if(head==NULL){
			head=p;
			tail=p;
		}else{
			tail->next=p;
			tail=p;
		}
	}
    tail->next=NULL;
	return head; 
}
void Difference(LinkList &La,LinkList Lb)
{
	LNode *p,*q,*pre;
	pre=La;
	p=La;
	while(p)
	{
		q=Lb;
		while(q&&(q->data!=p->data))
		    q=q->next;
		if(q){
			pre->next=p->next;
			delete p;
			p=pre->next;
		}else{
			pre=p;
			p=p->next;
		}
	}
}
void print(LinkList L)
{
	LNode *p=L;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next; 
	}
}
int main()
{
	LNode *La,*Lb;
	La=CreateList(10);
	Lb=CreateList(5);
	Difference(La,Lb);
	print(La);
    system("pause");
	return 0;
}
