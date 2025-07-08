#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;

		vector<vector<int>> v(2, vector<int>(n+2));
		vector<vector<int>> dp(2, vector<int>(n + 2));
		for (int i = 0; i < n; ++i)
			cin >> v[0][i];
		for (int i = 0; i < n; ++i)
			cin >> v[1][i];
		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		dp[0][1] = dp[1][0] + v[0][1];
		dp[1][1] = dp[0][0] + v[1][1];

		int mx = max(max(dp[0][0], dp[1][0]), max(dp[0][1], dp[1][1]));
		for (int i = 2; i < n; ++i) {
			dp[0][i] = max(dp[1][i - 1] + v[0][i], dp[1][i - 2] + v[0][i]);
			dp[1][i] = max(dp[0][i - 1] + v[1][i], dp[0][i - 2] + v[1][i]);
			mx = max(mx, max(dp[0][i], dp[1][i]));
		}

		cout << mx << "\n";
	}
}