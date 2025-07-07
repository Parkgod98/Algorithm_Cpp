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
int N;
#define MOD 1000000000;

int main(void) {
	cin >> N;

	vector<vector<int>> dp(N + 1,vector<int>(10));
	for (int i = 1; i <= 9; ++i) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1]%MOD;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1] % MOD;
			}
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%MOD;
		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; ++i) {
		sum = (sum + dp[N][i])%MOD;
	}
	cout << sum << "\n";
}