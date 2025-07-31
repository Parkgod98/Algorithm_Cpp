#include <iostream>
#include <vector>
using namespace std;
int n,k;

int main() {
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	vector<int> dp(k + 1);

	for (int i = 0; i < n; ++i) {
		dp[v[i]]++;
		for (int m = 0; m <= k; ++m) {
			if (m - v[i] >= 0)
				dp[m] += dp[m - v[i]];
		}
	}

	cout << dp[k] << "\n";
}