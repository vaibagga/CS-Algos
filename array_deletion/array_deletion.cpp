//Program to delete an element from an array
#include <iostream>

using namespace std;

int main(){
    int arraySize,index,arr[100];
    cout << "Enter the size of array: ";
    cin >> arraySize;
    cout << "Enter the array: ";
    for (int i = 0; i < arraySize; i++){
        cin >> arr[i];
    }
    cout << "Enter the index of the element to be deleted: ";
    cin >> index;
    for (int i = index; i < arraySize-1; i++){
            arr[i] = arr[i+1];  //all the elements in right of input index are shifted left by one index
    }
    cout << "The updated array is: ";
    for (int i = 0; i < arraySize - 1; i++){
        cout << arr[i] << " ";
    }
}
