#include <iostream>

using namespace std;
int top = -1;
class myStack{
    public:
        int arr[100];
        void push(int element){
            if (top >= 98){
                cout << "stack overflow\n";
                return;
            }
            arr[top] = element;
            top++;
        }
        int pop(){
            if (top == 0){
                cout << "stack underflow\n";
                return 0;
            }
            int deleted_element = arr[top];
            top--;
            return deleted_element;
        }
        void print(){
            cout << "Updated stack is: ";
            for (int i = 0; i < top; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
int main(){
    myStack A;
    while (1){
        cout << "Enter 1 for pushing, 2 for popping an element, 3 for printing the stack and 4 for quitting: ";
        int pushOrPop;
        cin >> pushOrPop;
        if (pushOrPop ==1){
            cout << "Enter the element to be pushed: ";
            int element;
            cin >> element;
            A.push(element);
        }
        if (pushOrPop == 2){
            A.pop();
        }
        if (pushOrPop == 3){
            A.print();
        }
        if (pushOrPop == 4){
            break;
        }
        else{
            cout <<"Not valid";
            continue;
        }
    }
    return 0;
}
