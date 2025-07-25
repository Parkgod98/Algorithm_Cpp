#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<int> dp(N + 2); // 2차원이 될 수도 있어. 아직은 잘 몰라. DP라는것까지만.
	for (int i = 1; i <= N; ++i) {
		int day, money;
		cin >> day >> money;

		if (i + day <= N + 1)
			dp[i + day] = max(dp[i + day], dp[i] + money);
		dp[i + 1] = max(dp[i], dp[i + 1]);
		
	}
	cout << dp[N + 1] << "\n";
}