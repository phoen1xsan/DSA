#include <stdio.h>
#include <stdlib.h>
struct Node {
	int coeff;
	int expo;
	struct Node *next;
};
struct Node *create()
{
	int c,e,n,i=0;
	scanf("%d",&n);
	struct Node *head=(struct Node *)malloc(sizeof(struct Node));
	printf("Enter coeff");
	scanf("%d",&c);
	printf("Enter expo");
	scanf("%d",&e);
	head->expo=e;
	head->coeff=c;
	head->next=NULL;
	struct Node*last=head;
	
	
	for(i=0;i<n-1;i++)
	{
	printf("Enter coeff");
	scanf("%d",&c);
	printf("Enter expo");
	scanf("%d",&e);
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	t->next=NULL;
	t->coeff=c;
	t->expo=e;
	last->next=t;
	last=t;
		
	}
	return head;
	
	
}
struct Node* add(struct Node *p1,struct Node*p2)
{
	struct Node*head,*last;
	struct Node*result=(struct Node *)malloc(sizeof(struct Node));
	result->expo=0;
	result->coeff=0;
	result->next=NULL;
	last=result;
	while(p1!=NULL || p2!=NULL)
	{	
		if(p1->expo==p2->expo)
		{

			struct Node * t=(struct Node *)malloc(sizeof(struct Node));
			t->coeff=p1->coeff+p2->coeff;
			t->expo=p1->expo;
			t->next=NULL;
			last->next=t;
			last=t;
			p1=p1->next;
			p2=p2->next;
			
		}
		if(p1->expo>p2->expo)
		{
			struct Node * t=(struct Node *)malloc(sizeof(struct Node));
			t->coeff=p1->coeff;
			t->expo=p1->expo;
			t->next=NULL;
			last->next=t;
			last=t;
			p1=p1->next;
			
		}
		if(p1->expo<p2->expo){
			struct Node * t=(struct Node *)malloc(sizeof(struct Node));
			t->coeff=p2->coeff;
			t->expo=p2->expo;
			t->next=NULL;
			last->next=t;
			last=t;
			p2=p2->next;
		}
	}
	while(p1!=NULL)
	{
		struct Node * t=(struct Node *)malloc(sizeof(struct Node));
		t->coeff=p1->coeff;
		t->expo=p1->expo;
		t->next=NULL;
		last->next=t;
		last=t;
        p1=p1->next;
	}
	while(p2!=NULL)
	{
		struct Node * t=(struct Node *)malloc(sizeof(struct Node));
		t->coeff=p2->coeff;
		t->expo=p2->expo;
		t->next=NULL;
		last->next=t;
		last=t;
        p2=p2->next;
	}
	return result->next;
	

}
void display(struct Node*first)
{
	struct Node *p=first;
	while(p!=NULL)
	{
		printf("%dx%d ",p->coeff,p->expo);
		p=p->next;
	}
}

struct Node* mulcoeff(struct Node*p1,int coeff,int expo)
{
	struct Node* last;
	struct Node* first=(struct Node *)malloc(sizeof(struct Node));
	first->next=NULL;
	first->coeff=p1->coeff*coeff;
	first->expo=p1->expo+expo;
	last=first;
	p1=p1->next;
	while(p1)
	{
		struct Node* t=(struct Node *)malloc(sizeof(struct Node));
		t->next=NULL;
		last->next=t;
		t->coeff=p1->coeff*coeff;
		t->expo=p1->expo+expo;
		last=t;
		p1=p1->next;
		
	}
	return first;
}
struct Node* mul(struct Node*poly1,struct Node*poly2)
{
	struct Node*p1=poly1;
	struct Node*p2=poly2;
	struct Node*t1=mulcoeff(p2,p1->coeff,p1->expo);
	display(t1);
	p1=p1->next;
	struct Node*t2=mulcoeff(p2,p1->coeff,p1->expo);
	display(t2);
	p1=p1->next;
	struct Node* result=add(p1,p2);
	display(result);
	while(p1)
	{
		struct Node*t3=mulcoeff(p2,p1->coeff,p1->expo);
		result=add(result,t3);
		p1=p1->next;
	}

}
int main()
{
	struct Node * p1=create();
	struct Node * p2=create();
	display(add(p1,p2));
	//display(mul(p1,p2));
	return 0;
}