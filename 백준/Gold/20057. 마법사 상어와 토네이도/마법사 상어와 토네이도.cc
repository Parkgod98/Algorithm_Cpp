#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n;
vector<vector<int>> v;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
int y, x;
int dir = 0;
int res = 0;

double z[9] = { 0.05, 0.1, 0.07, 0.01, 0.1, 0.07, 0.01, 0.02, 0.02 };

void PrintV() {
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

vector<vector<pair<int, int>>> dir_list = {
	{{0,-2},{-1,-1},{-1,0},{-1,1},{1,-1},{1,0},{1,1},{-2,0},{2,0}},
	{{2,0},{1,-1},{0,-1},{-1,-1},{1,1},{0,1},{-1,1},{0,-2},{0,2}},
	{{0,2},{-1,1},{-1,0},{-1,-1},{1,1},{1,0},{1,-1},{-2,0},{2,0}},
	{{-2,0},{-1,-1},{0,-1},{1,-1},{-1,1},{0,1},{1,1},{0,-2},{0,2}}
};

void UpdateDust(int y, int x, int d) {

	int orig = v[y][x];
	vector<pair<int, int>> &dust_map = dir_list[d];
	
	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		auto &it = dust_map[i];
		int ny = y + it.first;
		int nx = x + it.second;

		int nxt = (double)orig * z[i];
		sum += nxt;
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
			res += nxt;
			continue;
		}

		v[ny][nx] += nxt;
	}
	
	int update = orig - sum;

	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (!(ny < 0 || ny >= n || nx < 0 || nx >= n))
		v[ny][nx] += update;
	else
		res += update;
		
}
void Move(int weight) {

	for (int i = 0; i < weight; ++i) {
		y += dy[dir];
		x += dx[dir];

		UpdateDust(y, x, dir);
		v[y][x] = 0;
		//PrintV();

	}
}

int main(void) {
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
	}

	int weight = 1;

	int roop = 2;
	y = n / 2;
	x = n / 2;

	for (int i = 0; i < n; ++i) { // 총 sz번 이동할거고.

		//PrintV();
		for (int j = 0; j < roop; ++j) {
			Move(weight);
			//PrintV();
			dir = (dir + 1) % 4;
		}
		weight++;
		if (weight == n) {
			weight--;
			roop = 1;
		}
	}


	//PrintV();
	cout << res << "\n";
}