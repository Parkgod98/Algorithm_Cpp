#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> st;
	for (int i = 0; i < N; ++i) {
		int com;
		cin >> com;

		switch (com) {
		case 1:
			int x;
			cin >> x;
			st.push(x);
			break;
		case 2:
			if (!st.empty()) {
				cout << st.top() << "\n";
				st.pop();
			}
			else
				cout << -1 << "\n";
			break;
		case 3:
			cout << st.size() << "\n";
			break;
		case 4:
			if (st.empty()) {
				cout << 1 << "\n";
			}
			else
				cout << 0 << "\n";
			break;
		case 5:
			if (!st.empty()) {
				cout << st.top() << "\n";
			}
			else
				cout << -1 << "\n";
			break;
		}
	}
}
