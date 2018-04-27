#include<stdio.h>
#include<conio.h>
using namespace std;
int fibonacci(int number)
{
	if (number==0)
		return 0;
	if(number==1)
		return 1;
	else
		return(fibonacci(number-1)+fibonacci(number-2));
	
}
int main()
{
	int number,result;
	printf("Enter the number : ");
	scanf("%d",&number);
	result=fibonacci(number);
	printf("Result : %d",result);
	getch();
}

