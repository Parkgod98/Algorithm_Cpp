#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
#define INF 999999999
int main(){
	cin >> N;


	vector<int> dp(N + 1,INF);
	dp[1] = 0;
	for (int i = 1; i <= N; ++i) {
		if (i + 1 <= N) {
			dp[i + 1] = min(dp[i] + 1, dp[i+1]);
		}
		if (i * 2 <= N) {
			dp[i * 2] = min(dp[i] + 1, dp[i * 2]);
		}
		if (i * 3 <= N) {
			dp[i * 3] = min(dp[i] + 1, dp[i * 3]);
		}
	}
	cout << dp[N] << "\n";
	int i = N;
	while (1) {
		cout << i << " ";
		if (i == 1)
			break;
		if (dp[i] == dp[i - 1] + 1) {
			i = i - 1;
		}
		else if (i%2 == 0 && dp[i] == dp[i / 2] + 1)
			i = i / 2;
		else if (i%3 == 0 && dp[i] == dp[i / 3] + 1)
			i /= 3;
	}
	cout << "\n";
}