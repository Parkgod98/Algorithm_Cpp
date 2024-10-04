#define _crt_secure_no_warnings
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(null);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

typedef long long ll;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(5001);
	dp[3] = dp[5] = 1;

	for (int i = 6; i <= n; ++i) {
		if (dp[i - 3])
			dp[i] = dp[i - 3] + 1;
		if (dp[i - 5]) {
			if (dp[i] == 0)
				dp[i] = dp[i - 5] + 1;
			else
				dp[i] = min(dp[i], dp[i - 5] + 1);
		}
	}
	if (dp[n] == 0)
		cout << -1;
	else
		cout << dp[n];
}
