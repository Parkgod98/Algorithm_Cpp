#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;
vector<vector<int>> v;

int main() {
	cin >> N >> M;

	v = vector<vector<int>>(M, vector<int>(N));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}


	queue<pair<int, int>> q;
	vector<vector<bool>> visited(M, vector<bool>(N));
	q.push({ 0,0 });
	visited[0][0] = false;
	string res = "No";
	while (!q.empty()) {
		auto it = q.front();
		int y = it.first;
		int x = it.second;
		q.pop();
		if (y == M - 1 && x == N - 1) {
			res = "Yes";
			break;
		}

		if (y + 1 < M && !visited[y+1][x] && v[y + 1][x] == 1) {
			q.push({ y + 1,x });
			visited[y + 1][x] = 1;
		}
		if (x + 1 < N && !visited[y][x+1] && v[y][x + 1] == 1) {
			q.push({ y,x + 1 });
			visited[y][x + 1] = 1;
		}
	}

	cout << res << "\n";
}