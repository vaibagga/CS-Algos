//Priority Queue Implementation.
#include<stdio.h>
#include<process.h>
int insert_by_priority(int );
int delete_by_priority(int );
int check(int );
void display_queue();

int front=-1;
int rear=-1;
int queue[20];
int main()
{
	int choice,item;
	printf("Priority Queue Menu\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.Wrong Choice\n");
	printf("Enter your choice\n");
	
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter element to be inserted: ");
			scanf("%d",&item);
			insert_by_priority(item);
			break;
			
			case 2: printf("Enter element to be deleted: ");
			scanf("%d",&item);
			delete_by_priority(item);
			break;
			
			case 3: display_queue();
			break;
			
			case 4: exit(0);
			break;
			default: printf("Wrong choice entered\n");
		}
	}
	return 0;
}

int insert_by_priority(int item)
{
	if(rear==19)
	{
		printf("Queue Overflow");
	}
	if(front==-1||rear==-1)
	{
		front++;
		rear++;
		queue[rear]=item;
		return;
	}
	else
	check(item);
	
}++

int check(int item)
{
	int i,j;
	for(i=0;i<=rear;i++)
	{
		if(item>=queue[i])
		{
			for(j=rear;j>i;j--)
			{
				queue[j]=queue[j-1];
			}
		}
	}
	queue[i]=item;
	return;
}

int delete_by_priority(int item)
{
	if(front==-1||rear==-1)
	{
		printf("Queue Underflow\n");
	}
	for(i=0;i<=rear;i++)
	{
		if(queue[i]=item)
		{
			for(;i<rear;i++)
			queue[i]=queue[i+1];
		}
		queue[i]=-99;
		rear--;
		
		if(front==-1)
		
	}
	
	
}


void display_queue()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
}






















