#include<iostream>
using namespace std;

int findfibonacci(int number)
{
if(number==0)
return 0;
if(number==1)
return 1;
else
return findfibonacci(number-1)+findfibonacci(number-2);
	}

int main()
{
	int number;
	cout<<"enter position of fibonacci= ";
	cin>>number;
	int fibo=findfibonacci(number-1);
	cout<<number<<"the fibonacci number is="<<fibo;
	return 0;
	
	}
