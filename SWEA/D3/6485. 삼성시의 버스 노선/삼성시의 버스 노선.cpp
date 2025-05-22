#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		vector<pair<int, int>> v(N+1);
		for (int i = 1; i <= N; ++i) {
			int ai, bi;
			cin >> ai >> bi;
			v[i] = { ai,bi };
		}

		int p;
		cin >> p;

		vector<int> res(p);
		for (int i = 0; i < p; ++i) {
			int n;
			cin >> n;

			for (int j = 1; j <= N; ++j) {
				if (v[j].first <= n && v[j].second >= n)
					++res[i];
			}
		}
		
		cout << "#" << tc << " ";
		for (int &i : res)
			cout << i << " ";
		cout << "\n";
	}
}