#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0};
int dx[4] = { 0,1,0,-1};
int r, c;

int bfs(vector<vector<int>> &v) {
	vector<vector<vector<int>>> visited(r, vector<vector<int>>(c, vector<int>(2, 0)));

	queue<vector<int>> q;
	q.push({ 0,0,0});
	visited[0][0][0] = 1;

	while (!q.empty()) {
		vector<int> it = q.front();
		q.pop();

		int y = it[0];
		int x = it[1];
		int IsBreak = it[2];
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;
			if (v[ny][nx] == 0 && !visited[ny][nx][IsBreak]) {
				q.push({ ny,nx,IsBreak });
				visited[ny][nx][IsBreak] = visited[y][x][IsBreak] + 1;
			}
			else if (v[ny][nx] == 1 && IsBreak == 0 && !visited[ny][nx][IsBreak]) {
				q.push({ ny,nx,1 });
				visited[ny][nx][1] = visited[y][x][IsBreak] + 1;
			}
		}
	}
	if (visited[r - 1][c - 1][0] || visited[r - 1][c - 1][1]) {
		if (visited[r - 1][c - 1][0] != 0 && visited[r - 1][c - 1][1])
			return min(visited[r - 1][c - 1][0], visited[r - 1][c - 1][1]);
		return max(visited[r - 1][c - 1][0], visited[r - 1][c - 1][1]);
	}
	return -1;
}

int main()
{
	cin >> r >> c;
	vector<vector<int>> v(r, vector<int>(c, 0));

	vector<pair<int, int>> block;
	for (int i = 0; i < r; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < c; ++j) {
			v[i][j] = s[j] -'0';
			if (v[i][j] == 1)
				block.push_back({ i,j });
		}
	}


	cout << bfs(v) << "\n";

}