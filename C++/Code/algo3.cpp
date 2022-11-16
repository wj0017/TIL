#include <iostream>
#include <climits>

using namespace std;


void optimalSearchTree(int n, const float p[], float& minAvg, int** R);

int main(void){
    int n = 4;
    
    //Example 3.9
    float book_p[5] = {0, 0.375, 0.375, 0.125, 0.125};
    // 자작 데이터
    float my_p[5] = {0, 0.5, 0.25, 0.25, 0.125};

    float minAvg;

    int** R = new int* [n+2];

    for(int i = 0; i < n+2; i++){
        R[i] = new int[n+1];
    }

    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n+1; j++){
            R[i][j] = 0;
        }
    }

    optimalSearchTree(n, my_p, minAvg, R);

    cout << "\n minAug : " << minAvg;

    cout << "\n\n R : ";
    for (int i = 0; i <= n; ++i){
        cout << "\t" << i;
    }
    cout << endl << "     ______________________________________" << endl;
    for (int i = 1; i <= n+1; ++i)
    {
        cout << "  " << i << " |";
        for (int j = 0; j <= n; ++j)
            cout << "\t" << R[i][j];
        cout << endl;
    }
    cout << endl;

    return 0;
}


void optimalSearchTree(int n, const float p[], float& minAvg, int** R){
    int i, j, k, diagonal;
    float A[n+2][n+1];

    float sum = 0;
    for(i = 0; i <= n+1; i++)
        for(j = 0; j <= n; j++)
            A[i][j] = 0;

    for(i = 1; i <= n; i++){
        A[i][i-1] = 0;
        A[i][i] = p[i];
        R[i][i] = i;
        R[i][i-1] = 0;
    }

    A[n+1][n] = 0;
    R[n+1][n] = 0;

    for(diagonal = 1; diagonal <= n-1; diagonal++){
        for(i = 1; i <= n-diagonal; i++){
            j = i + diagonal;
            float minval = INT_MAX;
            for(k = i; k <= j; k++){
                if(minval > A[i][k-1] + A[k+1][j]){
                    minval = A[i][k-1] + A[k+1][j];
                    R[i][j] = k;
                }
            }

            sum = p[i];
            for(k = i+1; k <= j; k++){
                sum += p[k];
            }

            A[i][j] = minval + sum;
        }
        minAvg = A[1][n];        
    }

    cout << "\n A : ";
    for (int i = 0; i <= n; ++i){
        cout << "\t" << i;
    }
    cout << endl << "     ______________________________________" << endl;
    for (int i = 1; i <= n+1; ++i)
    {
        cout << "  " << i << " |";
        for (int j = 0; j <= n; ++j)
            cout << "\t" << A[i][j];
        cout << endl;
    }
    cout << endl;
}