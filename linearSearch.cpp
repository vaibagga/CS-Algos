//Program for linear search
#include <iostream>

using namespace std;

int main(){
    int arraySize,element,index,arr[100],flag = 0;
    cout << "Enter the size of array: ";
    cin >> arraySize;
    cout << "Enter the array: ";
    for (int i = 0; i < arraySize; i++){
        cin >> arr[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> element;
    for (int i = 0; i < arraySize; i++){
            if (arr[i]==element){
                flag = 1;
                index = i;
                break;
            }
    }
    if (flag){
        cout << "Element found at " << index << " index.";
    }
    else{
        cout << "Element not found.";
    }
}
