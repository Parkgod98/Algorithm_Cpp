#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int N;
vector<vector<int>> visited(2001, vector<int>(2001));
vector<vector<int>> map(2001, vector<int>(2001,-1));
int sum = 0;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };
struct Elem {
	int y, x;
	int dir = -1;
	int K;
	bool die = false;
};
vector<Elem> v;

bool Alldie() {
	for (int i = 0; i < N; ++i) {
		if (v[i].die == false)
			return false;
	}
	return true;
}

void CheckOut() {
	for (int i = 0; i < N; ++i) {
		if (v[i].die == false) {
			int y = v[i].y;
			int x = v[i].x;
			int dir = v[i].dir;

			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny > 2000 || nx < 0 || nx > 2000)
				v[i].die = true;
		}
	}
}

void CheckZzum5() {
	/* 안죽은 원자들 싹다 맵에 배치하고. */
	for (int i = 0; i < N; ++i) {
		if (v[i].die == false) {
			int y = v[i].y;
			int x = v[i].x;
			map[y][x] = i;
		}
	}

	// 안죽은 원자들 다음 좌표 구해서. 다음 좌표에 원자가 있을떄 서로 바라본다면
	for (int i = 0; i < N; ++i) {
		if (v[i].die == false) {
			int y = v[i].y;
			int x = v[i].x;
			int dir = v[i].dir;

			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (map[ny][nx] != -1 && ((v[i].dir == 0 && v[map[ny][nx]].dir == 1) || (v[i].dir == 1 && v[map[ny][nx]].dir == 0) || (v[i].dir == 2 && v[map[ny][nx]].dir == 3) || (v[i].dir == 3 && v[map[ny][nx]].dir == 2))) {
				sum += (v[map[ny][nx]].K + v[i].K);
				v[map[ny][nx]].die = true;
				v[i].die = true;
			}
		}
	}

	/* 일반적인 원자 */
	for (int i = 0; i < N; ++i) {
		if (v[i].die == false) {
			int y = v[i].y;
			int x = v[i].x;
			int dir = v[i].dir;

			int ny = y + dy[dir];
			int nx = x + dx[dir];
			visited[ny][nx]++;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (v[i].die == false) {
			int y = v[i].y;
			int x = v[i].x;
			int dir = v[i].dir;

			int py = y + dy[dir];
			int px = x + dx[dir];
			if (visited[py][px] >= 2) {
				for (int d = 0; d < 4; ++d) {
					int ny = py + dy[d];
					int nx = px + dx[d];
					if (ny < 0 || ny > 2000 || nx < 0 || nx > 2000)
						continue;
					if (map[ny][nx] == -1 || v[map[ny][nx]].die)
						continue;

					if (d == 0) {
						if (v[map[ny][nx]].dir == 1) {
							v[map[ny][nx]].die = true;
							sum += v[map[ny][nx]].K;
						}
					}
					else if (d == 1) {
						if (v[map[ny][nx]].dir == 0) {
							v[map[ny][nx]].die = true;
							sum += v[map[ny][nx]].K;
						}
					}
					else if (d == 2) {
						if (v[map[ny][nx]].dir == 3) {
							v[map[ny][nx]].die = true;
							sum += v[map[ny][nx]].K;
						}
					}
					else if (d == 3) {
						if (v[map[ny][nx]].dir == 2) {
							v[map[ny][nx]].die = true;
							sum += v[map[ny][nx]].K;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		int y = v[i].y;
		int x = v[i].x;
		int dir = v[i].dir;
		map[y][x] = -1;

		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(!(ny < 0 || ny > 2000 || nx < 0 || nx > 2000))
			visited[ny][nx] = 0;
		if (v[i].die == false) {
			v[i].y = ny;
			v[i].x = nx;
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		v = vector<Elem>(N);
		for (int i = 0; i < N; ++i) {
			int x, y, dir, K;
			cin >> x >> y >> dir >> K;
			v[i] = { y+1000,x+1000,dir,K };
		}

		while (!Alldie()) {
			CheckOut(); // 나갈 사람들 die처리
			CheckZzum5();
		}

		cout << "#" << tc << " " << sum << "\n";
		sum = 0;
	}
}