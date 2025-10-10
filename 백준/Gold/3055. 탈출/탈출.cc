#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Point {
	int y, x;
};

int R, C;
vector<vector<char>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int t = 0;
bool Can = false;

void BFS() {
	queue<Point> wq;
	queue<Point> bq;

	vector<vector<int>> visited(R, vector<int>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (v[i][j] == '*') {
				wq.push({ i,j });
			}
			else if (v[i][j] == 'S')
				bq.push({ i,j });
		}
	}

	while (1) { 
		queue<Point> nwq, nbq;
		while (!wq.empty()) {
			auto it = wq.front();
			wq.pop();
			int y = it.y;
			int x = it.x;

			visited[y][x] = 1;
			for (int d = 0; d < 4; ++d) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
					continue;
				if (v[ny][nx] == '*' || v[ny][nx] == 'X' || v[ny][nx] == 'D' || v[ny][nx] == 'S')
					continue;
				nwq.push({ ny,nx });
				visited[ny][nx] = 1;
			}
		}

		while (!bq.empty()) {
			auto it = bq.front();
			bq.pop();
			int y = it.y;
			int x = it.x;

			if (v[y][x] == 'D') {
				Can = true;
				return;
			}
			for (int d = 0; d < 4; ++d) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
					continue;
				if (v[ny][nx] == '*' || v[ny][nx] == 'X')
					continue;
				nbq.push({ ny,nx });
				visited[ny][nx] = 1;
			}
		}

		if (nbq.empty()) {
			break;
		}
		++t;
		bq = nbq;
		wq = nwq;
	}
	
}

int main() {
	cin >> R >> C;
	v = vector<vector<char>>(R, vector<char>(C));

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> v[i][j];
		}
	}

	BFS();
	if (Can) {
		cout << t << "\n";
	}
	else
		cout << "KAKTUS\n";
}