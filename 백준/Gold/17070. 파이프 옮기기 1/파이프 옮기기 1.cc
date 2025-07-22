#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N;
vector<vector<int>> v;

int main() {
	cin >> N;
	v = vector<vector<int>>(N + 1, vector<int>(N + 1));
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(3)));
	dp[1][2][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			cin >> v[i][j];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 2; j <= N; ++j) {
			if (i == 1 && j == 2)
				continue;
			if (v[i][j] == 0) {
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
				dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j][1];
				if (v[i][j-1] != 1 && v[i-1][j] != 1)
					dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2] + dp[i - 1][j - 1][0];
			}
			
		}
	}
	int sum = 0;
	for (int i = 0; i < 3; ++i)
		sum += dp[N][N][i];

	cout << sum << "\n";
}