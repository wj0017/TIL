#include<iostream>
#include <climits>

#define N 6

using namespace std;

int minmult(int n, const int d[], int P[][N+1]);
int order(int i, int j, int P[N+1][N+1]);

int main(){
    int d[N+1] = {7, 6, 5, 4, 3, 2, 1};
    int P[N+1][N+1] = {0};

    cout << "minmult의 값 : " << minmult(N, d, P);

    cout << "\n\n P : ";
    for (int i = 1; i <= N; ++i){
                cout << "       " << i;
    }
    cout << endl << "     ____________________________________________________" << endl;
    for (int i = 1; i <= N; ++i)
    {
        cout << "  " << i << " |";
        for (int j = 1; j <= N; ++j)
            cout << "       " << P[i][j];
        cout << endl;
    }
    cout << endl;
    
    cout << "최적의 순서 : ";
    order(1, N, P);

    return 0;
}

int minmult(int n, const int d[], int P[][N+1]) {
    int i, j, k, diagonal;
    int M[N+1][N+1];

    for(i = 1; i <= n; i++){
        M[i][i] = 0;
    }

    for(diagonal = 1; diagonal <= n-1; diagonal++){
        for(i = 1; i <= n-diagonal; i++) {
            j = i + diagonal;
            int minimum = INT_MAX;
            M[i][j] = M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
            for(k = i; k <= j-1; k++){
                if( M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j] < minimum){
                    M[i][j] = M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j];
                    minimum = M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j];
                    P[i][j] = k;
                }
            }
        }
    }
    return M[1][n];
}

int order(int i, int j, int P[N+1][N+1]){

    int k;

    if (i == j) {
        cout << "A" << i;
    }
    else {
        k = P[i][j];
        cout << "(";
        order(i, k, P);
        order(k+1, j, P);
        cout << ")";
    }
}
/*
#include<iostream>
#include <climits>

#define N 6

using namespace std;

int minmult(int n, const int d[], int P[][N+1]);
int order(int i, int j, int P[N+1][N+1]);

int main(){
    int d[N+1] = {7, 6, 5, 4, 3, 2, 1};
    int P[N+1][N+1] = {0};

    cout << "minmult의 값 : " << minmult(N, d, P);

    cout << "\n\n P : ";
    for (int i = 1; i <= N; ++i){
                cout << "       " << i;
    }
    cout << endl << "     ____________________________________________________" << endl;
    for (int i = 1; i <= N; ++i)
    {
        cout << "  " << i << " |";
        for (int j = 1; j <= N; ++j)
            cout << "       " << P[i][j];
        cout << endl;
    }
    cout << endl;
    
    cout << "최적의 순서 : ";
    order(1, N, P);

    return 0;
}

int minmult(int n, const int d[], int P[][N+1]) {
    int i, j, k, diagonal;
    int M[N+1][N+1];

    for(i = 1; i <= n; i++){
        M[i][i] = 0;
    }

    for(diagonal = 1; diagonal <= n-1; diagonal++){
        for(i = 1; i <= n-diagonal; i++) {
            j = i + diagonal;
            int minimum = INT_MAX;
            M[i][j] = M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
            for(k = i; k <= j-1; k++){
                if( M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j] < minimum){
                    M[i][j] = M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j];
                    minimum = M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j];
                    P[i][j] = k;
                }
            }
        }
    }
    return M[1][n];
}

int order(int i, int j, int P[N+1][N+1]){

    int k;

    if (i == j) {
        cout << "A" << i;
    }
    else {
        k = P[i][j];
        cout << "(";
        order(i, k, P);
        order(k+1, j, P);
        cout << ")";
    }
>>>>>>> 096d49bc5924c65723e19fe9c7fe8557fb65a3d9
}
*/