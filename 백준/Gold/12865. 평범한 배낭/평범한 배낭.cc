#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int N, K;

int main() {
	cin >> N >> K;
	int res = 0;

	vector<int> dp(K + 1);
	for (int i = 0; i < N; ++i) {
		int w, v;
		cin >> w >> v;
		for (int j = K; j >= w; --j) {
			dp[j] = max(dp[j], dp[j - w] + v);
			res = max(res, dp[j]);
		}
	}

	cout << res << "\n";
}