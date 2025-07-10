#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
pair<int, int> s;
vector<vector<int>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 2)
				s = { i,j };
		}
	}

	vector<vector<int>> visited(N, vector<int>(M));

	queue<pair<int, int>> q;
	q.push(s);
	visited[s.first][s.second] = 1;

	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		
		int y = it.first;
		int x = it.second;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || v[ny][nx] == 0)
				continue;

			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (visited[i][j] == 0 && v[i][j] == 0)
				cout << visited[i][j] << " ";
			else if (visited[i][j] == 0 && v[i][j] == 1)
				cout << -1 << " ";
			else
				cout << visited[i][j] - 1 << " ";
		}
		cout << "\n";
	}

}