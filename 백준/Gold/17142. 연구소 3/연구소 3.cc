#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 999999999
int N, M;
vector<vector<int>> v;
struct Point {
	int y, x;
};
vector<Point> virus;
vector<Point> choice;
int mn_time = INF;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void PrintV(vector<vector<int>> &v) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (v[i][j] == INF)
				cout << "X" << " ";
			else
				cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}

void BFS() {
	queue<Point> q;
	vector<vector<int>> visited(N, vector<int>(N,INF));
	for (auto &it : choice) {
		q.push(it);
		visited[it.y][it.x] = 1;
	}

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.y;
		int x = it.x;

		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || v[ny][nx] == 1)
				continue;

			if (visited[ny][nx] == INF) {
				q.push({ ny,nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
			else if (visited[ny][nx] > visited[y][x] + 1) {
				q.push({ ny,nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
	}
	//PrintV(visited);

	int mx_time = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j] != INF && v[i][j] == 0) {
				mx_time = max(mx_time, visited[i][j]);
			}
			else if (visited[i][j] == INF && v[i][j] == 0) {
				return;
			}
		}
	}
	mn_time = min(mn_time, mx_time);
}
void Comb(int depth, int idx) {
	if (depth == M) {
		BFS();

		return;
	}

	for (int i = idx; i < virus.size(); ++i) {
		choice.push_back({ virus[i] });
		Comb(depth + 1, i + 1);
		choice.pop_back();
	}
	
}
int main()
{
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	

	Comb(0,0);

	if (mn_time == INF)
		cout << -1 << "\n";
	else if(mn_time == 0)
		cout << 0 << "\n";
	else
		cout << mn_time -1 << "\n";


}