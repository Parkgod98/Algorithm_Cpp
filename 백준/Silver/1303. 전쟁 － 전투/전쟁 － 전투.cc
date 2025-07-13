#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
vector<vector<char>> v;
vector<vector<int>> visited;
int w, b;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void BFS(int y, int x) {
	int cur = v[y][x];

	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;

	int cnt = 0;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		++cnt;

		int yy = it.first;
		int xx = it.second;
		for (int i = 0; i < 4; ++i) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || v[ny][nx] != cur)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}

	if (cur == 'W')
		w += (cnt * cnt);
	else
		b += (cnt * cnt);
}

int main(void) {
	cin >> M >> N;
	v = vector<vector<char>>(N, vector<char>(M));
	visited = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!visited[i][j]) {
				BFS(i, j);
			}
		}
	}

	cout << w << " " << b << "\n";
}
