#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	cin.ignore();

	queue<int> q;
	for(int i = 0; i < n; ++i) {
		string com;
		getline(cin,com);

		if(com == "front") {
			if(!q.empty())
				cout << q.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if(com == "back") {
			if(!q.empty()) {
				cout << q.back() << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else if(com == "empty") {
			if(q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if(com == "size") {
			cout << q.size() << "\n";
		}
		else if(com == "pop") {
			if(!q.empty()) {
				int n = q.front();
				cout << n << "\n";
				q.pop();
			}
			else
				cout << -1 << "\n";
		}
		else {
			int n = stoi(com.substr(5));
			q.push(n);
		}
	}
}