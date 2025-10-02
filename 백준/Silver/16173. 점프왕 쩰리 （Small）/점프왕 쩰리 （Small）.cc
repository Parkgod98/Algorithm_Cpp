#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dy[2] = { 0,1 };
int dx[2] = { 1,0 };
int main() {
	int N;
	cin >> N;
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	vector<vector<int>> visited(N, vector<int>(N));
	visited[0][0] = 1;


	bool f = false;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int value = v[it.first][it.second];

		if (it.first == N - 1 && it.second == N - 1)
			f = true;
		for (int i = 0; i < 2; ++i) {
			int ny = it.first + dy[i] * value;
			int nx = it.second + dx[i] * value;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}

	if (f)
		cout << "HaruHaru\n";
	else
		cout << "Hing\n";
}