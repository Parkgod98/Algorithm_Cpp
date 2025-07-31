#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<vector<int>> v;
vector<int> visited;
vector<pair<int, int>> num;

int DFS(int cur, int depth) {
	visited[cur] = 1;

	int cnt = 1;
	if (depth > 0)
		num[cur].first++;
	for (int &n : v[cur]) {
		if (!visited[n]) {
			cnt += DFS(n,depth+1);
		}
	}
	return cnt;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		cin >> M;

		// (나보다 작은 사람, 나보다 큰 사람 수)
		num = vector<pair<int, int>>(N + 1, {0,0});
		v = vector<vector<int>>(N + 1);
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}
		for (int i = 1; i <= N; ++i) {
			visited = vector<int>(N + 1);
			num[i].second = DFS(i,0) -1;
			
		}

		int cnt = 0;
		for (int i = 1; i <= N; ++i) {
			int s = num[i].first + num[i].second;
			if (s == N - 1)
				++cnt;
		}

		cout << "#" << tc << " " << cnt << "\n";
	}
}