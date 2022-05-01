#include<iostream>
#include<cstdio>
#define N 10001

using namespace std;

bool idx[N];

int sol(int num){

    int sum = num;

    while(true){
 
        if(num == 0){
            break;
        } 
        sum += num % 10;
        num = num / 10;
    }

    return sum;
}

int main(){

    for(int i = 1; i < N; i++){

        int a = sol(i);

        if(a <= N){
            idx[a] = true;
        }
    }

    for(int i = 1; i < N; i++){
        
        if(!idx[i]){
            cout << i << "\n";
        }
    }

    return 0;
}
