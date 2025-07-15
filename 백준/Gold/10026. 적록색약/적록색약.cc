#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n;
void bfs(vector<vector<char>>& v, vector<vector<bool>> &visited, int y, int x, int mode) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		y = it.first;
		x = it.second;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || v[ny][nx] != v[y][x])
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = true;
		}
	}
}

int main()
{
	cin >> n;
	
	vector<vector<char>> v(n, vector<char>(n));

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); ++j) {
			v[i][j] = s[j];
		}
	}

	for (int i = 0; i < 2; ++i) {
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		int cnt = 0;
		if (i == 1) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					if (v[j][k] == 'G')
						v[j][k] = 'R';
				}
			}
		}
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				if (!visited[y][x]) {
					bfs(v, visited,y,x,i);
					++cnt;
				}
			}
		}
		cout << cnt << "\n";
	}
	

}