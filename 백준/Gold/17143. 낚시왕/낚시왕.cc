#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n, m, k;
vector<vector<int>> v;
struct Micro {
	int y, x;
	int velocity;
	int dir;
	int sz;
	bool die = false;
};
vector<Micro> micro;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int sum = 0;

void PrintV() {
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

void Erase() { // O(10000)

	for (int i = 1; i <= k; ++i) {
		int y = micro[i].y;
		int x = micro[i].x;
		v[y][x] = 0;
	}
}
void Mark() { // O(10000)

	for (int i = 1; i <= k; ++i) {
		if (micro[i].die)
			continue;
		int y = micro[i].y;
		int x = micro[i].x;
		v[y][x] = i;
	}
}

void Go(int col) {
	for (int i = 0; i < n; ++i) {
		int idx = v[i][col];
		if (idx != 0) {
			micro[idx].die = true;
			sum += micro[idx].sz;
			v[i][col] = 0;
			//cout << sum << "\n";
			return;
		}
	}
}

void Move() {

	for (int i = 1; i <= k; ++i) {
		if (micro[i].die)
			continue;

		int y = micro[i].y;
		int x = micro[i].x;
		int dir = micro[i].dir;
		y += (micro[i].velocity * (dy[dir]));
		x += (micro[i].velocity * (dx[dir]));

		int ny = -1;
		int nx = -1;
		if (y < 0 || y >= n || x < 0 || x >= m) {
			int offset = 0;
			if (y < 0) {
				offset = (-y);
				int mok = offset / (n-1);
				if (mok % 2 == 0) {
					ny = offset % (n - 1);
					nx = x;
					//v[offset%(n-1)][x] = i;
					micro[i].y = offset % (n - 1);
					if (micro[i].dir == 0)
						micro[i].dir = 1;
					else
						micro[i].dir = 0;
				}
				else {
					//v[n - 1 - (offset % (n - 1))][x] = i;
					ny = n - 1 - (offset % (n - 1));
					nx = x;
					micro[i].y = n - 1 - (offset % (n - 1));
				}
			}
			else if (y >= n) {
				offset = (y - n + 1);
				int mok = offset / (n - 1);
				if (mok % 2 == 0) {
					//v[n - 1 - (offset % (n - 1))][x] = i;
					ny = n - 1 - (offset % (n - 1));
					nx = x;
					micro[i].y = n - 1 - (offset % (n - 1));
					if (micro[i].dir == 0)
						micro[i].dir = 1;
					else
						micro[i].dir = 0;
				}
				else {
					//v[offset % (n - 1)][x] = i;
					ny = offset % (n - 1);
					nx = x;
					micro[i].y = offset % (n - 1);
				}
			}
			else if (x < 0) {
				offset = (-x);
				int mok = offset / (m - 1);
				if (mok % 2 == 0) {
					//v[y][offset % (m - 1)] = i;
					ny = y;
					nx = offset % (m - 1);
					micro[i].x = offset % (m - 1);
					if (micro[i].dir == 2)
						micro[i].dir = 3;
					else
						micro[i].dir = 2;
				}
				else {
					//v[y][m - 1 - (offset % (m - 1))] = i;
					ny = y;
					nx = m - 1 - (offset % (m - 1));
					micro[i].x = m - 1 - (offset % (m - 1));
				}
			}
			else if (x >= m) {
				offset = (x - m + 1);
				int mok = offset / (m - 1);
				if (mok % 2 == 0) {
					//v[y][m - 1 - (offset % (m - 1))] = i;
					ny = y;
					nx = m - 1 - (offset % (m - 1));
					micro[i].x = m - 1 - (offset % (m - 1));
					if (micro[i].dir == 2)
						micro[i].dir = 3;
					else
						micro[i].dir = 2;
				}
				else {
					//v[y][offset % (m - 1)] = i;
					ny = y;
					nx = offset % (m - 1);
					micro[i].x = offset % (m - 1);
				}
			}
		}
		else {
			ny = y;
			nx = x;
			micro[i].y = ny;
			micro[i].x = nx;
		}
		if (v[ny][nx] != 0) {
			if (micro[i].sz > micro[v[ny][nx]].sz) {
				micro[v[ny][nx]].die = true;
				v[ny][nx] = i;
			}
			else {
				micro[i].die = true;
			}
		}
		else
			v[ny][nx] = i;
	}
}

int main() {
	cin >> n >> m >> k;
	v = vector<vector<int>>(n, vector<int>(m));
	micro = vector<Micro>(k+1);
	for (int i = 0; i < k; ++i) {
		int y, x, s, d, b;
		cin >> y >> x >> s >> d >> b;
		micro[i+1] = { y - 1,x - 1,s,d - 1,b };
	}


	//PrintV();

	for (int c = 0; c < m; ++c) {
		Mark();
		//PrintV();

		Go(c);
		//PrintV();


		Erase(); //  맵에 적힌거 다지우고
		//PrintV();


		Move();
		//PrintV();
		Erase();
	}

	cout << sum << "\n";
}