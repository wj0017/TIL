#include<iostream>

using namespace std;

int main(){

    int num;
    int check = 0;
    
    cin >> num;

    while(num > 0){
        check++;
        num -= check;
    }
    
    if (check % 2 == 1)
		cout << 1 - num << "/" << check + num;
	else
		cout << check + num << "/" << 1 - num;
}