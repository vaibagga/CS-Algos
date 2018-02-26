#include <iostream>

using namespace std;

/* Node Data Type consists of:
an integer storing info
a pointer to an node
priority of the node lesser first
*/

struct node{
    int info;
    node *link;
    int priority;
};
node *head = NULL;

/*
Append function adds element at end
To be used when user inputs elements in a sequence
*/

void print(){
    if (head == NULL){//empty
        cout << "Empty queue\n";
        return;
    }
    node *ptr = head;
    cout << "Priority queue is: ";
    while(ptr != NULL){
        cout << ptr -> info << " " <<"priority:" << ptr -> priority << " ";
        ptr = ptr -> link;
    }
    cout << endl;
}
void enqueue(int element, int priority){
    node *temp = new node();
    temp -> info = element;
    temp -> priority = priority;
    if (head == NULL){
        head = temp;
        temp -> link = NULL;
        return;
    }
    if(head -> priority > priority){
		temp -> link= head;
		head = temp;
		return;
    }
    node *ptr = head;
    while (ptr -> link != NULL && ptr -> link -> priority <= priority){
        ptr = ptr -> link;
    }
        temp -> link = ptr -> link;
        ptr -> link = temp;
}
void front_queue(){
    if (head == NULL){
        cout << "Empty queue\n";
        return;
    }
    cout << head -> info << endl;
}
//deleteIndex deletes an element at index (parameter)

void rear_queue(){
    if (head == NULL){
        cout << "Empty queue\n";
        return;
    }
    node *ptr = head;
    while (ptr -> link != NULL){
        ptr = ptr -> link;
    }
    cout << ptr -> info << endl;
}
void dequeue(){
    if (head == NULL){
        cout << "Underflow";
        return;
    }
    node *temp = head;
    head = temp -> link;
    delete(temp);
    return;
}
int main(){
    while(1){
        char userInput;
        cout << "Enter:\n'p' for printing the linked list, \n'e' for enqueue operation,\n'd' for dequeue operation \nand any other character for exiting\n";
        cin >> userInput;
        if (userInput=='p'){
            print();
            continue;
        }
        if (userInput == 'e'){
            cout << "Enter the element to be enqueued followed by its priority: ";
            int element, priority;
            cin >> element >> priority;
            enqueue(element,priority);
            continue;
        }
        if (userInput == 'd'){
            dequeue();
        }
        else{
            break;
        }
    }
    return 0;
}

