#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int a[MAX],top=-1;

void push(int a[],int x);
int pop(int a[]);
int val;

int main()
{
	int num,digit;
	printf("Enter the decimal number:");
	scanf("%d",&num);
	while(num>0)
	{
		digit=num%16;
		push(a,digit);
		num/=16;
	}
	printf("The hexadecimal equivalent is:");
	while(top!=-1)
	{
		val=pop(a);
		printf("%d",val);
	}
	return 0;
}

void push(int a[],int x)
{
	if(top==MAX-1)
	{
		printf("\nSTACK OVERFLOW\n");
	}
	else
	{
		top=top+1;
		a[top]=x;
	}
}
int pop(int a[])
{
	if(top==-1)
	{
		printf("\nSTACK UNDERFLOW\n");
		return -1;
	}
	else
	{
		val=a[top];
		top--;
		return val;
	}
}
