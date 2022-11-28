#include <iostream>
#include <vector>
#include <climits>

#define N 5
#define INF 999 

using namespace std;

void dijkstra (int n, int** W, vector<pair<int, int>> F);

int main(void){

    int book[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 7, 4, 6, 1},
        {0, INF, 0, INF, INF, INF},
        {0, INF, 2, 0, 5, INF},
        {0, INF, 3, INF, 0, INF},
        {0, INF, INF, INF, 1, 0}
    };
    int my[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 5, 1, 4, 2},
        {0, INF, 0, 2, INF, 5},
        {0, INF, INF, 0, INF, INF},
        {0, INF, 2, INF, 0, 1},
        {0, INF, INF, INF, INF, 0}
    };
    int** W = new int* [N+1];
    vector<pair<int, int>> F;

    for(int i = 0; i < N+1; i++){
        W[i] = new int[N+1];
    }

    for(int i = 0; i < N+1; i++){
        for(int j = 0 ; j < N+1; j++){
            W[i][j] = book[i][j];
        }
    }

    dijkstra(N, W, F);

    return 0;
}


void dijkstra (int n, int** W, vector<pair<int, int>> F){
    int i, vnear;
    pair<int, int> e;
    int touch[N + 1];
    int length[N + 1];

    for(i = 2; i <= n; i++){
        touch[i] = 1;
        length[i] = W[1][i];
    }

    for(int k = 0; k < n-1; k ++){
        int min = INT_MAX;
        for(i = 2; i <= n; i++){
            if(length[i] >= 0 && length[i] <= min){
                min = length[i];
                vnear = i;
            }
        }
        
        e = make_pair(touch[vnear], vnear);
        F.push_back(e);

        for(i = 2; i <= n; i++){
            if(length[vnear] + W[vnear][i] < length[i]){
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        }
        length[vnear] = -1;
    }

    for(int i = 0; i < F.size(); i++){
        cout << F[i].first << " " << F[i].second << "\n";
    }
}


