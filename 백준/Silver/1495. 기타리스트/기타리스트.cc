#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, S, M;
vector<int> v,visited;
int mx = 0;

void PrintV(vector<vector<int>> &v) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

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

	int mx = -1;
	for (int j = 0; j <= M; ++j) {
		if (dp[N][j]) {
			mx = j;
		}
	}

	cout << mx << "\n";
}