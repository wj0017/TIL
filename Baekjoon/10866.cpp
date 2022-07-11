#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n,m;
    queue<int> q;
	queue<int> ans;

	cin >> n >> m;
    for (int i = 1; i < n + 1; i++){q.push(i);}
	cout << "<";

	while (q.size()-1){
		for (int i = 1; i < m; i++) {
			int t = q.front();
			q.pop();
			q.push(t);
		}
		cout << q.front() << ", ";
		q.pop();
	}
    cout << q.front() << ">";
	q.pop();
	return 0;
}