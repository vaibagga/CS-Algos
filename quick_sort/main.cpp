#include <iostream>
using namespace std;
void QuickSort(int A[],int start,int ending);
int Partition(int A[],int start,int ending);
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >>n;
    int A[n];
    cout << "\nEnter the elements: ";
    for(int i=0;i<n;i++){
        cin >>A[i];
    }
    QuickSort(A,0,n-1);
    cout <<"The sorted list is : ";
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    return 0;
}

void QuickSort(int A[],int start,int ending){
    int pIndex;
    if(start<ending){
        pIndex=Partition(A,start,ending);
        QuickSort(A,start,pIndex-1);
        QuickSort(A,pIndex+1,ending);
    }
}

int Partition(int A[],int start,int ending){
    int pivot,pIndex,temp,temp2;
    pivot=A[ending];
    pIndex=start;
    for(int i=start;i<ending;i++){
        if(A[i]<=pivot){
            temp=A[i];
            A[i]=A[pIndex];
            A[pIndex]=temp;
            pIndex=pIndex+1;
        }
    }
    temp2=A[pIndex];
    A[pIndex]=A[ending];
    A[ending]=temp2;
    return pIndex;
}
