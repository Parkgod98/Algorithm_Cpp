#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MOD 1000000009

int main(){
	int T;
	cin >> T;

	vector<vector<int>> dp(100001,vector<int>(4));
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int i = 4; i <= 100000; ++i) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;

		int res = 0;
		for (int i = 1; i <= 3; ++i) {
			res += dp[n][i];
			res %= MOD;
		}
		cout << res << "\n";
	}
}