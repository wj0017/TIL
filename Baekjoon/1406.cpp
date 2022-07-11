#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){

    stack<char> st;
    stack<char> st2;
    string sentence = "";
    char mention, str;
    int num;

    cin >> sentence;
    for(int i = 0; i < sentence.length(); i++){
        st.push(sentence[i]);
    }
    cin >> num;

    while(num--){

        cin >> mention;

        if(mention == 'L'){
            if(st.empty()) continue;
            else{
                st2.push(st.top());
                st.pop();
            } 
        }
        else if(mention == 'D'){
            if(st2.empty()) continue;
            else{
                st.push(st2.top());
                st2.pop();
            } 
        }
        else if(mention == 'B'){
            if(st.empty()) continue;
            else st.pop();
        }
        else if(mention == 'P'){
            cin >> str;
            st.push(str);
        }
    }

    while(!st.empty()){st2.push(st.top()); st.pop();}
    while(!st2.empty()){cout << st2.top(); st2.pop();}

    return 0;
}

/*

구글 폼으로 물어볼 사항

0. 이름
1. 이번 소프트웨어 공모전 참석 여부
2. 공모점 아이디어(있다면)
3. 응애

*/