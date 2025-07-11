#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
long long cnt = 0;
vector<vector<int>> v;
vector<vector<long long>> dp;

int main(){
	cin >> N;

	v = vector<vector<int>>(N, vector<int>(N));
	dp = vector<vector<long long>>(N, vector<long long>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}

	dp[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (v[i][j] == 0)
				continue;
			if (dp[i][j]) {
				if (i + v[i][j] < N)
					dp[i + v[i][j]][j] += dp[i][j];
				if (j + v[i][j] < N)
					dp[i][j + v[i][j]] += dp[i][j];
			}
		}
	}

	cout << dp[N-1][N-1] << "\n";
}