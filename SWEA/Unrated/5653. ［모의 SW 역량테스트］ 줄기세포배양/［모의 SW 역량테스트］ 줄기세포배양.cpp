#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <list>
using namespace std;
vector<pair<int, int>> dp[400][11];
int board[700][700];
int active[12];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int N, M, K;

void Init() {
	for (int i = 0; i < 12; ++i)
		active[i] = 0;
	for (int i = 0; i < 600; ++i) {
		for (int j = 0; j < 600; ++j) {
			if (i < 400 && j < 11)
				dp[i][j].clear();
			board[i][j] = 0;
		}
	}
}


int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> K;
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> board[i + 320][j + 320];
				if (board[i + 320][j + 320] != 0) {
					dp[board[i + 320][j + 320]][board[i + 320][j + 320]].push_back({ i + 320,j + 320 });
					++cnt;
				}
			}
		}

		for (int i = 1; i <= K; ++i) {
			for (int j = 10; j >= 1; --j) {
				for (int k = 0; k < dp[i - 1][j].size(); ++k) {
					int py = dp[i - 1][j][k].first;
					int px = dp[i - 1][j][k].second;
					for (int d = 0; d < 4; ++d) {
						int ny = py + dy[d];
						int nx = px + dx[d];
						if (board[ny][nx] == 0) {
							board[ny][nx] = j;
							++cnt;
							dp[i + j][j].push_back({ ny,nx });
						}
					}
				}
			}
			cnt -= active[1];
			for (int j = 1; j <= 10; ++j)
				active[j] = active[j + 1];
			for (int j = 1; j <= 10; ++j)
				active[j] += dp[i][j].size();

		}
		cout << "#" << tc << " " << cnt << "\n";
		Init();
	}
}