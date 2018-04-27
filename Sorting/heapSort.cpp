#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
   // Find largest among root, left child and right child
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
     largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n){
   // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   // Heap sort
    for (int i=n-1; i>=0; i--){
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
   }
}

void printArray(int arr[], int n){
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cout <<"Enter size of array: ";
    cin >> n;
    cout << "Enter the array: ";
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    heapSort(arr, n);

    cout << "Sorted array is: ";
    printArray(arr, n);
}
