#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C, R, K;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	cin >> C >> R >> K;
	if (K > C*R) {
		cout << 0 << "\n";
		return 0;
	}

	int r, c,cur;
	r = c = cur = 1;
	int dir = 1;
	vector<vector<bool>> v(C + 1, vector<bool>(R + 1, false));
	v[r][c] = 1;
	while (1) {
		if (cur == K) {
			cout << r << " " << c << "\n";
			return 0;
		}
		int ny = r + dy[dir];
		int nx = c + dx[dir];
		if (ny < 1 || ny > C || nx < 1 || nx > R || v[ny][nx]) {
			dir = (dir + 1) % 4;
			continue;
		}
		else {
			r = ny;
			c = nx;
			cur++;
			v[ny][nx] = 1;
		}
	}
}