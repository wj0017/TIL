#include <iostream>
using namespace std;

int apt[101][15];

int main(){
  // Test Case 입력
  int t; 
  cin >> t;
  
  while(t--){
	// k <= 1, n <= 14  
    int k, n; 
    cin >> k >> n;
      
    for (int i=0; i <= k; i++){
        for (int j=1; j <= n; j++){
            if (i == 0) {
                apt[0][j] = j;
            }
            else if (j == 1){
                apt[i][1] = 1;
            }
            else {
                apt[i][j] = apt[i][j-1] + apt[i-1][j];
            } 
        }
    }
    cout << apt[k][n] << "\n";
  }
}