#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void bfs(vector<vector<int>>& mp, vector<vector<int>>& visited, int y, int x) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = visited[y][x];
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		cnt++;
		y = p.first;
		x = p.second;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= mp.size() || nx >= mp[0].size() || visited[ny][nx] || mp[ny][nx] == 0)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] +1;
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m,0));
	vector<vector<int>> visited(n, vector<int>(m, false));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); ++j)
			v[i][j] = s[j] - '0';
	}
	bfs(v,visited,0, 0);
	cout << visited[n - 1][m - 1] +1 << "\n";
}