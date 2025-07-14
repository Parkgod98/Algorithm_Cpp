#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, S, M;
vector<int> v,visited;

int main(){
	cin >> N >> S >> M;

	v = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	vector<vector<int>> dp(N+1,vector<int>(M+1));
	dp[0][S] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= M; ++j) {
			if (dp[i][j]) {
				if (j - v[i] >= 0)
					dp[i+1][j-v[i]] = 1;
				if (j + v[i] <= M)
					dp[i+1][j + v[i]] = 1;
			}
		}
	}

	for (int j = M; j >= 0; --j) {
		if (dp[N][j]) {
			cout << j << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
}