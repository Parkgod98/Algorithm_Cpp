#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	int c, r;
	cin >> c >> r;

	queue<pair<int, int>> q;
	vector<vector<int>> v(r, vector<int>(c, 0));
	vector<vector<int>> visited(r, vector<int>(c, 0));
	int total_tomato = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
			else if (v[i][j] == 0)
				total_tomato++;
		}
	}

	
	int cnt = 1;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = it.first + dy[i];
			int nx = it.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || v[ny][nx] != 0)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[it.first][it.second] + 1;
			cnt = max(cnt, visited[ny][nx]);
			total_tomato--;
		}
	}
	if (total_tomato != 0)
		cout << -1 << "\n";
	else
		cout << cnt -1 << "\n";
}