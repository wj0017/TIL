#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string exp;
    stack<char> st;

	cin >> exp;

    for(int i = 0; i < exp.length(); i++){
        if (exp[i] >= 'A' && exp[i] <= 'Z'){ st.push(exp[i]); }
        else{
            if(exp[i] == '('){
                   
            }
        }
    }


	return 0;
}