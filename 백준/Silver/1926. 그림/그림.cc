#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;
vector<vector<int>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int main()
{
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> v[i][j];
	}

	int mx = 0;
	int cnt, area;
	cnt = 0;
	vector<vector<bool>> visited(N, vector<bool>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			area = 0;
			if (v[i][j] == 1 && !visited[i][j]) {
				++cnt;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;

				while (!q.empty()) {
					++area;
					auto it = q.front();
					q.pop();
					int y = it.first;
					int x = it.second;

					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M || !v[ny][nx] || visited[ny][nx])
							continue;
						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}
				mx = max(mx, area);
			}
		}
	}

	cout << cnt << "\n" << mx << "\n";
}