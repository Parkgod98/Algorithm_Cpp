#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n;
vector<vector<int>> v;

struct Robot {
	int y, x;
	int lv = 2;
	int exp = 0;
};
Robot r;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int t = 0;
pair<int,int> CanKill() {
	vector<vector<int>> visited(n, vector<int>(n));
	visited[r.y][r.x] = 1;
	queue<pair<int, int>> q;
	q.push({ r.y,r.x });

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.first;
		int x = it.second;
		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || v[ny][nx] > r.lv)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}

	int mn_dist = 999999;
	pair<int, int> res = { -1,-1 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] > 0 && v[i][j] < r.lv && visited[i][j] < mn_dist && visited[i][j] >= 1) {
				mn_dist = (visited[i][j]);
				res.first = i;
				res.second = j;
			}
		}
	}

	if(mn_dist == 999999)
		return { -1,-1 };
	r.y = res.first;
	r.x = res.second;
	r.exp += 1;
	if (r.lv == r.exp) {
		r.lv += 1;
		r.exp = 0;
	}
	v[r.y][r.x] = 0;
	t += (mn_dist - 1);
	return res;
}
int main() {
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 9) {
				r.y = i;
				r.x = j;
				v[i][j] = 0;
			}
		}
	}

	while (1) {
		pair<int, int> kill = CanKill();
		if (kill.first == -1)
			break;
	}
	cout << t << "\n";
}