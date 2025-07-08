#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n;

int bfs(vector<vector<int>>& v, int limit) {

	vector<vector<bool>> visited(n, vector<bool>(n, false));

	queue<pair<int, int>> q;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j] && v[i][j] > limit) {
				++cnt;
				q.push({ i,j });
				visited[i][j] = true;
				while (!q.empty()) {
					auto it = q.front();
					q.pop();

					for (int k = 0; k < 4; ++k) {
						int ny = it.first + dy[k];
						int nx = it.second + dx[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || (v[ny][nx] <= limit))
							continue;
						q.push({ ny,nx });
						visited[ny][nx] = true;
					}
				}

			}
		}
	}

	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int mx = 0;
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
			mx = max(mx, v[i][j]);
		}
	}

	int res = 1;
	for (int i = 1; i <= mx; ++i) {
		res = max(res, bfs(v,i));
	}

	cout << res << "\n";
}