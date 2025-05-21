/*
가장 긴 증가하는 부분 수열 4 스페셜 저지

문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> dp(n, 1);         // LIS 길이 저장
    vector<int> prev(n, -1);      // 이전 인덱스 저장 (경로 추적용)

    // LIS 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // LIS 최대 길이와 마지막 원소 인덱스 찾기
    int lis_len = 0, last_idx = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > lis_len) {
            lis_len = dp[i];
            last_idx = i;
        }
    }

    // LIS 수열 역추적
    vector<int> lis_seq;
    while (last_idx != -1) {
        lis_seq.push_back(A[last_idx]);
        last_idx = prev[last_idx];
    }
    reverse(lis_seq.begin(), lis_seq.end());

    // 출력
    cout << lis_len << '\n';
    for (int x : lis_seq) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}