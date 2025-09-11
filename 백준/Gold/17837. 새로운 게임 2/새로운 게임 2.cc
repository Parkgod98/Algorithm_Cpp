#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n, k;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
struct Unit {
	int y, x;
	int dir;
	int num;
};
vector<vector<int>> v;
vector<vector<vector<Unit>>> unit_board;
vector<Unit> unit;
bool Detect = false;

void Go(int y, int x, int ny, int nx, int u) {
}

void Move(int u) {
	int y = unit[u].y;
	int x = unit[u].x;
	int dir = unit[u].dir;

	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx] == 2) {
		dir ^= 1;
		ny = y + dy[dir];
		nx = x + dx[dir];
		unit[u].dir = dir;
	}

	if (ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx] == 2) {
		return;
	}
	else if (v[ny][nx] == 0) {
		vector<Unit> Move_list;
		int cnt = 0;
		int idx = 0;
		for (int i = 0; i < unit_board[y][x].size(); ++i) {
			if (unit_board[y][x][i].num == u) {
				idx = i;
				break;
			}
		}

		for (int i = idx; i < unit_board[y][x].size(); ++i) {
			int num = unit_board[y][x][i].num;
			unit[num].y = ny;
			unit[num].x = nx;
			Move_list.push_back(unit[num]);
			++cnt;
		}
		for (int i = 0; i < cnt; ++i) {
			unit_board[y][x].pop_back();
		}

		for (auto &it : Move_list) {
			unit_board[ny][nx].push_back(it);
			it.y = ny;
			it.x = nx;
		}
		if (unit_board[ny][nx].size() >= 4)
			Detect = true;
	}
	else if (v[ny][nx] == 1) {
		vector<Unit> Move_list;
		int cnt = 0;
		int idx = 0;

		for (int i = 0; i < unit_board[y][x].size(); ++i) {
			if (unit_board[y][x][i].num == u) {
				idx = i;
				break;
			}
		}

		for (int i = unit_board[y][x].size()-1; i >= idx; --i) {
			int num = unit_board[y][x][i].num;
			unit[num].y = ny;
			unit[num].x = nx;
			Move_list.push_back(unit_board[y][x][i]);
			++cnt;
		}

		for (int i = 0; i < cnt; ++i) {
			unit_board[y][x].pop_back();
		}

		for (auto &it : Move_list) {
			unit_board[ny][nx].push_back(it);
			it.y = ny;
			it.x = nx;
		}

		if (unit_board[ny][nx].size() >= 4)
			Detect = true;
	}
}

void PrintV() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << "y : " << i << " x : " << j << "\n";
			for (auto &it : unit_board[i][j]) {
				cout << "num : " << it.num << " y : " << it.y << " x : " << it.x << " dir : " << it.dir << "\n";
			}
		}
	}
	cout << "\n";
}

int main(void) {
	cin >> n >> k;
	v = vector<vector<int>>(n, vector<int>(n));
	unit_board = vector<vector<vector<Unit>>>(n, vector<vector<Unit>>(n));
	unit = vector<Unit>(k + 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
	}

	for (int i = 1; i <= k; ++i) {
		int y, x, d;
		cin >> y >> x >> d;
		y--;
		x--;
		d--;
		unit[i] = { y,x,d,i };
		unit_board[y][x].push_back(unit[i]);
	}

	int turn = 1;
	while (1) {

		for (int i = 1; i <= k; ++i) {
			Move(i);
			//PrintV();
			if (Detect) {
				cout << turn << "\n";
				return 0;
			}
		}

		++turn;
		if (turn > 1000) {
			cout << -1 << "\n";
			return 0;
		}
	}
}