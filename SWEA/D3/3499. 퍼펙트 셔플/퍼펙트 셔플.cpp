#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		queue<string> a, b;
		if (N % 2 == 0) {
			for (int i = 0; i < N / 2; ++i) {
				string s;
				cin >> s;
				a.push(s);
			}
			for (int i = 0; i < N / 2; ++i) {
				string s;
				cin >> s;
				b.push(s);
			}
		}
		else {
			for (int i = 0; i < (N / 2) +1; ++i) {
				string s;
				cin >> s;
				a.push(s);
			}
			for (int i = 0; i < N / 2; ++i) {
				string s;
				cin >> s;
				b.push(s);
			}
		}

		cout << "#" << tc << " ";
		while (!(a.empty() && b.empty())) {
			if (!a.empty()) {
				cout << a.front() << " ";
				a.pop();
			}
			if (!b.empty()) {
				cout << b.front() << " ";
				b.pop();
			}
		}
		cout << "\n";
	}
}