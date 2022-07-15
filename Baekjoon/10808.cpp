#include<iostream>
#include<string>

using namespace std;

int main(){

    int alphabat[26] = {0};
    string word;

    cin >> word;

    for(int i = 0; i < word.length(); i++){
        alphabat[word[i] - 97]++;
    }

    for(int i = 0; i < 26; i++){
        cout << alphabat[i] << " ";
    }
}

