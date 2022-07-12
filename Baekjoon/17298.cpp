#include <iostream>
#include<algorithm>
#include <stack>
#define MAX 1000001

using namespace std;

int main(void)
{
	stack<int> st;
    int arr[MAX];
    int result[MAX];
    int num;
    
    cin >> num;

    for(int i = 0; i < num; i++){cin >> arr[i];}

    for(int i = num - 1; i >= 0; i--){
        while (!st.empty() && st.top() <= arr[i]){st.pop();}

        if(st.empty()) result[i] = -1;
        else result[i] = st.top();

        st.push(arr[i]);
    }

    for(int i = 0; i < num; i++)
        cout << result[i] << " ";
}
// 21288
// 53433 