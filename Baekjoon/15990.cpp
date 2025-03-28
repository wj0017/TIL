/*
1, 2, 3 더하기 5

문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 3가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다. 단, 같은 수를 두 번 이상 연속해서 사용하면 안 된다.

1+2+1
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 100,000보다 작거나 같다.

출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.

1-100,000

1
2
3 12 21
4 121 31 13
5 1212 2121 32 23
6 


*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000009;
const int MAX_N = 100000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 전처리: 모든 가능한 n에 대해 미리 계산
    vector<vector<long long>> dp(MAX_N + 1, vector<long long>(4, 0));
    
    // 초기값 설정
    dp[1][1] = 1;  // 1
    dp[2][2] = 1;  // 2
    dp[3][3] = 1;  // 3
    dp[3][1] = 1;  // 2+1
    dp[3][2] = 1;  // 1+2
    
    for (int i = 4; i <= MAX_N; i++) {
        // 마지막 숫자가 1인 경우, 이전 숫자는 2나 3이어야 함
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        
        // 마지막 숫자가 2인 경우, 이전 숫자는 1이나 3이어야 함
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        
        // 마지막 숫자가 3인 경우, 이전 숫자는 1이나 2이어야 함
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
    }
    
    // 각 n에 대한 결과를 미리 계산
    vector<int> result(MAX_N + 1);
    for (int i = 1; i <= MAX_N; i++) {
        result[i] = (dp[i][1] + dp[i][2] + dp[i][3]) % MOD;
    }
    
    // 테스트 케이스 처리
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        cout << result[n] << '\n';
    } 
    
    return 0;
}