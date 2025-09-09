#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
#define INF 999999999
struct Point {
	int first, second;
};
int N, M;
vector<vector<int>> v;
vector<Point> virus;
vector<Point> ans;
int sz;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int res = INF;
int zero = 0;

int bfs() {
	queue<Point> q;
	vector<vector<int>> visited(N, vector<int>(N));

	for (auto &p : ans) {
		q.push(p);
		visited[p.first][p.second] = 1;
	}

	int mx = 1;
	int cnt2 = 0;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.first;
		int x = it.second;
		if (v[y][x] != 1) {
			++cnt2;
			mx = max(mx, visited[y][x]);
		}
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || v[ny][nx] == 1)
				continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	if (zero == cnt2) 
		return mx - 1;
	return INF;
}
void Comb(int idx, int depth) {
	if (M == depth) {
		res = min(bfs(), res);
		return;
	}

	for (int i = idx; i < sz; ++i) {
		ans.push_back(virus[i]);
		Comb(i+ 1, depth + 1);
		ans.pop_back();
	}
}
int main() {
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				++zero;
				virus.push_back({ i,j });
			}
			else if (v[i][j] == 0)
				++zero;
		}
	}


	sz = virus.size();
	Comb(0, 0);

	if (res == INF)
		cout << -1 << "\n";
	else
		cout << res << "\n";
}
