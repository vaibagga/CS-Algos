#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int A[100],N;
	cout << "Size of Array: ";
	cin >> N;
	cout << "Array: ";
	for (int i = 0; i < N;i++){
		cin >> A[i];
	}
	int temp;
	for (int i = 0; i < N - 1; i++){
		for (int j = 0; j < N - i - 1; j++){
			if (A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;		
			}
		}
	}
	cout << "Sorted Array: ";
		for (int i = 0; i < N;i++){
			cout << A[i] << " ";
	}
	return 0;
}
