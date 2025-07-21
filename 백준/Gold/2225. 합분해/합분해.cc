#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N, K;
#define MOD 1000000000

int main() {
	cin >> N >> K;

	vector<vector<int>> dp(N+1,vector<int>(K+1,1));
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 2; j <= K; ++j) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << dp[N][K];
}
