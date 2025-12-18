#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int N, K;
struct Item {
	int v, c;
};
vector<Item> v;
vector<vector<int>> dp;

int recur(int idx, int volume) {
	if (volume > K)
		return -1000000000;

	if (idx >= N + 1)
		return 0;

	if (dp[idx][volume] != -1)
		return dp[idx][volume];

	int a = recur(idx + 1, volume) + 0;
	int b = recur(idx + 1, volume + v[idx].v) + v[idx].c;

	dp[idx][volume] = max(a, b);

	return dp[idx][volume];
}
int main(){
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;
		v = vector<Item>(N + 1);
		
		for (int i = 1; i <= N; ++i) {
			int vi, c;
			cin >> vi >> c;
			v[i] = { vi,c };
		}

		dp = vector<vector<int>>(N + 1, vector<int>(K + 1, -1));
		int res = recur(1, 0);

		cout << "#" << tc << " " << res << "\n";
	}
}
