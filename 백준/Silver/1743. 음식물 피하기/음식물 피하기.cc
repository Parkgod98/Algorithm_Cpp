#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, K;
vector<vector<int>> v,visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int mx;
int main(void) {
	cin >> N >> M >> K;
	v = vector<vector<int>>(N, vector<int>(M));
	visited = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < K; ++i) {
		int r, c;
		cin >> r >> c;
		v[r - 1][c - 1] = 1;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j] == 1 && !visited[i][j]) {

				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;
				int cnt = 0;
				
				while (!q.empty()) {
					auto it = q.front();
					q.pop();
					++cnt;

					int y = it.first;
					int x = it.second;
					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M || v[ny][nx] == 0 || visited[ny][nx])
							continue;

						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}

				mx = max(mx, cnt);
			}
		}
	}

	cout << mx << "\n";

}
