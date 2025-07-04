#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> dp;
int N, M;
int mx;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	v = vector<vector<int>>(N+1, vector<int>(M+1));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j)
			cin >> v[i][j];
	}
	dp = v;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = v[i][j] + max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
		}
	}
	cout << dp[N][M] << "\n";
}