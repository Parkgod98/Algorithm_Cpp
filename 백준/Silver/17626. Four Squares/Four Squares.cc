#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp(50001,20);
	for (int i = 1; i < 224; ++i) {
		dp[i*i] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		if (dp[i] != 1) {
			for (int j = 1; j <= sqrt(i); ++j) {
				
				int num = dp[j*j] + dp[i - j * j];
				dp[i] = min(num, dp[i]);
			}
		}
	}

	cout << dp[n] << "\n";
}  