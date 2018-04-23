//Recursive program for binary search
#include <iostream>

using namespace std;
int binarySearch(int A[],int length,int low,int high,int element){
    int mid = low + (high-low)/2;
    if (A[mid] == element){
        return mid;
    }
    if (A[mid] > element){
        return binarySearch(A,length,low,mid-1,element);
    }
    if (A[mid] < element){
        return binarySearch(A,length,mid+1,high,element);
    }
    if (high < low){
        return -1;
    }
}

int main(){
    int arraySize,element,flag = 0;
    cout << "Enter the size of array: ";
    cin >> arraySize;
    int arr[arraySize],high=arraySize,low=0,mid;
    cout << "Enter the array: ";
    for (int i = 0; i < arraySize; i++){
        cin >> arr[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> element;
    if (binarySearch(arr,arraySize,low,high,element) < 0){
        cout << "Element not found.";
    }
    else{
        cout << "Element found at " << binarySearch(arr,arraySize,low,high,element) << " index";
    }
}
