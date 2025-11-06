#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> v;
vector<vector<int>> area;

int rnum, w_h, mx_area;
struct Point {
	int y, x;
};

int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

void BFS() {


	vector<vector<int>> visited(N, vector<int>(M));
	int color = 1;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!visited[i][j]) {
				int cnt = 0;
				queue<Point> q;
				q.push({ i,j });
				visited[i][j] = color;

				while (!q.empty()) {
					auto it = q.front();
					q.pop();

					int y = it.y;
					int x = it.x;
					++cnt;
					for (int d = 0; d < 4; ++d) {
						int mask = 1 << d;

						if ((mask & v[y][x]) == 0) {
							int ny = y + dy[d];
							int nx = x + dx[d];

							if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
								continue;
							q.push({ ny,nx });
							visited[ny][nx] = color;
						}
					}
				}
				++color;
				w_h = max(cnt, w_h);
			}
		}
	}

	vector<int> area_num(color);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			area_num[visited[i][j]]++;
		}
	}

	rnum = color - 1;


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			
			for (int d = 0; d < 4; ++d) {
				int ny = i + dy[d];
				int nx = j + dx[d];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] == visited[i][j])
					continue;

				mx_area = max(mx_area, (area_num[visited[ny][nx]] + area_num[visited[i][j]]));
			}
		}
	}
}
int main() {
	cin >> M >> N;
	v = area = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
		}
	}

	//for (int d = 0; d < 4; ++d) {
	//	int mask = 1 << d;
	//	cout << mask << "\n";
	//}
	BFS();


	cout << rnum << "\n" << w_h << "\n" << mx_area << "\n";
}