#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, getNum;
int cn = 0;
int cnt = 0;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++){

        cin >> getNum;
        // 소수를 구하기 위해서 나누어 지는 수가 1, 자기 자신
        // 나머지 수에서는 나머지가 무조건 존재 == 약수가 1, 자기 자신 뿐이라는 소리고
        // 약수를 구하는 방법?
        // for문 사용하여 구하기 그러다가 1, 자기자신이 아니면 break 만약 그렇다면 cnt++
        // 여기서 문제! 이게 2초만에 계산이 다 될것이냐 -> 일단 해

        for(int j = 2; j < getNum; j++){
            if(getNum % j == 0){
                cn++;
            }
        }
        if(cn == 0 && getNum != 1) cnt++;
        cn = 0;
    }

    cout << cnt;
}//