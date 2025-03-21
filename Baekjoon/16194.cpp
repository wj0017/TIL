/*
카드 구매하기

요즘 민규네 동네에서는 스타트링크에서 만든 PS카드를 모으는 것이 유행이다.

PS카드는 PS(Problem Solving)분야에서 유명한 사람들의 아이디와 얼굴이 적혀있는 카드이다. 각각의 카드에는 등급을 나타내는 색이 칠해져 있고, 다음과 같이 8가지가 있다.

전설카드
레드카드
오렌지카드
퍼플카드
블루카드
청록카드
그린카드
그레이카드
카드는 카드팩의 형태로만 구매할 수 있고, 카드팩의 종류는 카드 1개가 포함된 카드팩, 카드 2개가 포함된 카드팩, ... 카드 N개가 포함된 카드팩과 같이 총 N가지가 존재한다.



HOW CAN I SOLVE THIS QUESTION? 

*/ 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_price_cal(int N; const vector<int>& price;{
    vector<int> dp(N+1, 0);
    
    for(int i=1; i<=N; i++){
      for(int j=1; j<=i; j++){
        if(j <= price.size())
        dp[i] = min(dp[i], dp[i-j] + price[j-1])
      }
    }
     
    return dp[N]
}

int main() {
    int N;
    cin >> N;
    
    vector<int> price(N);
    
    for(int i=0; i<N; i++){
      cin >> price[i]
    }
    
    
    return 0;
}