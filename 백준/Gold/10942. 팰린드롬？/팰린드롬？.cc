#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int N, M;

vector<int> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	v = vector<int>(N+1);
	for (int i = 1; i <= N; ++i) {
		cin >> v[i];
	}
	cin >> M;

	vector<vector<int>> dp(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		dp[i][i] = 1;
		if (i + 1 <= N && v[i] == v[i+1])
			dp[i][i + 1] = 1;
	}

	for (int i = N - 2; i >= 1; --i) {
		for (int j = i + 2; j <= N; ++j) {
			if (v[i] == v[j] && dp[i + 1][j - 1] == 1)
				dp[i][j] = 1;
		}
	}
	for (int i = 0; i < M; ++i) {
		int s, e;
		cin >> s >> e;

		cout << dp[s][e] << "\n";
	}
}
