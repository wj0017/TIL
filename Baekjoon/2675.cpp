#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
    
	for (int i = 0; i < t; i++) {
		int r;
		string str;
		cin >> r;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			for (int k = 0; k < r; k++) {
				printf("%c", str[j]);
			}
		}
		printf("\n");
	}
}