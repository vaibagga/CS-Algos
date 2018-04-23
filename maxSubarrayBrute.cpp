#include <iostream>

using namespace std;

int maxSubarray(int A[], int N){
    int max_sum = INT_MIN;
    for (int i = 1; i <= N; i++){
        for (int  start = 0; start < N - i; start++){
                int sum = 0;
                for (int k = start; k < i + start; k++)
                    sum += A[k];
                if (sum > max_sum)
                    max_sum = sum;
        }
    }
    return max_sum;
}

int main(){
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << maxSubarray(arr, N) << "\n";

}
