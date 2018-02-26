#include <bits/stdc++.h>


using namespace std;

int MaxSubarray(int A[], int N){
    if (N == 1)
        return A[0];
    int mid = N/2;
    int left_max = MaxSubarray(A, mid);
    int right_max = MaxSubarray(A + mid, N - mid);
    int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
    for (int i = 0; i < mid; i++)
        sum += A[i];
    left_sum = max(sum, left_sum);
    sum = 0;
    for (int i = mid; i < N; i++)
        sum += A[i];
    right_sum = max(sum, right_sum);
    int ans = max(left_max, right_max);
    return max(ans, left_sum + right_sum);
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cout << MaxSubarray(A, N) << "\n";
    return 0;
}
