#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, K;
vector<vector<char>> v;
vector<vector<int>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int mx;
int main(void) {
	cin >> N >> M;
	v = vector<vector<char>>(N, vector<char>(M));
	visited = vector<vector<int>>(N, vector<int>(M));
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
		}
	}

	int res_sheep, res_wolf;
	res_sheep = res_wolf = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j] != '#' && !visited[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;

				int sheep, wolf;
				sheep = wolf = 0;

				while (!q.empty()) {
					auto it = q.front();
					q.pop();

					int y = it.first;
					int x = it.second;
					if (v[y][x] == 'o')
						++sheep;
					else if (v[y][x] == 'v')
						wolf++;
					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M || v[ny][nx] == '#' || visited[ny][nx])
							continue;

						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}
				if (sheep > wolf) {
					res_sheep += sheep;
				}
				else
					res_wolf += wolf;
			}
		}
	}

	cout << res_sheep << " " << res_wolf << "\n";

}
