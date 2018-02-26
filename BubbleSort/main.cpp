#include <bits/stdc++.h>

using namespace std;

void BubbleSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    BubbleSort(arr, 10);
    for (int i =0 ; i < 10; i++)
        cout << arr[i] << " ";
    //cout << "Hello world!" << endl;
    return 0;
}
