#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void push(int A[],int term,int top){
	A[top+1] = term;
}

int main() {
	int initialSize, arr[100],element;
	char pushOrPop;
	cout << "Enter the number of terms in the stack: ";
	cin >> initialSize;
	cout << "Enter the terms in the stack: ";
	for (int index = 0; index < initialSize; index++){
		cin >> arr[index];
	}
	int top = initialSize - 1;
	cout << "Enter 'p' for pushing an element into the array and 'o' for popping an element: ";
	cin >> pushOrPop;
	if (pushOrPop == 'p'){
		cout << "Enter the element to be pushed into the array: ";
		cin >> element;
		if (top + 1 < 99){	
			push(arr,element,top);
			top++;
		}
		else
			cout << "overflow";
	}
	if (pushOrPop == 'o'){
		if (top != 0)
			top--;
		else
			cout << "underflow";
	}
	cout << "Updated stack is: ";
	for (int index = 0; index <= top; index++){
		cout << arr[index] << " ";
	}
	
	
	return 0;
}
