#include<iostream>

using namespace std;

int per;
int cnt[51] = {0};
int grade[51] = {0};
int x[51], y[51];

int main(){

    cin >> per;

    for(int i = 0; i < per; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < per; i++){
        for(int j = 0; j < per; j++){
            if(x[i] < x[j] && y[i] < y[j]){
                cnt[i]++;
            }
        }
    }

    for(int i = 0; i < per; i++){
        grade[i] = cnt[i] + 1;
        cout << grade[i] << " ";
    }
}