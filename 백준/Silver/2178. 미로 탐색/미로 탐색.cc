#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;

int mp[102][102];
int visited[102][102];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct Point {
	int y, x;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c;
			cin >> c;

			mp[i][j] = c - '0';
		}
	}

	int cnt = 0;

	queue<Point> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.y;
		int x = it.x;

		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
				continue;
			if (mp[ny][nx] == 0)
				continue;

			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}

	cout << visited[N - 1][M - 1] << "\n";
}