#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int N, K;
struct Item {
	int v, c;
};
vector<Item> v;
int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;
		v = vector<Item>(N + 1);
		for (int i = 1; i <= N; ++i) {
			int vi, c;
			cin >> vi >> c;
			v[i] = { vi,c };
		}
		vector<vector<int>> dp(N + 1, vector<int>(K + 1));

		int res = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= K; ++j) {
				if (j >= v[i].v) {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].v] + v[i].c);
				}
				else
					dp[i][j] = dp[i - 1][j];
				res = max(dp[i][j], res);
			}
		}

		cout << "#" << tc << " " << res << "\n";
	}
}
