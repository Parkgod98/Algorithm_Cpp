#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int N, M;
vector<vector<int>> v;

int main() {
	cin >> N >> M;
	v = vector<vector<int>>(N+1, vector<int>(M+1));

	int mn = min(N, M);
	for (int i = 1; i <= N; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; ++j) {
			v[i][j] = s[j-1] - '0';
		}
	}

	
	vector<vector<int>> dp(N + 1, vector<int>(M + 1));

	int mx = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (v[i][j] == 1) {
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
			}
			else
				dp[i][j] = 0;
			mx = max(dp[i][j], mx);
		}
	}

	cout << mx * mx << "\n";
}
