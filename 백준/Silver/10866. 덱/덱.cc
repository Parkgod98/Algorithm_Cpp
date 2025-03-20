#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	deque<int> dq;
	for(int i = 0; i < n; ++i) {
		string c;
		cin >> c;
		if(c == "push_front") {
			int n;
			cin >> n;
			dq.push_front(n);
		}
		else if(c == "push_back") {
			int n;
			cin >> n;
			dq.push_back(n);
		}
		else if(c == "pop_front") {
			if(!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if(c == "pop_back") {
			if(!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		else if(c == "size") {
			cout << dq.size() << "\n";

		}
		else if(c == "empty") {
			if(dq.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if(c == "front") {
			if(!dq.empty())
				cout << dq.front() << "\n";
			else
				cout << -1 << "\n";

		}
		else if(c == "back") {
			if(!dq.empty())
				cout << dq.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}
}