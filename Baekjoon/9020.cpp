#include<iostream>
#include<cmath>
// 소수는 에라토스테네스
using namespace std;

int main(){
    
    int num, max = 0;
    cin >> num;
    int* even = new int[num];
    for(int i = 0; i < num; i++) {
        cin >> even[i];
        if(even[i] > max){
            max = even[i];
        }
    }
    bool *prime = new bool[max+1];
    fill_n(prime, max + 1, 1);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= sqrt(max); i++){
        if(prime[i] == true){
            for(int j = i*2; j <= (max); j += i){
                prime[j] = false;
            }
        }
    }

    for(int i = 0; i < num; i++){
        for(int j = even[i]/2; j > 0; j--)
        {
            if(prime[j] && prime[even[i]-j])
            {
                cout << j << ' ' << even[i]-j << '\n';
                break;
            }
        }
    }
}