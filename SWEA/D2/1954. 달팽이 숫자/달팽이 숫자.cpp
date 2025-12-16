#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int T;
int N;
vector<vector<int>> v;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int main(){
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		v = vector<vector<int>>(N, vector<int>(N));

		int sz = N * N;
		int start = 1;

		int y, x;
		y = x = 0;
		int dir = 0;
		while (start <= sz) {
			v[y][x] = start;
			++start;
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || v[ny][nx] != 0)
				dir = (dir + 1) % 4;

			y += dy[dir];
			x += dx[dir];
		}

		cout << "#" << tc << "\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
	}
}
