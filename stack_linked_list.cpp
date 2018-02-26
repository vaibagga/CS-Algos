#include <iostream>

using namespace std;

/* Node Data Type consists of:
an integer storing info
a pointer to an node
*/
struct node{
    int info;
    node *link;
};
node *head = NULL;

/* prints the stack
with top printed first and rest elements
next in order
*/

void print(){
    if (head == NULL){//empty
        cout << "Empty stack\n";
        return;
    }
    node *ptr = head;
    cout << "Stack is: ";
    while(ptr != NULL){
        cout << ptr -> info << " ";
        ptr = ptr -> link;
    }
    cout << endl;
}

//pushes an element onto the top of the stack
void push(int element){
    node *temp = new node();
    temp -> info = element;
    temp -> link = head;
    head = temp;
    return;
}

//pops an element from the stack

int pop(){
    if (head == NULL){//empty stack
        cout << "Underflow\n";
        return -1000000000;
    }
    node *temp = head;
    head = head -> link;
    int data = temp -> info;
    delete(temp);
    return data;
}

// returns the top of the stack

int top(){
    return head -> info;
}

int main(){
    while(1){
        char userInput;
        cout << "Enter:\n'p' for printing the linked list, \n's' for pushing an element onto the stack, \n'o' for popping an element from the stack\n't' for printing the top of the stack:  ";
        cin >> userInput;
        if (userInput=='p'){
            print();
            continue;
        }
        if (userInput=='s'){
            cout << "Enter element to be pushed: ";
            int element;
            cin >> element;
            push(element);
            continue;
        }
        if (userInput == 'o'){
            cout << pop() << " deleted from the stack\n";
            continue;
        }
        if (userInput == 't'){
            cout << top();
        }
        else{
            break;
        }
    }
    return 0;
}


