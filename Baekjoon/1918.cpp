#include <iostream>
#include <stack>
using namespace std;

int priority(char c)
{
	switch (c)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		break;
	}
}

int main()
{
	stack<char> op;
	string exp;
	cin >> exp;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] >= 'A' && exp[i] <= 'Z')
		{
			cout << exp[i];
		}
		else if (exp[i] == '(')
		{
			op.push('(');
		}
		else if (exp[i] == ')')
		{
			while (op.top() != '(')
			{
				cout << op.top();
				op.pop();
			}
			op.pop();
		}
		else
		{
			while (!op.empty() && priority(op.top()) >= priority(exp[i]))
			{
				cout << op.top();
				op.pop();
			}
			op.push(exp[i]);
		}
		
	}

	while (!op.empty())
	{
		cout << op.top();
		op.pop();
	}
	cout << '\n';

	return 0;
}