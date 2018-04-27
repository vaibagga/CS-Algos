#include <iostream>
using namespace std;
int main(){
	cout << "Size of array:";
	int N;
	cin >> N;
	int A[100],i;
	cout << "Array:";
	for (i = 0 ; i < N; i++){
		cin >> A[i];
	}
	cout << "Index of element to be deleted:";
	int deletionIndex;
	cin >> deletionIndex;
	for (i = deletionIndex; i < N-1; i++){
		A[i] = A[i+1];
	}
	for (i = 0; i < N-1; i++){
		cout << A[i] << " ";
	}
	return 0;
}

