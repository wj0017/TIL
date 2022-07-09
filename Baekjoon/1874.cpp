#include <iostream>
#include <stack>
#include <vector>
 
using namespace std;

int main(){

    stack<int> a; 
    vector<char> b;

    int num, num_ = 1;
    cin >> num;

    while(num--){
        int c;
        cin >> c;

        while ( num_ <= c )
		{
			a.push(num_);
			b.push_back('+');
            num_++;
		}

        if (a.top() == c)//
		{
			a.pop();
			b.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
 
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << '\n';
	}
}