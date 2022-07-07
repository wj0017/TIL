#include<iostream>
#include<cmath>

using namespace std;

int hanoi(int num){

    if(num == 1){
        cout << "1 3";
    }
    else{
        hanoi(num - 1);
    }
}

int main(){

    // 하노이탑
    // 1 = 1
    // 2 = 3
    // 3 = 7
    // 4 = 15

    int block;
    cin >> block;

    int result = hanoi(block);
    cout << result;    
}