#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	getline(cin, s);

	int cnt = 0; 
    bool flag = true;
    
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			flag = true;
		}
		else if (flag) {
			flag = false;
			cnt++;
		}

	}
	cout << cnt;

	return 0;
}