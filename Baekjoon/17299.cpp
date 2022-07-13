#include<iostream>
#include<algorithm>
#include<stack>
#define MAX 1000001

// counting number
using namespace std;

int main(void)
{
	stack<int> st;
    int arr[MAX];
    int result[MAX];
    int num, cnt;
    
    cin >> num;

    for(int i = 0; i < num; i++){cin >> arr[i];}

    for(int i = num - 1; i >= 0; i--){
        for(int j = 0; j < st.size(); j++){
            
        }
        while (!st.empty() && st.empty()){st.pop();}

        if(st.empty()) result[i] = -1;
        else result[i] = st.top();

        st.push(arr[i]);
    }

    for(int i = 0; i < num; i++)
        cout << result[i] << " ";
}