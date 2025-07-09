#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 10007
int main()
{
	int N;
	cin >> N;

	vector<vector<int>> dp(N + 1, vector<int>(10));
	for (int i = 0; i <= 9; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= N; ++i) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= 9; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	int res = 0;
	for (int i = 0; i <= 9; ++i) {
		res += dp[N][i];
		res %= MOD;
	}

	cout << res << "\n";
}