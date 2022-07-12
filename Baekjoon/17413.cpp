#include <iostream>
#include <stack>
#include <string>
using namespace std;
void fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int main(void)
{
	fast_io();
	stack<char> s;
	string str;
	int i = 0;
	getline(cin, str);
	while (str[i] != '\0')
	{
		if (str[i] == '<')
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			while (true)
			{
				cout << str[i];
				if (str[i] == '>')
					break;
				i++;
			}
		}
		else if (isalnum(str[i]))
		{
			s.push(str[i]);
		}
		else
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << " ";
		}
		i++;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}