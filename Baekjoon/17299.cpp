#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000001

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n + 1);
	vector<int> result(n + 1, - 1);
	vector<int> cnt(MAX + 1, 0);
	stack<int> st;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	for (int i = 1; i <= n; i++)
	{
		while (!st.empty() && cnt[arr[st.top()]]< cnt[arr[i]])
		{
			result[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << ' ';
	}
	cout << '\n';

	return 0;
}
//48~~