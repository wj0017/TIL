#include<iostream>

using namespace std;

int main(){

    int num;
    int cnt = 0;

    cin >> num;

    while(!(num == 1)){
        if(num % 3 == 0){
            num /= 3;
            cnt++;
        }
        else if(num % 2 == 0){
            num /= 2;
            cnt++;
        }
        else{
            num -= 1;
            cnt++;
        }
    }

    printf("%d",cnt);
}