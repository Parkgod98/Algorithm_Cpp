#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, M;
void PrintV(vector<vector<int>> &v) {
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	string a, b;
	cin >> a >> b;

	N = a.size();
	M = b.size();
	vector<vector<int>> dp(1002, vector<int>(1002));

	int mx = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i-1][j]);
			}
			mx = max(mx, dp[i][j]);
		}
	}
	cout << mx << "\n";
}
