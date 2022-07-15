#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL); 
	int n, count = 0;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (i % 5 == 0) count++;
		if (i % 25 == 0) count++;
		if (i % 125 == 0) count++;
	}
	cout << count;
}
/* 시간초과
#include <cstdio>
#include<iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int factorial_cal(int input){
    if(input == 1 || input == 0) return 1;
    return input * factorial_cal(input - 1);
}

int main(){

    int num, num1;
    int cnt = 0;
    int  check = 0;
    cin >> num;
    
    num1 = factorial_cal(num);

    while(!check){

        check = num1 % 10;
        if(!check) cnt++;
        num1 = num1 / 10;
    }

    cout << cnt;
}
*/