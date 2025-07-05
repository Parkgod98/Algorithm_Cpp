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
#define MOD 1000000009;
int main() {
	int T;
	cin >> T;

	vector<long long> dp(1000001);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	dp[5] = 13;
	for (int i = 6; i <= 1000000; ++i) {
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1])%MOD;
	}

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;

		cout << dp[n] << "\n";
	}
}