#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int r, c;

void bfs(vector<vector<int>>& v, vector<vector<bool>>& visited, int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || v[ny][nx] == 0)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = true;
		}
	}
}

int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i) {
		cin >> c >> r;
		vector<vector<int>> v(r, vector<int>(c, 0));
		vector<vector<bool>> visited(r, vector<bool>(c, false));

		int k;
		cin >> k;

		for (int j = 0; j < k; ++j) {
			int x, y;
			cin >> x >> y;
			v[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (!visited[i][j] && v[i][j] == 1) {
					bfs(v, visited, i, j);
					++cnt;
				}
			}
		}
		cout << cnt << "\n";
	}
	
}