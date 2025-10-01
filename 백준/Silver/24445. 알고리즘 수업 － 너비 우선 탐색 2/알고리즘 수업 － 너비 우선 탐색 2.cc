#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, R;
vector<vector<int>> v;
int main() {
	cin >> N >> M >> R;
	v = vector<vector<int>>(N + 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) {
		sort(v[i].begin(), v[i].end(), greater<int>());
	}

	queue<int> q;
	vector<int> visited(N + 1);
	visited[R] = 1;
	q.push(R);

	int cnt = 2;
	while (!q.empty()) {
		int n = q.front();
		q.pop();

		for (auto &nxt : v[n]) {
			if (!visited[nxt]) {
				q.push(nxt);
				visited[nxt] = cnt++;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << visited[i] << "\n";
	}
}