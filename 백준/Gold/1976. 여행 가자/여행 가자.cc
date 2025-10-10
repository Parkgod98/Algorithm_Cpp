#include <iostream>
#include <vector>
using namespace std;
int N, M;

vector<vector<int>> v,dp;
vector<int> tar;

int main() {
	cin >> N >> M;
	v = vector<vector<int>>(N,vector<int>(N));
	tar = vector<int>(M);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
		}
	}
	dp = v;

	for (int i = 0; i < M; ++i) {
		int k;
		cin >> k;
		tar[i] = k - 1;
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j)
					dp[i][j] = dp[j][i] = 1;
				if (dp[i][k] && dp[k][j]) {
					dp[i][j] = dp[j][i] = 1;
				}
			}
		}
	}

	bool IsOkay = true;

	for (int i = 0; i < M-1; ++i) {
		if (!dp[tar[i]][tar[i + 1]]) {
			IsOkay = false;
			break;
		}
	}
	if (IsOkay)
		cout << "YES\n";
	else
		cout << "NO\n";
}