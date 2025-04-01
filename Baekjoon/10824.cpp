#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string a, b, c, d;
	long long num1, num2 = 0;	

	cin >> a >> b >> c >> d;

	a += b;	
	c += d;	

	num1 = stoll(a);
	num2 = stoll(c);

	cout << num1 + num2;  

	return 0;
}