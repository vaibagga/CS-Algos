#include <iostream>
using namespace std;
int main(){
	cout << "Size of Array:";
	int N;
	cin >> N;
	int A[100],i;
	cout << "Array:";
	for (i = 0 ; i < N; i++){
		cin >> A[i];
	}
	cout << "Element to be inserted and its index:";
	int insertionElement,index;
	cin >> insertionElement >> index;
	for (i = N-1; i >= index; i--){
		A[i+1] = A[i];
	}
	A[index] = insertionElement;
	for (i = 0; i < N+1; i++){
		cout << A[i] << " ";
	}
	return 0;
}

