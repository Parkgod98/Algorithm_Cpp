#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T;
int N, K;
int W;
vector<int> build_time;
vector<int> indegree;
vector<vector<int>> sequence;

int topology_sort() {
	queue<pair<int, int>> q;
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		if (indegree[i] == 0) {
			q.push({ i,build_time[i] });
			dp[i] = build_time[i];
		}
	}

	int res = 0;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int cur_node = it.first;
		int cur_time = it.second;
		if (cur_node == W)
			return dp[W];

		for (int &nxt : sequence[cur_node]) {
			indegree[nxt]--;
			dp[nxt] = max(dp[nxt], build_time[nxt] + cur_time);
			if (indegree[nxt] == 0)
				q.push({ nxt ,dp[nxt] });
		}
	}
}
int main() {
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;
		build_time = vector<int>(N + 1);
		for (int i = 1; i <= N; ++i)
			cin >> build_time[i];

		sequence = vector<vector<int>>(N + 1);
		indegree = vector<int>(N + 1);
		for (int i = 0; i < K; ++i) {
			int a, b;
			cin >> a >> b;
			sequence[a].push_back(b);
			++indegree[b];
		}

		cin >> W;

		int min_time = topology_sort();

		cout << min_time << "\n";
	}
}