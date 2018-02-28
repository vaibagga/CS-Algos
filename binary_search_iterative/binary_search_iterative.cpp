//Iterative program for binary search
#include <iostream>

using namespace std;

int main(){
    int arraySize,element,index,flag = 0;
    cout << "Enter the size of array: ";
    cin >> arraySize;
    int arr[arraySize],high=arraySize,low=0,mid;
    cout << "Enter the array: ";
    for (int i = 0; i < arraySize; i++){
        cin >> arr[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> element;
    while (high >= low){
        mid = low + (high-low)/2;
        if (arr[mid] == element){
            index = mid;
            flag = 1;
            break;
        }
        if (arr[mid] > element){
            high = mid - 1;
        }
        if (arr[mid] < element){
            low = mid + 1;
        }
    }
    if (flag){
        cout << "Element found at " << index << " index.";
    }
    else{
        cout << "Element not found.";
    }
}
