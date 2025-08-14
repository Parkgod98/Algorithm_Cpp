#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
int N, M, R, C, L;
vector<vector<int>> v;
vector<vector<int>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void PrintV() {
	cout << "\n";

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

}

void Init() {
	cin >> N >> M >> R >> C >> L;
	v = visited = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> v[i][j];
	}
}

int VisitCount() {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (visited[i][j])
				++cnt;
		}
	}

	return cnt;
}

void BFS() {
	queue<pair<int, int>> q;
	q.push({ R,C });
	visited[R][C] = 1;
	queue<pair<int, int>> new_q;
	for (int t = 1; t < L; ++t) {
		while (!q.empty()) {
			auto it = q.front();
			q.pop();

			int y = it.first;
			int x = it.second;
			if (v[y][x] != 0) {
				for (int i = 0; i < 4; ++i) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
						continue;
					if (v[y][x] == 2) {
						if (i == 1 || i == 3)
							continue;
						if (i == 0 && !(v[ny][nx] == 1 || v[ny][nx] == 2 || v[ny][nx] == 5 || v[ny][nx] == 6))
							continue;
						else if (i == 2 && !(v[ny][nx] == 1 || v[ny][nx] == 2 || v[ny][nx] == 4 || v[ny][nx] == 7))
							continue;
					}
					else if (v[y][x] == 3) {
						if (i == 0 || i == 2)
							continue;
						if (i == 1 && !(v[ny][nx] == 1 || v[ny][nx] == 3 || v[ny][nx] == 6 || v[ny][nx] == 7))
							continue;
						if (i == 3 && !(v[ny][nx] == 1 || v[ny][nx] == 3 || v[ny][nx] == 4 || v[ny][nx] == 5))
							continue;
					}
					else if (v[y][x] == 4) {
						if (i == 2 || i == 3)
							continue;
						if (i == 0 && !(v[ny][nx] == 1 || v[ny][nx] == 2 || v[ny][nx] == 5 || v[ny][nx] == 6))
							continue;
						if (i == 1 && !(v[ny][nx] == 1 || v[ny][nx] == 3 || v[ny][nx] == 6 || v[ny][nx] == 7))
							continue;
					}
					else if (v[y][x] == 5) {
						if (i == 0 || i == 3)
							continue;
						if (i == 1 && !(v[ny][nx] == 1 || v[ny][nx] == 3 || v[ny][nx] == 6 || v[ny][nx] == 7))
							continue;
						if (i == 2 && !(v[ny][nx] == 1 || v[ny][nx] == 2 || v[ny][nx] == 4 || v[ny][nx] == 7))
							continue;
					}
					else if (v[y][x] == 6) {
						if (i == 0 || i == 1)
							continue;
						if (i == 3 && !(v[ny][nx] == 1 || v[ny][nx] == 3 || v[ny][nx] == 4 || v[ny][nx] == 5))
							continue;
						if (i == 2 && !(v[ny][nx] == 1 || v[ny][nx] == 2 || v[ny][nx] == 4 || v[ny][nx] == 7))
							continue;
					}
					else if (v[y][x] == 7) {
						if (i == 1 || i == 2)
							continue;
						if (i == 0 && !(v[ny][nx] == 1 || v[ny][nx] == 2 || v[ny][nx] == 5 || v[ny][nx] == 6))
							continue;
						if (i == 3 && !(v[ny][nx] == 1 || v[ny][nx] == 3 || v[ny][nx] == 4 || v[ny][nx] == 5))
							continue;
					}
					else if (v[y][x] == 1) {
						if (i == 0 && !(v[ny][nx] == 1 || v[ny][nx] == 2 || v[ny][nx] == 5 || v[ny][nx] == 6))
							continue;
						if (i == 1 && !(v[ny][nx] == 1 || v[ny][nx] == 3 || v[ny][nx] == 6 || v[ny][nx] == 7))
							continue;
						if (i == 2 && !(v[ny][nx] == 1 || v[ny][nx] == 2 || v[ny][nx] == 4 || v[ny][nx] == 7))
							continue;
						if (i == 3 && !(v[ny][nx] == 1 || v[ny][nx] == 3 || v[ny][nx] == 4 || v[ny][nx] == 5))
							continue;
					}
					
					
					if (v[ny][nx] == 0)
						continue;
					new_q.push({ ny,nx });
					visited[ny][nx] = visited[y][x] + 1;
				}
			}
		}
		//PrintV();
		q = new_q;
	}
}


int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		Init();
		BFS();
		cout << "#" << tc << " " << VisitCount() << "\n";
	}
}


