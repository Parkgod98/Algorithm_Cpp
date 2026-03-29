#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int N;
vector<vector<char>> v;
vector<vector<int>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main(){
	cin >> N;
	v = vector<vector<char>>(N, vector<char>(N));
	visited = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j)
			v[i][j] = s[j];
	}

	int res1, res2;
	res1 = res2 = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				int cur = v[i][j];
				++res1;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;

				while (!q.empty()) {
					auto it = q.front();
					q.pop();

					int y = it.first;
					int x = it.second;
					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || v[ny][nx] != cur)
							continue;

						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}
			}
		}
	}

	visited = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				int cur = v[i][j];
				++res2;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;

				while (!q.empty()) {
					auto it = q.front();
					q.pop();

					int y = it.first;
					int x = it.second;
					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
							continue;
						if (cur == 'R' && v[ny][nx] == 'B')
							continue;
						if (cur == 'G' && v[ny][nx] == 'B')
							continue;
						if (cur == 'B' && v[ny][nx] != 'B')
							continue;

						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}
			}
		}
	}

	cout << res1 << " " << res2 << "\n";
}