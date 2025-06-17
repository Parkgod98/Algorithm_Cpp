#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		vector<int> v2(N+1);

		for (int i = 1; i <= N; ++i) {
			cin >> v2[i];
		}

		vector<vector<int>> v(N+1);
		for (int i = 0; i < N; ++i) {
			v[i + 1].push_back(v2[i + 1]);
		}

		int cnt = 0;
		vector<bool> visited(N + 1);

		queue<int> q;
		for (int i = 1; i <= N; ++i) {
			if (visited[i])
				continue;
			++cnt;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int n = q.front();
				q.pop();
				for (int &k : v[n]) {
					if (!visited[k]) {
						q.push(k);
						visited[k] = 1;
					}
				}
			}
		}
		cout << cnt << "\n";
	}
}  