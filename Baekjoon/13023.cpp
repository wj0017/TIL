//문제
//BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.

// 오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.

// A는 B와 친구다.
// B는 C와 친구다.
// C는 D와 친구다.
// D는 E와 친구다.
// 위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.

// 둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.

// 출력
// 문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.
#include<iostream>

using namespace std;

int main(){

    // N,M의 크기 입력
    int N, M;
    cin >> N >> M;

    // a, b 변수 선언 후 배열에 넣는 작업
    int arr[2, M];
    int a,b;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        arr[0, i] = a;
        arr[1, i] = b;
    }

    // A-B-C-D-E의 관계를 찾는 작업
    // 1,i(?)와 0,i(?)이 같은 경우가 4번 이어지면 존재 == 1; 존재 하지 않으면 == 0;
    
    for(int i = 0; i < M; i++){

        int start = arr[1,i];

        for(int j = 0; j < M; j++){
            
        }
    }

}

