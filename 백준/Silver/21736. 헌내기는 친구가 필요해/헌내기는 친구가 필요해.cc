#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
int N, M;
vector<vector<char>> v;
vector<vector<bool>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct Point {
	int y, x;
};
Point doy;
int main() {
	cin >> N >> M;
	v = vector<vector<char>>(N, vector<char>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 'I')
				doy = { i,j };
		}
	}

	visited = vector<vector<bool>>(N, vector<bool>(M));
	queue<Point> q;
	q.push(doy);
	visited[doy.y][doy.x] = 1;

	int cnt = 0;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.y;
		int x = it.x;
		if (v[y][x] == 'P')
			++cnt;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || v[ny][nx] == 'X')
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}
	if (cnt == 0)
		cout << "TT" << "\n";
	else
		cout << cnt << "\n";


}


