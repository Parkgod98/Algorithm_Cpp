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

		int cnt = 0;
		vector<bool> visited(N + 1);

		queue<int> q;
		for (int i = 1; i <= N; ++i) {
			if (visited[i])
				continue;
			++cnt;
			int cur = i;
			while (!visited[cur]) {
				visited[cur] = 1;
				cur = v2[cur];
			}
		}
		cout << cnt << "\n";
	}
}  