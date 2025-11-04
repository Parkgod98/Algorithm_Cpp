#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<vector<int>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
struct Point {
	int y, x;
};

void PrintV() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}

void CheckAir() {
	queue<Point> q;
	vector<vector<bool>> visited(N, vector<bool>(M));
	q.push({ 0,0 });

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.y;
		int x = it.x;

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || v[ny][nx] == 1)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}

	vector<vector<int>> air_count(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j] == 1) {
				for (int d = 0; d < 4; ++d) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (ny < 0 || ny >= N || nx < 0 || nx >= M || !visited[ny][nx] || v[ny][nx] != 0)
						continue;
					air_count[i][j]++;
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (air_count[i][j] >= 2)
				v[i][j] = 0;
		}
	}
	//PrintV();
}



bool NoCheese() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j] == 1)
				return false;
		}
	}
	return true;
}
int main() {
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
		}
	}

	int t = 0;
	while (1) {
		if (NoCheese()) {
			cout << t << "\n";
			return 0;
		}
		CheckAir();
		++t;
	}
}