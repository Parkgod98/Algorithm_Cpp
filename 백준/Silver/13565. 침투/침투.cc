#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int main() {
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j)
			v[i][j] = s[j] - '0';
	}

	queue<pair<int, int>> q;
	vector<vector<int>> visited(N, vector<int>(M));
	for (int i = 0; i < M; ++i) {
		if (v[0][i] == 0) {
			q.push({ 0,i });
			visited[0][i] = 1;
		}
	}

	bool f = false;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.first;
		int x = it.second;

		if (y == N - 1) {
			f = true;
			break;
		}
		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || v[ny][nx] == 1)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}
	if (f)
		cout << "YES\n";
	else
		cout << "NO\n";
}