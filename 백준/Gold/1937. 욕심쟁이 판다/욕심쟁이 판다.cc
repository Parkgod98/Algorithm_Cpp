#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
vector<vector<int>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<vector<int>> dp;

int mx = 0;

int DFS(int y, int x, int depth) {

	int cur = v[y][x];
	int res = depth;

	if (dp[y][x] != -1)
		return depth + dp[y][x];

	for (int d = 0; d < 4; ++d) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N || v[ny][nx] <= cur)
			continue;

		res = max(res,DFS(ny, nx, depth + 1));
		dp[y][x] = max(res-depth, dp[y][x]);
	}

	return res;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	v = vector<vector<int>>(N, vector<int>(N));
	dp = vector<vector<int>>(N, vector<int>(N, -1));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if(dp[i][j] == -1)
				dp[i][j] = DFS(i, j, 0);
			mx = max(dp[i][j], mx);
		}
	}

	cout << mx + 1<< "\n";
}