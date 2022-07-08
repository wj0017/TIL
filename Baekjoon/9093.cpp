#include<iostream>
#include<stack>

using namespace std;
stack<char> list;
string sentence;

int main(){

    int num;
    cin >> num;

    cin.ignore();
    
    while(num--){
        getline(cin, sentence);
        sentence += ' ';

        for(int j = 0; j < sentence.length(); j++){
            if(sentence[j] != ' '){ list.push(sentence[j]); }
            else {
                while(!list.empty()){
                    cout << list.top();
                    list.pop();
                }cout << ' ';
            }
        }cout << endl;
    }
}