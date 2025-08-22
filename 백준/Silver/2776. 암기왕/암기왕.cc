#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;
vector<int> res;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;
		map<int, bool> m1;
		for (int i = 0; i < N; ++i) {
			int n;
			cin >> n;
			m1[n] = 1;
		}

		int M;
		cin >> M;
		map<int, bool> m2;
		for (int i = 0; i < M; ++i) {
			int n;
			cin >> n;
			if (m1.find(n) == m1.end())
				res.push_back(0);
			else
				res.push_back(1);
		}

		for (int &n : res)
			cout << n << "\n";
		res.clear();
	}
} 