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
int N;
vector<vector<int>> cost;
int mn = 0;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	cost = vector<vector<int>>(N, vector<int>(3));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> cost[i][j];
			mn += cost[i][j];
		}
	}
	vector<vector<int>> dp(N, vector<int>(3,mn));
	for (int i = 0; i < 3; ++i) {
		dp[0][i] = cost[0][i];
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (j != k) {
					dp[i][j] = min(dp[i - 1][k] + cost[i][j], dp[i][j]);
				}
			}
		}
	}
	for (int i = 0; i < 3; ++i)
		mn = min(dp[N - 1][i], mn);
	cout << mn << "\n";
}