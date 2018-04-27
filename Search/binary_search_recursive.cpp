#include <iostream>
using namespace std;
int flag;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int binary_search(int A[],int l,int r,int query){
	if(l != r){
		int mid = l + (r-l)/2;
		if (A[mid] == query){
			flag = 1;
			return mid;
		}
		else if (A[mid] > query){
			return binary_search(A,l,mid - 1,query);
		}
		else if (A[mid] < query){
			return binary_search(A,mid+1,r,query);
		}
	}
}
int main(){
	int N,A[100],query;
	cout << "Size of array: ";
	cin >> N;
	cout << "Array: ";
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << "Query: ";
		cin >> query;
	int y = binary_search(A,0,N,query);
	if (flag == 0)
		cout << "Not found";
	else
		cout << y;
	return 0;
}
