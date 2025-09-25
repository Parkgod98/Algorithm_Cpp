#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

int main(void) {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}


	vector<vector<int>> visited(n, vector<int>(m));
	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == 1 && !visited[i][j]) {
				++cnt;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;

				while (!q.empty()) {
					auto it = q.front();
					q.pop();

					int y = it.first;
					int x = it.second;

					for (int d = 0; d < 8; ++d) {
						int ny = y + dy[d];
						int nx = x + dx[d];
						if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || v[ny][nx] == 0)
							continue;

						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}
			}
		}
	}

	cout << cnt << "\n";
}