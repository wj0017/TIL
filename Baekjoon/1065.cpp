#include<iostream>

using namespace std;
//a

bool hansoo(int num){

    if(num < 100) 
        return true;

    else if(num == 1000)
        return false;

    else{
        int data[4];

        for(int i = 0; i < 3; i++){

            if(num == 0){
                break;
            }
            int decom = num % 10;
            data[i] = decom;
            num /= 10;
        }

        if(data[2] - data[1] == data[1] - data[0])
            return true;
        return false;
    }
    
}

int main(){

    int num;
    int cnt = 0;
    cin >> num;
    
    for(int i = 1; i <= num; i++){
        if(hansoo(i))
            cnt++;
        }
    
    cout << cnt;
}