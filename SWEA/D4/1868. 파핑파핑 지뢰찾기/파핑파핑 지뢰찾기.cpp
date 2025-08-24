#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int N;
vector<vector<int>> v;
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

void CountBomb() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			
			if (v[i][j] == 1) {
				int cnt = 0;
				for (int d = 0; d < 8; ++d) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N || v[ny][nx] != -1)
						continue;
					if(v[ny][nx] == -1)
						++cnt;
				}
				v[i][j] = cnt;
			}
		}
	}
}

void PrintV() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

int BFS() {
	
	vector<vector<bool>> visited(N, vector<bool>(N));

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (v[i][j] == 0 && !visited[i][j]) {
				++cnt;
				queue<pair<int, int>> q;
				visited[i][j] = 1;
				q.push({ i,j });

				while (!q.empty()) {
					auto it = q.front();
					q.pop();

					int y = it.first;
					int x = it.second;

					for (int d = 0; d < 8; ++d) {
						int ny = y + dy[d];
						int nx = x + dx[d];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || v[ny][nx] == -1)
							continue;
						if(v[ny][nx] == 0)
							q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (v[i][j] != -1 && !visited[i][j])
				++cnt;
		}
	}

	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		v = vector<vector<int>>(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < N; ++j) {
				if (s[j] == '*')
					v[i][j] = -1;
				else
					v[i][j] = 1;
			}
		}

		CountBomb();
		//PrintV();
		cout << "#" << tc << " " << BFS() << "\n";
	}
}
