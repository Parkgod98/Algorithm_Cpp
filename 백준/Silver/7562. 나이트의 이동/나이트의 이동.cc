#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> v;
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int l;
int res;
void bfs(int a, int b, int ga, int gb) {

	vector<vector<int>> visited(l, vector<int>(l));
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		int y = it.first;
		int x = it.second;
		if (y == ga && x == gb) {
			res = visited[y][x];
			return;
		}

		for (int i = 0; i < 8; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= l || nx < 0 || nx >= l || visited[ny][nx])
				continue;

			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] + 1;
		}

	}
}
int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> l;
		v = vector<vector<int>>(l, vector<int>(l));
		int a, b, ga, gb;
		cin >> a >> b;
		cin >> ga >> gb;

		bfs(a, b, ga, gb);
		cout << res -1 << "\n";
	}
}