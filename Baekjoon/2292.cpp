#include<iostream>

using namespace std;

int main(){

    int number;
    int i = 0;

    cin >> number;

    for(int sum=2; sum <= number; i++)
        sum += 6*i;

    if(number == 1) 
        i=1;
    cout << i;
    return 0;
}