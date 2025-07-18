#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N, M;
pair<int, int> robot;
int r_dir;
vector<vector<int>> v,visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool Check(int y, int x) {

	bool Find = false;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || v[ny][nx] == 1 || v[ny][nx] == 2)
			continue;
		if (v[ny][nx] == 0)
			return true;
	}
	return false;
}

void PrintV(vector<vector<int>> &v) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}
int main() {
	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;
	robot = { r,c };
	r_dir = d;

	v = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> v[i][j];
	}

	queue<pair<int, int>> q;
	q.push(robot);
	v[robot.first][robot.second] = 2;
	int cnt = 1;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.first;
		int x = it.second;
		if (Check(y, x)) { // 근처에 청소안된 칸이 존재
			while (1) {
				int new_dir = (r_dir + 3) % 4;
				int ny = y + dy[new_dir];
				int nx = x + dx[new_dir];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M || v[ny][nx] == 1 || v[ny][nx] == 2) {
					r_dir = new_dir;
					continue;
				}
				if (v[ny][nx] == 0) {
					++cnt;
					r_dir = new_dir;
					robot = { ny,nx };
					q.push(robot);
					v[ny][nx] = 2;
					break;
				}
			}
			
		}
		else { // 근처에 청소 안된 칸이 존재하지 않음.
			int new_dir = (r_dir + 2) % 4;
			int ny = y + dy[new_dir];
			int nx = x + dx[new_dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || v[ny][nx] == 1)
				break;
			robot = { ny,nx };
			q.push(robot);
		}
	}

	cout << cnt << "\n";
}
