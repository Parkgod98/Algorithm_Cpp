#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M, K;
vector<vector<int>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	cin >> N >> M >> K;
	v = vector<vector<int>>(N, vector<int>(M,0));
	for (int i = 0; i < K; ++i) {
		int a, b, c, d;
		cin >> b >> a >> d >> c;
		for (int i = a; i < c; ++i) 
			for (int j = b; j < d; ++j) 
				v[i][j] = 1;
	}

	vector<vector<bool>> visited(N, vector<bool>(M));
	vector<int> ans;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int cnt = 0;
			if (!visited[i][j] && v[i][j] == 0) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;

				while (!q.empty()) {
					++cnt;
					auto it = q.front();
					q.pop();

					int y = it.first;
					int x = it.second;

					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || v[ny][nx])
							continue;
						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}

				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	cout << "\n";
}