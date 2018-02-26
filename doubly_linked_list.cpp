#include <iostream>

using namespace std;

// size of list is initially zero
int SIZE = 0;
/* a node consists of 3 parts
1. information or data
2. pointer to previous node
3. poinbter to next node
*/
struct node{
    int info;
    node *next;
    node *prev;
};

node *head = NULL;
node *tail = NULL;
// append function inserts a number in the linked list at the last position

void append(int insertion_element){
    node *temp = new node();
    temp -> info = insertion_element;
    temp -> next = NULL;
    tail = temp;
    SIZE++;
    if (head == NULL){ //empty list
        head = temp;
        return;
    }
    node *ptr = head;
    while(ptr -> next != NULL){ // traversing the list
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    temp -> prev = ptr;
}
/* prints the list
in order starting with head pointer and proceeding to next
pointer in order
*/
void print(){
    if (head == NULL){
        cout << "Empty linked list\n";
        return;
    }
    node *ptr = head;
    cout << "Linked list is: ";
    while(ptr != NULL){
        cout << ptr -> info << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}

/* prints the list in reversed order
starting with tail and proceeding to
previous pointer
*/

void reversePrint(){
    if (head == NULL){
        cout << "Empty list\n";
        return;
    }
    node *ptr = tail;
    cout << "Linked list in reverse is: ";
    while (ptr != NULL){
        cout << ptr -> info << " ";
        ptr = ptr -> prev;
    }
    cout << endl;
}

/* inserts 'element'
in the list to 'index'
*/

void insertIndex(int element, int index){
    if (index > SIZE){
        cout << "Index out of bound\n";
        return;
    }
    // creation of new node
    node *temp = new node();
    temp -> info = element;
    //insertion at tail
     if (index == SIZE){
        append(element);
        return;
    }
    //insertion at head
    if (index == 0){
        temp -> next = head;
        temp -> prev = NULL;
        head -> prev = temp;
        head = temp;
        SIZE++;
        return;
    }
    //insertion between head and tail
    if (index < SIZE){
        node *ptr = head;
        for (int i = 0; i < index-1; i++){
            ptr = ptr -> next;
            i++;
        }
        ptr -> next -> prev = temp;
        temp -> next = ptr -> next;
        temp -> prev = ptr;
        ptr -> next = temp;
        SIZE++;
        return;
    }
}

//deletes element at index
void deleteIndex(int index){
    if (index > SIZE - 1){
        cout << "Index out of bound\n";
        return;
    }
    if (head == NULL){//empty list
        cout << "Underflow";
        return;
    }
    if (head == tail){//single element only
        head = NULL;
        tail = NULL;
        return;
    }
    node *temp = head;
    //deletion at head
    if (index == 0){
        head = temp -> next;
        head -> prev = NULL;
        delete(temp);
        SIZE--;
        return;
    }
    //deletion at tail
    if (index == SIZE-1){
        temp = tail;
        temp -> prev -> next = NULL;
        tail = tail -> prev;
        SIZE--;
        return;
    }
    //deletion in between
    for (int i = 0; i < index - 1; i++){
        temp = temp -> next;
    }
    node *temp1 = temp -> next;
    temp -> next = temp1 -> next;
    temp1 -> next -> prev = temp;
    //memory freed
    delete(temp1);
    SIZE--;
}
int main(){
    while(1){
        char userInput;
        cout << "Enter:\n'p' for printing the linked list, \n'a' for inserting an element at the end, \n'i' for inserting element at index,\n'd' for deleting an element at index \n'r' for printing in reverse\nand any other character for exiting: ";
        cin >> userInput;
        // User inputs a character to signify the option he wants
            if (userInput=='p'){
            print();
            continue;
        }
         if (userInput=='r'){
            reversePrint();
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

