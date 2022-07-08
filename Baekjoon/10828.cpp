#include<iostream>
#include<cstring>
#include<vector>

using namespace std;


int main(){

    int num, num1;
    string dicrection;
    vector<int> stack;

    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> dicrection;

        if(dicrection == "push"){
            cin >> num1;
            stack.push_back(num1);
        }
        else if(dicrection == "pop"){
            if( stack.size() == 0){ cout << "-1\n";}
            else {cout << stack.back() << endl; stack.pop_back();}
        }
        else if(dicrection == "size"){
            cout << stack.size() << endl;
        }
        else if(dicrection == "empty"){
            if(stack.size() > 0) {cout << "0\n";}
            else {cout << "1\n";}
        }
        else if(dicrection == "top"){
            if(stack.size() > 0) {cout << stack.back() << endl;}
            else {cout << "-1\n";}
        }
    }
}