#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		int com;
		cin >> com;

		int n;
		switch (com) {
		case 1:
			cin >> n;
			dq.push_front(n);
			break;
		case 2:
			cin >> n;
			dq.push_back(n);
			break;
		case 3:
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << -1 << "\n";
			break;
		case 4:
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
				cout << -1 << "\n";
			break;
		case 5:
			cout << dq.size() << "\n";
			break;
		case 6:
			if (dq.empty()) {
				cout << 1 << "\n";
			}
			else
				cout << 0 << "\n";
			break;
		case 7:
			if (!dq.empty()) {
				cout << dq.front() << "\n";
			}
			else
				cout << -1 << "\n";
			break;
		case 8:
			if (!dq.empty()) {
				cout << dq.back() << "\n";
			}
			else
				cout << -1 << "\n";
			break;
		}
	}
}