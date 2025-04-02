/*
쉬운 계단 수

문제
45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.



줄 수가 주어지면
거기에 따른 계단의 갯수를 측정하고
1,000,000,000,000으로 나눈다

1 0개
2 7*2개 
3 8*2*2개 32개
4 8*

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    const int MOD = 1000000000;
    
    // dp[i][j] = 길이가 i이고 마지막 숫자가 j인 계단 수의 개수
    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));
    
    // 기본 케이스: 길이가 1인 계단 수
    // 한 자리 숫자 1-9는 각각 계단 수 (0으로 시작하는 수는 계단 수가 아님)
    for (int digit = 1; digit <= 9; digit++) {
        dp[1][digit] = 1;
    }
    
    // 길이가 2부터 N까지의 계단 수 계산
    for (int length = 2; length <= N; length++) {
        for (int last_digit = 0; last_digit <= 9; last_digit++) {
            // 마지막 숫자가 0인 경우, 이전 숫자는 반드시 1
            if (last_digit == 0) {
                dp[length][last_digit] = dp[length - 1][1];
            }
            // 마지막 숫자가 9인 경우, 이전 숫자는 반드시 8
            else if (last_digit == 9) {
                dp[length][last_digit] = dp[length - 1][8];
            }
            // 그 외의 경우, 이전 숫자는 현재 숫자보다 1 작거나 1 큰 수
            else {
                dp[length][last_digit] = (dp[length - 1][last_digit - 1] + dp[length - 1][last_digit + 1]) % MOD;
            }
        }
    }
    
    // 길이가 N인 모든 계단 수의 합 계산
    long long total = 0;
    for (int digit = 0; digit <= 9; digit++) {
        total = (total + dp[N][digit]) % MOD;
    }
    
    cout << total << endl;
    
    return 0;
}