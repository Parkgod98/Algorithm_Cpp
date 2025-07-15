#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int N, M;
vector<vector<int>> v,visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	v = visited = vector<vector<int>>(N, vector<int>(M));

	int total = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
			else if (v[i][j] == 0)
				++total;
		}
	}

	int cnt = 1;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.first;
		int x = it.second;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || v[ny][nx] != 0)
				continue;

			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] + 1;
			cnt = max(cnt, visited[ny][nx]);
			total--;
		}
	}

	if (total != 0) {
		cout << -1 << "\n";
	}
	else
		cout << cnt - 1 << '\n';
}