//iterative bubble sort
#include <iostream>

using namespace std;

int main(){
    int arraySize,temp;
    cout << "Enter the size of array: ";
    cin >> arraySize;
    int arr[arraySize];
    cout << "Enter the array: ";
    for (int i = 0; i < arraySize; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < arraySize - 1; i++){
        for (int j = 0; j < arraySize - i; j++){
            if (arr[j+1] < arr[j]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Sorted array is: ";
    for (int i = 0; i < arraySize; i++){
        cout << arr[i] << " ";
    }
}
