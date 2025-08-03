#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
using namespace std;
int N;

int main() {
	cin >> N;
	vector<int> v(N),dp(N,1),dp2(N,1);

	for (int i = 0; i < N; ++i)
		cin >> v[i];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[j] < v[i])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	for (int i = N-1; i >=0; --i) {
		for (int j = N-1; j >i; --j) {
			if (v[i] > v[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}

	int mx = -1;
	for (int i = 0; i < N; ++i) {
		if (mx < dp[i] + dp2[i]) {
			mx = dp[i] + dp2[i];
		}
	}

	int res = mx - 1;
	cout << res << "\n";
}