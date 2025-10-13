#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define INF 99999
int N, M;
vector<vector<int>> v;
vector<vector<vector<int>>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
struct Point {
	int y, x;
};
int main() {
	cin >> M >> N;
	v = vector<vector<int>>(N, vector<int>(M));
	visited = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(1,INF)));
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j) {
			v[i][j] = s[j] - '0';
		}
	}
	
	queue<Point> q;
	q.push({ 0,0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.y;
		int x = it.x;

		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (v[ny][nx] == 1 && visited[ny][nx][0] > visited[y][x][0] + 1) {
				q.push({ ny,nx });
				visited[ny][nx][0] = visited[y][x][0] + 1;
			}
			else if (v[ny][nx] == 0 && visited[ny][nx][0] > visited[y][x][0]) {
				q.push({ ny,nx });
				visited[ny][nx][0] = visited[y][x][0];
			}
		}
	}

	cout << visited[N - 1][M - 1][0] - 1 << "\n";

}
