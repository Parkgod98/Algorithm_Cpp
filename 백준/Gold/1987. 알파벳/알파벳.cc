#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R, C;
vector<vector<char>> v;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[26] = { 0 };
int mx = 0;

void DFS(int y, int x, int depth) {
	if (y < 0 || y >= R || x < 0 || x >= C || visited[v[y][x]]) {
		return;
	}

	visited[v[y][x]] = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		DFS(ny, nx, depth + 1);
	}
	visited[v[y][x]] = 0;
	mx = max(mx, depth);
}
int main() {
	cin >> R >> C;
	v = vector<vector<char>>(R, vector<char>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j)
			cin >> v[i][j];
	}

	DFS(0, 0, 1);
	cout << mx << "\n";
}