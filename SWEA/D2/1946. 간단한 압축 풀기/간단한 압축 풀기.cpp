#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		cout << "#" << tc << "\n";
		
		vector<pair<char, int>> v;
		for (int i = 0; i < N; ++i) {
			char a;
			int b;
			cin >> a >> b;
			v.push_back({ a,b });
		}

		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < v[i].second; ++j) {
				cout << v[i].first;
				cnt++;
				if (cnt == 10) {
					cout << "\n";
					cnt = 0;
				}
			}
		}
		cout << "\n";

	}
}