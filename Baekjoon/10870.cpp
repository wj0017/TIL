#include <iostream>

using namespace std;

int fibo(int num){

    if(num == 0) return 0;
    if(num == 1) return 1;

    return fibo(num-2) + fibo(num-1);
}

int main(void){
    int num, result;
    cin >> num;

    result = fibo(num);
    cout << result;
}