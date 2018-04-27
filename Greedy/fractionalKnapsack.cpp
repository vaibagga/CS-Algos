#include <bits/stdc++.h>

using namespace std;

int FractionalKnapsack(vector <int> value, vector <int> weight, int capacity){
    int N = weight.size();
    vector <float> density(N);
    for (int i = 0; i < N; i++){
        density[i] = value[i]/weight[i];
    }
    sort(density.begin(), density.end());
    int filled = 0, total_value = 0;
    for (int i = N; i > 0 && filled < capacity; i--){

    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
