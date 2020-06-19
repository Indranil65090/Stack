#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX],top=-1;
void push(int a[],int val);
int  pop(int a[]);
int  peek(int a[]);
void display(int a[]);
int main()
{
	int val,option;
	do
	{
		printf("\n*********MAIN MENU**************");
		printf("\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.POP");
		printf("\n4.DISPLAY");
		printf("**********************************");
		printf("\n\nEnter your option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the number to be pushed in to the stack:");
				scanf("%d",&val);
				push(a,val);
				break;
			case 2:
				val=pop(a);
				printf("\nThe value to be deleted from the stack is:%d",val);
				break;
			case 3:
				val=peek(a);	
				printf("\nThe value stored at the top of the stack is:%d",val);	
				break;
			case 4:
				display(a);
				break;	
		}
	}while(option!=5);
	return 0;
}
void push(int a[],int val)
{
	if(top==MAX-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		top++;
		a[top]=val;
	}
}
int pop(int a[])
{
	int val;
	if(top==-1)
	{
		printf("\nSTACK UNDERFLOW");
		return -1;
	}
	else
	{
		val=a[top];
		top--;
		return val;
	}
}
void display(int a[])
{
	int i;
	if(top==-1)
	{
		printf("\nSTACK IS EMPTY");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d",a[i]);
		}
	}
}
int peek(int a[])
{
	if(top==NULL)
	{
		printf("\nSTACK IS EMPTY");
		return -1;
	}
	else
	{
		return a[top];
	}
}
