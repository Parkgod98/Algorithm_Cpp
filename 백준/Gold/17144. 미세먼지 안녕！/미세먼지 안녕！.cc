#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n, m, t;
vector<vector<int>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

pair<int, int> up, down;

void PrintV() {
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}
void Spread() {

	vector<vector<int>> visited(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] > 0) {
				int sum = 0;
				for (int d = 0; d < 4; ++d) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m || v[ny][nx] == -1)
						continue;
					int val = v[i][j] / 5;
					visited[ny][nx] += val;
					sum += val;
				}
				visited[i][j] -= sum;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			v[i][j] += visited[i][j];
		}
	}
	//PrintV();
}

void Clean() {

	int sy = up.first;
	int sx = up.second;
	sx += 1;
	int dir = 1;
	deque<int> dq;
	while (1) {
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];
		dq.push_back(v[sy][sx]);
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
			dir = (dir + 3) % 4;
			ny = sy + dy[dir];
			nx = sx + dx[dir];
		}
		if (v[ny][nx] == -1)
			break;
		sy = ny;
		sx = nx;
	}
	dq.pop_back();
	v[up.first][up.second + 1] = 0;
	sy = up.first;
	sx = up.second + 1;
	dir = 1;

	while (!dq.empty()) {
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
			dir = (dir + 3) % 4;
			ny = sy + dy[dir];
			nx = sx + dx[dir];
		}
		if (v[ny][nx] == -1)
			break;
		v[ny][nx] = dq.front();
		dq.pop_front();
		sy = ny;
		sx = nx;
	}

	sy = down.first;
	sx = down.second;
	sx += 1;
	dir = 1;

	while (1) {
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];
		dq.push_back(v[sy][sx]);
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
			dir = (dir + 1) % 4;
			ny = sy + dy[dir];
			nx = sx + dx[dir];
		}
		if (v[ny][nx] == -1)
			break;
		sy = ny;
		sx = nx;
	}


	dq.pop_back();
	v[down.first][down.second + 1] = 0;
	sy = down.first;
	sx = down.second + 1;
	dir = 1;
	while (!dq.empty()) {
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
			dir = (dir + 1) % 4;
			ny = sy + dy[dir];
			nx = sx + dx[dir];
		}
		if (v[ny][nx] == -1)
			break;
		v[ny][nx] = dq.front();
		dq.pop_front();
		sy = ny;
		sx = nx;
	}

	//PrintV();

}

int GetSum() {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			sum += v[i][j];
	}
	sum += 2;
	return sum;
}

int main() {
	cin >> n >> m >> t;
	v = vector<vector<int>>(n, vector<int>(m));
	up = down = { -1,-1 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
			if (v[i][j] == -1 && up.first == -1)
				up = { i,j };
			else if (v[i][j] == -1 && down.first == -1)
				down = { i,j };
		}
	}

	//cout << "\n";
	//Spread();

	for (int i = 0; i < t; ++i) {
		Spread();
		Clean();
	}

	cout << GetSum() << "\n";
}