#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>
using namespace std;

int M, N;
int sum = 0;

int main()
{
    cin >> M >> N;
    int min = -1;

    for(int i = M; i <= N; i++){

        int getNum = i;
        int cn = 0;

        for(int j = 2; j < getNum; j++){
            if(getNum % j == 0) cn++;
        }
        if(cn == 0 && getNum != 1) {
            if(min == -1){
                min = i;
            }
            sum += i;
        }
    }

    if(min != -1) cout << sum << "\n" << min;
    else        cout << "-1";
}