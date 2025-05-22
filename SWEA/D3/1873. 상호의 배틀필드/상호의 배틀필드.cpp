#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int h, w;
		cin >> h >> w;
		vector<vector<char>> v(h, vector<char>(w));

		int dir = 0;
		int y, x;
		for (int i = 0; i < h; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < s.size(); ++j) {
				v[i][j] = s[j];
				if (s[j] == '<') {
					dir = 3;
					y = i;
					x = j;
				}
				else if (s[j] == '^') {
					dir = 0;
					y = i;
					x = j;
				}
				else if (s[j] == 'v') {
					dir = 2;
					y = i;
					x = j;
				}
				else if (s[j] == '>') {
					dir = 1;
					y = i;
					x = j;
				}
			}
		}

		int com;
		cin >> com;
		string scom;
		cin >> scom;
		for (int i = 0; i < com; ++i) {
			if (scom[i] == 'U') {
				dir = 0;
				v[y][x] = '^';
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w || v[ny][nx] != '.')
					continue;
				v[y][x] = '.';
				y = ny;
				x = nx;
				v[ny][nx] = '^';
			}
			else if (scom[i] == 'D') {
				dir = 2;
				v[y][x] = 'v';
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w || v[ny][nx] != '.')
					continue;
				v[y][x] = '.';
				y = ny;
				x = nx;
				v[ny][nx] = 'v';

			}
			else if (scom[i] == 'L') {
				dir = 3;
				v[y][x] = '<';
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w || v[ny][nx] != '.')
					continue;
				v[y][x] = '.';
				y = ny;
				x = nx;
				v[ny][nx] = '<';
			}
			else if (scom[i] == 'R') {
				dir = 1;
				v[y][x] = '>';
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w || v[ny][nx] != '.')
					continue;
				v[y][x] = '.';
				y = ny;
				x = nx;
				v[ny][nx] = '>';

			}
			else if (scom[i] == 'S') {
				int sy, sx;
				sy = y;
				sx = x;
				while (1) {
					int ny = sy + dy[dir];
					int nx = sx + dx[dir];
					if (ny < 0 || nx < 0 || ny >= h || nx >= w)
						break;
					if (v[ny][nx] == '*') {
						v[ny][nx] = '.';
						break;
					}
					else if (v[ny][nx] == '#')
						break;
					sy = ny;
					sx = nx;
				}
			}
		}
		cout << "#" << tc << " ";
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cout << v[i][j];
			}
			cout << "\n";
		}
	}
}