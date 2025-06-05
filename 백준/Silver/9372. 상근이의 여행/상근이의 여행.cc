#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> v(N + 1);
		vector<bool> visited(N + 1);
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		int cnt = 0;
		for (int i = 1; i <= N; ++i) {
			for (int &n : v[i]) {
				if (!visited[n]) {
					visited[n] = true;
					++cnt;
				}
			}
		}
		cout << cnt-1 << "\n";
	}
}