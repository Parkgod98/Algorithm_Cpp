#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, D;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<vector<int>> v;
int cnt = 0;
struct Point {
	int y, x;
};
vector<Point> attacker(3);
int mx_cnt = 0;
bool GameOver() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j] == 1)
				return false;
		}
	}
	return true;
}

void Move() {
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < M; ++j) {
			if (i == N - 1 && v[i][j] == 1)
				v[i][j] = 0;
			else if (i != N - 1 && v[i][j] == 1) {
				v[i][j] = 0;
				v[i + 1][j] = 1;
			}
		}
	}
}

Point WhereShoot(int sy, int sx) {
	queue<Point> q;
	vector<vector<int>> visited(N, vector<int>(M));
	q.push({ sy,sx });

	int min_dist = 999999;
	Point res = { 99999,99999 };
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

			int dist = abs(ny - sy) + abs(nx - sx);
			if (dist > D)
				continue;

			q.push({ ny,nx });
			visited[ny][nx] = dist;

			if (v[ny][nx] == 1 && dist < min_dist) {
				min_dist = dist;
				res.y = ny;
				res.x = nx;
			}
			else if (v[ny][nx] == 1 && dist == min_dist && res.x > nx) {
				res.x = nx;
				res.y = ny;
			}
		}
	}
	
	return res;
}
vector<vector<int>> origin;
vector<int> attack_position;

void Comb(int depth, int idx) {
	if (depth == 3) {
		while (!GameOver()) {
			vector<Point> kill_list(3);
			for (int i = 0; i < 3; ++i) {
				kill_list[i] = WhereShoot(attacker[i].y, attacker[i].x);
			}

			for (int i = 0; i < 3; ++i) {
				int y = kill_list[i].y;
				int x = kill_list[i].x;
				if (y != 99999 && x != 99999 && v[y][x] == 1) {
					v[y][x] = 0;
					++cnt;
				}
			}
			Move();
		}
		v = origin;
		mx_cnt = max(mx_cnt, cnt);
		cnt = 0;
		return;
	}

	for (int i = idx; i < M; ++i) {
		attacker[depth] = { N,i };
		Comb(depth+1, i+1);
		attacker[depth] = { N,-1 };
	}
}

int main() {
	cin >> N >> M >> D;
	v = vector<vector<int>>(N, vector<int>(M));
	attack_position = vector<int>(M);

	for (int i = 0; i < M; ++i)
		attack_position[i] = i;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> v[i][j];
	}

	origin = v;
	Comb(0,0);
		

	cout << mx_cnt << "\n";
}