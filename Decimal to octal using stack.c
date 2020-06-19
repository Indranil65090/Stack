#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int a[MAX],top=-1;

void push(int a[],int val);
int pop(int a[]);

int main()
{
	int num,digit;
	printf("Enter the decimal number:");
	scanf("%d",&num);
	while(num>0)
	{
		digit=num%8;
		push(a,digit);
		num/=8;
	}
	printf("The octal equivalent is:");
	while(top!=-1)
	{
		printf("%d",pop(a));
	}
	return 0;
}

void push(int a[],int val)
{
	if(top==MAX-1)
	{
		printf("\nSTACK OVERFLOW\n");
	}
	else
	{
		top=top+1;
		a[top]=val;
	}
}
int pop(int a[])
{
	int val;
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
