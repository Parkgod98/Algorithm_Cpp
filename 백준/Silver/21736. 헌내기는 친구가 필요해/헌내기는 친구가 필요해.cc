#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N,M;
vector<vector<char>> v;
vector<vector<bool>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int main() {
	cin >> N >> M;
	v = vector<vector<char>>(N, vector<char>(M));
	visited = vector<vector<bool>>(N, vector<bool>(M));
	pair<int, int> start;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 'I') {
				start = { i,j };
				visited[i][j] = 1;
			}
		}

	queue<pair<int, int>> q;
	q.push(start);

	int cnt = 0;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		int y = it.first;
		int x = it.second;
		if (v[y][x] == 'P')
			++cnt;
		
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
				continue;
			if (v[ny][nx] == 'X')
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}

	if (cnt == 0)
		cout << "TT" << "\n";
	else
		cout << cnt << "\n";
}