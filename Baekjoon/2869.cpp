#include<iostream>

using namespace std;

int main(){

    int a; // 낮에 올라가는 거리
    int b; // 밤에 떨어지는 거리
    int c; // 막대 길이

    cin >> a >> b >> c;

    cout << (c - b - 1) / (a - b) + 1;
}