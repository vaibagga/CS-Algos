#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int bubble_sort(int A[],int N){
	if (N==0)
		return 0;
	for (int j = 0; j < N; j++){
		if (A[j] > A[j + 1])
			swap(A[j], A[j+1]);
	}
	return bubble_sort(A,N-1);
	
	
}
int main() {
	int N;
	cout << "Size of array: ";
	cin >> N;
	int A[N];
	cout << "Array: ";
	for (int i = 0; i < N;i++){
		cin >> A[i];
	}
	bubble_sort(A,N);
	cout << "Sorted Array: ";
	for (int i = 0; i < N;i++){
		cout << A[i] << " ";
	}
	return 0;
}
