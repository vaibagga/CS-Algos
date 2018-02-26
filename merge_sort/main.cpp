#include <iostream>

using namespace std;

// A function to merge the two half into a sorted data
void Merge(int *a, int low, int high, int mid){
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[]
	while (i <= mid && j <= high){
		if (a[i] < a[j]){
			temp[k] = a[i];
			k++;
			i++;
		}
		else{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	// leftover terms
	while (i <= mid){
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high){
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++){
		a[i] = temp[i-low];
	}
}

void MergeSort(int *a, int low, int high){
	int mid;
	if (low < high){
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}

int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;

	int arr[n];
	cout << "Enter the array";
	for(i = 0; i < n; i++){
		cin>>arr[i];
	}

	MergeSort(arr, 0, n-1);
	cout<<"\nSorted Array is: ";
	for (i = 0; i < n; i++)
        cout<<arr[i] << " ";
	return 0;
}
