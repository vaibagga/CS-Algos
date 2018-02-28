//Program to insert an element into an array
#include <iostream>

using namespace std;

int main(){
    int arraySize,element,index,arr[100];
    cout << "Enter the size of array: ";
    cin >> arraySize;
    cout << "Enter the array: ";
    for (int i = 0; i < arraySize; i++){
        cin >> arr[i];
    }
    cout << "Enter the element to be inserted and the index to which it is to be inserted: ";
    cin >> element >> index;
    for (int i = arraySize; i > index; i--){
            arr[i] = arr[i-1];  //all the elements in right of input index are pushed by one index to right
    }
    arr[index] = element;
    cout << "The updated array is: ";
    for (int i = 0; i < arraySize + 1; i++){
        cout << arr[i] << " ";
    }
}
