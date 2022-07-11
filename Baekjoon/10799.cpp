#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	stack<char> s;
	string str;
    int cnt = 0;
	
    cin >> str;
    
    for(int i = 0; i < str.length(); i++){

        if(str[i] == '('){ s.push(str[i]); }
        else{
            if(str[i - 1] == '('){s.pop(); cnt += s.size();}
            else{s.pop(); cnt++;}
        }
    }

    cout << cnt;
    return 0;
}