#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
#define INF 100000000
int main(void) {
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	vector<int> dp(k + 1,INF);
	dp[0] = 0;
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i - v[j] >= 0) {
				dp[i] = min(dp[i - v[j]] + 1, dp[i]);
			}
		}
	}

	if (dp[k] != INF)
		cout << dp[k] << "\n";
	else
		cout << -1 << "\n";
}
