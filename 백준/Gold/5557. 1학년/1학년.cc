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
vector<int> v;

int main() {
	cin >> N;
	v = vector<int>(N+1);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];

	vector<vector<long long>> dp(N + 1, vector<long long>(21));
	dp[1][v[1]] = 1;

	for (int i = 2; i < N; ++i) {
		for (int j = 0; j <= 20; ++j) {
			if (dp[i - 1][j]) {
				if (j + v[i] <= 20)
					dp[i][j + v[i]] += dp[i - 1][j];
				if (j - v[i] >= 0)
					dp[i][j - v[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[N - 1][v[N]] << "\n";
}