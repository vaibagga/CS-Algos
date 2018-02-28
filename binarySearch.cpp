#include <iostream>
using namespace std;
//Binary Search
int main(){
	cout << "Size of array:";
	int N,flag = 0;
	cin >> N;
	int A[100],i,high = N-1,low = 0, mid;
	cout << "Array:";
	for (i = 0 ; i < N; i++){
		cin >> A[i];
	}
	int searchElement;
	cout << "Element to be searched:"; 
	cin >> searchElement;
	mid = (high+low)/2;
	while (high >= low){
		if(A[mid] == searchElement){
			flag++;
			cout << mid;
			break;
		}
		if (A[mid] < searchElement){
			low = mid + 1;
		}
		if (A[mid] > searchElement){
			high = mid - 1;
		}
		mid = (low + high)/2;
	}
	if (!flag)
	 cout << "Element not present";
	return 0;
}


