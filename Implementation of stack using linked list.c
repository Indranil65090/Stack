#include<stdio.h>
#include<stdlib.h>

struct stack 
{
	int data;
	struct stack *next;
};

struct stack *top=NULL;
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
int peek(struct stack *);
void display(); 

int main()
{
	int val,option;
	do
	{
		printf("\n**********MAIN MENU***********");
		printf("\n 1.PUSH");
		printf("\n 2.POP");
		printf("\n 3.PEEK");
		printf("\n 4.DISPLAY");
		printf("\n*******************************");
		printf("\n\nEnter the option from user(except for option 5):");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the number to be pushed in to the stack:");
				scanf("%d",&val);
				top=push(top,val);
				break;
			case 2:
				top=pop(top);
				break;
			case 3:
				val=peek(top);
				if(val==-1)
				{
					printf("\n\n*********************ERROR THE STACK IS EMPTY*****************************\n");
				}
				else
				{
					printf("\nThe value stored at the top of the stack:%d",val);
				}
				break;
			case 4:
				display();
				break;		
		}
	}while(option!=5);
	if(option>=5)
	{
		printf("NOTHING TO SHOW");
	}
	return 0;
}

struct stack *push(struct stack *top,int val)
{
	struct stack *ptr;
	ptr=(struct stack*)malloc(sizeof(struct stack));
	ptr->data=val;
	if(top==NULL)
	{
		top=ptr;
		top->next=NULL;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	return top;
}

struct stack *pop(struct stack *top)
{
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		top=top->next;
		printf("\nThe value to be deleted is:%d\n",ptr->data);
		free(ptr);
	}
	return top;
}

int peek(struct stack *top)
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		return top->data;	
	}
	
}

void display()
{
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("\nSTACK IS EMPTY");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("Display the stack:");
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
	}
}
