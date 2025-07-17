#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <list>
using namespace std;
int L, R, C;
vector<vector<vector<char>>> v;
int dz[6] = { 0,0,0,0,1,-1 };
int dy[6] = { -1,0,1,0,0,0 };
int dx[6] = { 0,1,0,-1,0,0 };

struct Point {
	int z, y, x;
};

void bfs(Point &s, Point &e) {
	int z = s.z;
	int y = s.y;
	int x = s.x;

	queue<Point> q;
	q.push({ z,y,x });
	vector<vector<vector<int>>> visited(L, vector<vector<int>>(R, vector<int>(C)));
	visited[z][y][x] = 1;

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int zz = it.z;
		int yy = it.y;
		int xx = it.x;
		for (int i = 0; i < 6; ++i) {
			int nz = zz + dz[i];
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C || visited[nz][ny][nx])
				continue;
			if (v[nz][ny][nx] == '#')
				continue;
			q.push({ nz,ny,nx });
			visited[nz][ny][nx] = visited[zz][yy][xx] + 1;
		}
	}

	if (visited[e.z][e.y][e.x])
		cout << "Escaped in " << visited[e.z][e.y][e.x] - 1 << " minute(s).\n";
	else
		cout << "Trapped!\n";
}

int main() {
	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		v = vector<vector<vector<char>>>(L, vector<vector<char>>(R, vector<char>(C)));

		Point s, e;
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					cin >> v[i][j][k];
					if (v[i][j][k] == 'S')
						s = { i,j,k };
					else if (v[i][j][k] == 'E')
						e = { i,j,k };
				}
			}
		}

		bfs(s,e);
	}
}