#include<stdio.h>

void push();
void pop();
void display();
int top=-1;
int Array[6];
int main()
{
	int ch;
	while(1)
	{
		printf("stack menu\n");
		printf("\n1.push\n2.pop\n3display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
			default:printf("wrong choice\n");
					}
	}
	return 0;
}

void push()
{
	int value;
	if(top==5)
	{
		printf("stack overflow.\n");
	}
	else
	{
		printf("enter element to push=");
		scanf("%d",&value);
		top=top+1;
		Array[top]=value;
		printf("\n");
		
			}
}
	void pop()
	{
	if (top==-1)
	{
		printf("underflow\n");
		
	}
	else
	{
		printf("deleted element is %d",Array[top]);
		top=top-1;
	}
	printf("\n");
	}
	void display()
	{
		int i;
		if(top==-1)
		{
			printf("stack is empty\n");
		}
		else
		{
			for(i=0;i<=top;i++)
			printf("%d",Array[i]);
		}
			
				printf("\n");
			
		
	}

