//circular linked list
#include <iostream>

using namespace std;

int SIZE = 0;
/* Node Data Type consists of:
an integer storing info
a pointer to an node
*/
struct node{
    int info;
    node *link;
};
node *head = NULL;
/*
Append function adds element at end
To be used when user inputs elements in a sequence
*/
void append(int insertion_element){
    node *temp = new node();
    temp -> info = insertion_element;
    SIZE++;
    if (head == NULL){
        head = temp;
        temp -> link = head;
        return;
    }
    node *ptr = head;
    while(ptr -> link != head){
        ptr = ptr -> link;
    }
    ptr -> link = temp;
    temp -> link = head; //link of last node is head
}
void print(){
    if (head == NULL){//empty
        cout << "Empty linked list\n";
        return;
    }
    node *ptr = head;
    cout << "Linked list is: ";
    for (int i = 0; i < SIZE; i++){
        cout << ptr -> info << " ";
        ptr = ptr -> link;
    }
    cout << endl;
}
/*
insertIndex adds element (1st parameter) at index (2nd parameter)
*/
void insertIndex(int element, int index){
    if (index > SIZE){
        cout << "Index out of bound\n";//index exceeds size insertion not possible
        return;
    }
    node *temp = new node();
    temp -> info = element;
    if (index == SIZE){
        append(element);
        return;
    }
    if (index == 0){
        temp -> link = head;
        head = temp;
        SIZE++;
        return;
    }
    if (index < SIZE){
        node *ptr = head;
        for (int i = 0; i < index-1; i++){
            ptr = ptr -> link;
            i++;
        }
        temp -> link = ptr -> link;
        ptr -> link = temp;
        SIZE++;
        return;
    }

}
/*
deleteIndex deletes an element at index (parameter)
*/
void deleteIndex(int index){
    if (index > SIZE - 1){
        cout << "Index out of bound\n";
        return;
    }
    if (head == NULL){
        cout << "Underflow";
        return;
    }
    node *temp = head;
    if (index == 0){
        if (head -> link == NULL){
            head = NULL;
            SIZE--;
            return;
        }
        head = temp -> link;
        delete(temp);
        SIZE--;
        return;
    }
    for (int i = 0; i < index - 1; i++){
        temp = temp -> link;
    }
    node *temp1 = temp -> link;
    temp -> link = temp1 -> link;
    delete(temp1);
    SIZE--;
}
int main(){
    while(1){
        char userInput;
        cout << "Enter:\n'p' for printing the linked list, \n'a' for inserting an element at the end, \n'i' for inserting element at index,\n'd' for deleting an element at index \nand any other character for exiting\n";
        cin >> userInput;
        if (userInput=='p'){
            print();
            continue;
        }
        if (userInput=='a'){
            cout << "Enter element to be inserted: ";
            int element;
            cin >> element;
            append(element);
            continue;
        }
        if (userInput == 'i'){
            cout << "Enter the element to be inserted and the index at which it is to be inserted: ";
            int element, index;
            cin >> element >> index;
            insertIndex(element,index);
            continue;
        }
        if (userInput == 'd'){
            cout << "Enter index of element to be deleted: ";
            int index;
            cin >> index;
            deleteIndex(index);
        }
        else{
            break;
        }
    }
    return 0;
}
