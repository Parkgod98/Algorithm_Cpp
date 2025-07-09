#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
int main()
{
	cin >> N;

	v.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];

	vector<int> dp(N + 1);
	dp[1] = v[1];
	for (int i =2; i <= N; ++i) {
		dp[i] = v[i];
		for (int j = 1; j < i; ++j) {
			dp[i] = max(dp[i], (dp[i - j] + dp[j]));
		}
	}
	cout << dp[N] << "\n";

}