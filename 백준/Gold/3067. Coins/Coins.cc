#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; ++i)
			cin >> v[i];

		int M;
		cin >> M;
		vector<long long> dp(M + 1);
		for (int i = 0; i < N; ++i) {
			dp[v[i]]++;
			for (int j = 0; j <= M; ++j) {
				if (j - v[i] >= 0) {
					dp[j] += dp[j - v[i]];
				}
			}
		}
		cout << dp[M] << "\n";
	}
}