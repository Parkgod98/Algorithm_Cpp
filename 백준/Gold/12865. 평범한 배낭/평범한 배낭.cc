#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int N, K;
struct Item {
	int W, V;
};

vector<Item> v;
int main() {
	cin >> N >> K;

	v = vector<Item>(N+1);
	for (int i = 1; i <= N; ++i) {
		int w, k;
		cin >> w >> k;
		v[i] = { w,k };
	}

	vector<vector<int>> dp(N+1, vector<int>(K + 1));

	int res = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (j >= v[i].W) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].W] + v[i].V);
			}
			else
				dp[i][j] = dp[i - 1][j];
			res = max(dp[i][j], res);
		}
	}
	cout << res << "\n";
}