#include <iostream>

using namespace std;

int n = 5;
int INF = 100;


int p[5][5];
int arr[5][5] = {
	{0, 5, INF, INF, 4},
	{9, 0, INF, 2, 2},
	{3, INF, 0, 1, INF},
	{2, 5, INF, 0, INF},
	{INF, INF, 1, 7, 0},
};

void path(int *p[5], int q, int r);

void floyd2() {
	int d[5][5];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = arr[i][j];
			p[i][j] = 0;
		}
	}

	for (int a = 0; a < n; a++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][a] + d[a][j] < d[i][j]) {
				    p[i][j] = a;
					d[i][j] = d[i][a] + d[a][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", d[i][j]);
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", p[i][j]);
		}
		cout << endl;
	}
    cout << endl;

}

void path(int *p[5], int q, int r){
    if(p[q][r] != 0){
        path(p, q,p[q][r]);
        cout << " v " << p[q][r];
        path(p, p[q][r], r);
    }
    
}

int main() {

	floyd2();
}

/*
  0   5   5   6   4 
  4   0   3   2   2 
  3   6   0   1   7 
  2   5   7   0   6 
  4   7   1   2   0 

  0   0   4   4   0 
  3   0   4   0   0 
  0   3   0   0   0 
  0   0   4   0   0 
  2   3   0   2   0 

*/