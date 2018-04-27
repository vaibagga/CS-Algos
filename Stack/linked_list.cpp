#include <iostream>
using namespace std;
//stack using linked list
struct node{
	int info;
	node *ptr;
};
node *head = NULL;
void appendL();
void deleteL();
void printL();

int main() {
	
	int userInput;
	while(1){
		cout << "Press/n1. for printing (top first)/n2. for append/n3.for popping/nany other number for exit";
		cin >> userInput;
		if (userInput == 1){
			printL();
		}
		else if (userInput == 2){
			cout << "Enter element to be inserted";
			int userData;
			cin >> userData;
			appendL(userData);
		}
		else if(userInput == 3{
		popL();
		}
		else{
			break;
		}
			
	}
	return 0;
}
void appendL(int data){
	node *node = new newNode;
	newNode -> ptr = head;
	newNode -> info = data;
	head = &newNode
}
void popL(){
	if (head == NULL){
		cout << "underflow";
		return;
	}
	head = head -> ptr;
	
}

/*	
	if (head == NULL){
		node newNode;
		head = newNode;
		newNode -> info = data;
		newNode -> ptr = NULL;
	}
	
}
*/

void printL(){
	node *point = head;
	while (point != NULL){
		cout << point -> info
		point = point -> ptr;
	}
}
