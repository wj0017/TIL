#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int arr[11];
    vector<int> result;
    int sum = 0;
    int a, b;

    for(int i = 0; i < 9; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if((sum - arr[i] - arr[j]) == 100){
                a = i;
                b = j;
                break;
            }
        }
    }

    for(int i = 0; i < 9; i++){
        if(i == a || i == b)
            continue;
        else
            result.push_back(arr[i]);
    }

    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "\n";
    }
}