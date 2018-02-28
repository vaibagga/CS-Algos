//Queue implementation.
#include<stdio.h>
#include<process.h>
void insert();
void delete();
void display();
int queue[10];
int front=-1;
int rear=-1; 
int main()
{
	int choice;
	while(1)
	{
		printf("Queue Menu\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
			break;
			case 2:delete();
			break;
			case 3:display();
			break;
			case 4:exit(1);
			break;
			default: printf("Wrong choice entered.\n");
		}
	}
	return 0;
}

void insert()
{
	int add_item;
	if(rear==9)
	{
		printf("Queue overflow\n");
	}
	else
	{
		if(front==-1)
		front=0;
		printf("Enter element to be inserted: ");
		scanf("%d",&add_item);
		rear=rear+1;
		queue[rear]=add_item;
	}
}

void delete()
{
	if(front==-1||front>rear)
	{
		printf("Queue underflow\n");
	}
	else
	{
		printf("Element deleted from the queue is %d",queue[front]);
		front=front+1;
	}
	printf("\n");
}

void display()
{
	int i;
	if(front==-1)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		printf("%d ",queue[i]);
	}
	printf("\n");
}
