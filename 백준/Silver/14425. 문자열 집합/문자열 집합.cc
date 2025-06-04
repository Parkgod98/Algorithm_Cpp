#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	cin.ignore();
	unordered_set<string> s;
	for (int i = 0; i < N; ++i) {
		string t;
		getline(cin, t);
		s.insert(t);
	}

	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		string t;
		getline(cin, t);

		if (s.find(t) != s.end()) {
			++cnt;
		}
	}

	cout << cnt << "\n";
}
