#include<iostream>
using namespace std;

int findfactorial(int number)
{
if(number==0)
return 1;
else
return number*findfactorial(number-1);
	
}

int main()
{
	int number;
	cout<<"enter number to find factorial=";
	cin>>number;
	int fibo=findfactorial(number);
	cout<<"factorial is="<<fibo;
	return 0;
	
}


