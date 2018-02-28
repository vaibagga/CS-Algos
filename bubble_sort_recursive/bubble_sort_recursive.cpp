#include <iostream>

using namespace std;

int bubbleSort(int A[],int length){
        if (length == 1){
            return 0;
        }
        int temp;
        for (int j = 0; j < length - 1; j++){
            if (A[j+1] < A[j]){
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
        return bubbleSort(A,length-1);
    }
int main(){
    int arraySize,temp;
    cout << "Enter the size of array: ";
    cin >> arraySize;
    int arr[arraySize];
    cout << "Enter the array: ";
    for (int i = 0; i < arraySize; i++){
        cin >> arr[i];
    }
    bubbleSort(arr,arraySize);
    cout << "Sorted array is: ";
    for (int i = 0; i < arraySize; i++){
        cout << arr[i] << " ";
    }
}
