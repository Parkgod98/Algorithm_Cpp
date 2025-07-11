#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
#define MOD 9901
int main(){
	cin >> N;

	vector<vector<int>> dp(N+1, vector<int>(3));
	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= N; ++i) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
	}

	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		sum += dp[N][i];
		sum %= MOD;
	}

	cout << sum << "\n";
}