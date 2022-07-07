#include<iostream>

using namespace std;

void hanoi(int num, int from, int to, int bypass){

    if(num == 1){
        cout << from << to << endl;
    }
    else{
        hanoi(num - 1, from, bypass, to);
        cout << from << to << endl;
        hanoi(num - 1, bypass, to, from);
    }
}

int main(){

    int block;
    cin >> block;
    cout << (1<<block) -1 << endl;

    hanoi(block, 1, 3, 2);
}