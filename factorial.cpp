#include<stdio.h>
#include<conio.h>
int factorial(int number)
{
	int i;
	int fact=1;
	for(i=number;i>0;i--)
	{
			fact*=number;
			number--;
	}
	return fact;
}
int main()
{
	int number,result;
	printf("enter the number : ");
	scanf("%d",&number);
	result=factorial(number);
	printf("Result : %d",result);
	getch();	
}
