/*
제곱수의 합

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)

출력
주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다.

예제 입력 1 
7
예제 출력 1 
4

예제 입력 2 
1
예제 출력 2 
1

예제 입력 3 
4
예제 출력 3 
1

예제 입력 4 
11
예제 출력 4 
3

예제 입력 5 
13
예제 출력 5 
2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
  int N;
  cin >> N;
    
  // dp[i] = i를 제곱수의 합으로 나타낼 때 필요한 최소 개수
  vector<int> dp(N + 1, INT_MAX);
    
  // 초기값: 0을 만들기 위해서는 0개의 제곱수가 필요
  dp[0] = 0;
  
  // 1부터 N까지 각 숫자에 대해 계산
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j * j <= i; j++){
      int square = j * j;
      dp[i] = min(dp[i], dp[i - square] + 1);
    }
  }
  
  cout << dp[N] << endl;
  
  return 0;
}