#include <bits/stdc++.h>

void Merge(int arr[], int mid, int size){
    int temp[size];
    int i = 0, j = mid, k = 0;
    while (i < mid && j < size && k < size){
        if (arr[i] > arr[j]){
            temp[k] = arr[j];
            j++;
            k++;
        }
        else{
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    while (i < mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j < size){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = 0 ; i < size; i++)
        arr[i] = temp[i];
}

void MergeSort(int arr[], int size){
    if (size <= 1)
        return;
    int mid = size/2;
    MergeSort(arr, mid);
    MergeSort(arr + mid, size - mid);
    Merge(arr, mid, size);
}

using namespace std;

int main()
{
    int arr[] = {2,5,1,55,332,22};
    MergeSort(arr, 6);
    for (int i = 0 ; i < 6; i++)
        cout << arr[i] << " ";
    return 0;

}
