#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int N, M;
vector<vector<int>> v;
vector<vector<int>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int cnt = 0;

void PrintV() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}

int DFS(int y, int x) {
	int cur = v[y][x];

	if (y == N - 1 && x == M - 1)
		return 1;
	if (visited[y][x] == -1) {
		visited[y][x] = 0;
		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || v[ny][nx] >= cur)
				continue;
			visited[y][x] += DFS(ny, nx);
		}
	}

	return visited[y][x];
}

int main() {
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(M));
	visited = vector<vector<int>>(N, vector<int>(M,-1));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> v[i][j];
	}

	cout << DFS(0, 0) << "\n";
}
