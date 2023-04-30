#include <stdio.h>
#include <stdlib.h>
struct Node
{
	char data;
	struct Node * next;
	
}*top=NULL;

void push(char x)
{
	struct Node *t;
	t=(struct Node *)malloc(sizeof(struct Node));
	if(t==NULL)
	{
		printf("stack overflow");
	}
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}
char pop()
 {
	struct Node *t;
	char x='z';
	if(top==NULL)
	{
		printf("stack underflow");
	}
	else
	{
		t=top;
		x=t->data;
		top=top->next;
		free(t);
	}
	return x;
}
int isOperand(char x)
{
 if(x=='+' || x=='-' || x=='*' || x=='/'|| x=='^' || x=='%' || x==')')
 return 0;
 else
 return 1;

}
int prec(char x){
	if(x=='+' || x=='-'){
		return 1;
	}
	else if(x=='*' || x=='/'){
		return 2;
	}
	else if(x=='%' || x=='^'){
		return 3;
	}
	else{
		return 0;
	}
}
void postfix(char * infix){
	int i=0;
	while(infix[i]!='\0'){//use while loop
		if(infix[i]=='('){
			push(infix[i]);
			i++;
		}
		else if(isOperand(infix[i])){
			printf("%c",infix[i]);
			i++;
		}
		else if(infix[i]==')'){
			char x=pop();
			while(x!='('){
				printf("%c",x);
				x=pop();
			}
	         i++;
			
		}
		else{
			if(top==NULL){
				push(infix[i++]);
			}
			else if(prec(infix[i])>prec(top->data)){
				push(infix[i++]);
			}
			else{
				printf("%c",pop());	
			}
		}
	}
	while(top!=NULL){
		printf("%c",pop());
	}
	
}
int main()
{
	char *infix="(x+e/f)-g*h^b+(a-c)";
	postfix(infix);
	
	
	return 0;
}