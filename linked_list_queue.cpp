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
node *rear = NULL;

//enqueue function adds element at end

void enqueue(int insertion_element){
    node *temp = new node();
    temp -> info = insertion_element;
    temp -> link = NULL;
    rear = temp;
    if (head == NULL){
        head = temp;
        return;
    }
    node *ptr = head;
    while(ptr -> link != NULL){
        ptr = ptr -> link;
    }
    ptr -> link = temp;
}

//prints the front of the queue

void front_queue(){
    if (head== NULL){
        cout << "Empty queue\n";
        return;
    }
    cout << head -> info << endl;
}

//prints the rear of the queue

void rear_queue(){
    if (rear== NULL){
        cout << "Empty queue\n";
        return;
    }
    cout << rear -> info << endl;
}

void print(){
    if (head == NULL){//empty
        cout << "Empty queue\n";
        return;
    }
    node *ptr = head;
    cout << "Linked list is: ";
    while(ptr != NULL){
        cout << ptr -> info << " ";
        ptr = ptr -> link;
    }
    cout << endl;
}


//dequeue removes an element and returns the info contained

int dequeue(){
    if (head == NULL){
        cout << "Underflow\n";
        return -1000000;
    }
    node *temp = head;
    head = temp -> link;
    int data = temp -> info;
    delete(temp);
    return data;
}
int main(){
    while(1){
        char userInput;
        cout << "Enter:\n'p' for printing the linked list\n'e' for enqueue operation\n'd' for dequeue operation\n'f' for front to diplay front of the queue\n'r' to display rear of the queue: ";
        cin >> userInput;
        if (userInput=='p'){
            print();
            continue;
        }
        if (userInput=='e'){
            cout << "Enter element to be inserted: ";
            int element;
            cin >> element;
            enqueue(element);
            continue;
        }
        if (userInput == 'd'){
            dequeue();
            continue;
        }
        if (userInput == 'f'){
            front_queue();
            continue;
        }
        if (userInput == 'r'){
            rear_queue();
            continue;
        }
        else{
            break;
        }
    }
    return 0;
}

