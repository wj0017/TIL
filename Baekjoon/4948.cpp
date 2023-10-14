#include <iostream>
#include <algorithm>
using namespace std;

// 베르트랑 공준
// 자연수 n에 대하여 n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다
// 1 <= n <= 123,456

int main(){

    int n;
    while(n > 0){
        cin >> n;
        int cnt = 0;
        for(int j = n; j < 2 * n; j++){
            for(int i = 1; i < n; i++){
                if(j % i == 1)
                    cnt++;
            }
        }
        cout << cnt;
        cnt = 0;
    }

    return 0;
}