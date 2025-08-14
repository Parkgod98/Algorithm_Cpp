#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<vector<int>> v;
int dy[4] = { -1,-1,1,1 };
int dx[4] = { -1,1,1,-1 };
int desert[101] = { 0 };
vector<vector<bool>> visited;
vector<int> ban(4);
int mx = 0;
void Input() {
	cin >> N;
	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}
	visited = vector<vector<bool>>(N, vector<bool>(N));
	mx = 0;
}

void InitDesert() {
	for (int i = 0; i < 101; ++i) {
		desert[i] = 0;
	}
}

int Count() {
	int cnt = 0;
	for (int i = 1; i <= 100; ++i) {
		if (desert[i])
			++cnt;
	}
	return cnt;
}

void DFS(int y, int x, int start, int sy, int sx, int prev_dir, vector<int> &ban) {

	for (int i = 0; i < 4; ++i) {
		if (ban[i])
			continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if ((prev_dir == 0 && i == 2) || (i == 0 && prev_dir == 2) || (prev_dir == 3 && i == 1) || (prev_dir == 1 && i == 3))
			continue;
		if (visited[ny][nx] && sy == ny && sx == nx) {
			mx = max(mx, Count());
			return;
		}
		if (visited[ny][nx])
			continue;
		if (desert[v[ny][nx]])
			continue;
		bool Flag = false;
		if (prev_dir != -1 && prev_dir != i) {
			ban[prev_dir] = 1;
			Flag = true;
		}
		visited[ny][nx] = 1;
		desert[v[ny][nx]] = 1;
		DFS(ny, nx, start, sy, sx,i,ban);
		visited[ny][nx] = 0;
		desert[v[ny][nx]] = 0;
		if (Flag)
			ban[prev_dir] = 0;
	}
}

void Solve() {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			visited[i][j] = 1;
			desert[v[i][j]] = 1;
			DFS(i, j, v[i][j], i,j, -1, ban);
			visited[i][j] = 0;
			desert[v[i][j]] = 0;
		}
	}
}
int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		Input();
		Solve();
		if (mx == 0)
			mx = -1;
		cout << "#" << tc << " " << mx << "\n";
 	}
}