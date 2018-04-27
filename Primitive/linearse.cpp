#include <iostream>
using namespace std;
//Linear Search
int main(){
	cout << "Size of array:";
	int N,flag = 0;
	cin >> N;
	int A[100],i;
	cout << "Array:";
	for (i = 0 ; i < N; i++){
		cin >> A[i];
	}
	int searchElement;
	cout << "Element to be searched:";
	cin >> searchElement;
	for (i = 0; i < N; i++){
		if(A[i] == searchElement){
			flag++;
			cout << i;
		}
	}
	if (!flag)
	 cout << "Element not present";
	return 0;
}

