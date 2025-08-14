#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
int N, K;
vector<vector<int>> v;
vector<pair<int, int>> start_point;
vector<vector<bool>> visited;
int mx_height = 0;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int mx_length = -9999999;

void Init() {
	start_point.clear();
	mx_height = 0;
	mx_length = -99999999;
}

void Input() {
	cin >> N >> K;
	v = vector<vector<int>>(N, vector<int>(N));
	visited = vector<vector<bool>>(N, vector<bool>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
			mx_height = max(v[i][j], mx_height);
		}
	}
}

void GetStartPoint() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (mx_height == v[i][j]) {
				start_point.push_back({ i,j });
			}
		}
	}
}

void Start(int y, int x, int depth) {
	mx_length = max(mx_length, depth);

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
			continue;
		if (v[ny][nx] >= v[y][x])
			continue;

		visited[ny][nx] = 1;
		Start(ny, nx, depth+1);
		visited[ny][nx] = 0;
	}
}

void GoAllCases() {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k <= K; ++k) {
				v[i][j] -= k;
				for (auto &p : start_point) {
					if (v[p.first][p.second] != mx_height)
						continue;
					visited[p.first][p.second] = 1;
					Start(p.first,p.second,1);
					visited[p.first][p.second] = 0;
				}
				v[i][j] += k;
			}
		}
	}
}
int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		Init();
		Input();
		GetStartPoint();
		GoAllCases();

		cout << "#" << tc << " " << mx_length << "\n";
	}
}


