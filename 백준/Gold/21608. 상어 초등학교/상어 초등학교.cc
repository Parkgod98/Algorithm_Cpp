#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <list>
using namespace std;
int N;
vector<vector<int>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void PrintV() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << v[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

struct favorite {
	int a, b, c, d;
};

int main() {
	cin >> N;
	v = vector<vector<int>>(N, vector<int>(N));
	int sz = N * N;
	vector<favorite> f(sz+1);

	for (int i = 0; i < sz; ++i) {
		int n;
		int a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		f[n] = { a,b,c,d };
		int mx_fave = 0;
		int cur_empty = 0;
		int by, bx;
		by = bx = -1;
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				if (v[y][x] == 0) {
					if (by == -1) {
						by = y;
						bx = x;
					}
					int fave = 0;
					int empty = 0;
					for (int dir = 0; dir < 4; ++dir) {
						int ny = y + dy[dir];
						int nx = x + dx[dir];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N)
							continue;
						if (v[ny][nx] == a || v[ny][nx] == b || v[ny][nx] == c || v[ny][nx] == d)
							++fave;
						else if (v[ny][nx] == 0)
							++empty;
					}
					if (mx_fave < fave) {
						by = y;
						bx = x;
						mx_fave = fave;
						cur_empty = empty;
					}
					else if (mx_fave == fave && cur_empty < empty) {
						by = y;
						bx = x;
						mx_fave = fave;
						cur_empty = empty;
					}

				}
			}
		}
		v[by][bx] = n;
		//PrintV();
	}

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int cur = v[i][j];
			int cnt = 0;
			for (int dir = 0; dir < 4; ++dir) {
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;
				if (v[ny][nx] == f[cur].a || v[ny][nx] == f[cur].b || v[ny][nx] == f[cur].c || v[ny][nx] == f[cur].d) {
					++cnt;
				}
			}

			switch (cnt)
			{
			case 1:
				sum += 1;
				break;
			case 2:
				sum += 10;
				break;
			case 3:
				sum += 100;
				break;
			case 4:
				sum += 1000;
				break;
			default:
				break;
			}
		}
	}


	cout << sum << "\n";
}