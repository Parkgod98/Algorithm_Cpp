#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N+1);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];

	vector<int> dp(N+1);
	dp[1] = v[1];
	dp[2] = min(v[2], dp[1]+v[1]);
	
	for (int i = 3; i <= N; ++i) {
		dp[i] = v[i];
		for (int j = 1; j < i; ++j) {
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[N] << "\n";
}