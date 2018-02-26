#include <iostream>

using namespace std;

void insertion_sort(int A[],int size_A){
    for (int i = 1; i < size_A; i++){
        int j = i, temp = A[i];
        while(j > 0 && A[j-1] > temp){
            A[j] = A[j-1];
            j--;
        }
        A[j] = temp;
    }
}
int main(){
    int array_size;
    cout << "Enter the size of array: ";
    cin >> array_size;
    int arr[array_size];
    cout << "Enter the terms of the array: ";
    for (int i = 0; i < array_size;i++){
        cin >> arr[i];
    }
    insertion_sort(arr,array_size);
    for (int i = 0; i < array_size;i++){
        cout << arr[i] << " ";
    }
    return 0;

}
