#include <iostream>
#define MAXSIZE 10

using namespace std;

int A[MAXSIZE][MAXSIZE];
int B[MAXSIZE][MAXSIZE];
int prod[MAXSIZE][MAXSIZE];

bool IsPossible(int m1, int n1,int m2, int n2){
    if (n1 != m2)
        return false;
    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n2; j++){
            prod[i][j] = 0;
            for (int k = 0; k < n1; k++)
                prod[i][j] += A[i][k] * B[k][j];
        }
    }
    return true;
}

int main(){
    int m1, n1, m2, n2;
    cin >> m1 >> n1  >> m2 >> n2;
    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n1; j++)
            cin >> A[i][j];
    }
    for (int i = 0; i < m2; i++){
        for (int j = 0; j < n2; j++)
            cin >> B[i][j];
    }
    if (IsPossible(m1,n1,m2,n2)){
        for (int i = 0; i < m1; i++){
            for (int j = 0; j < n2; j++)
                cout << prod[i][j] << " ";
            cout << "\n";
        }
    }
    else
        cout << "Dimensions do not match" << "\n";

    return 0;
}
