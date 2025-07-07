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

int main(void){
	cin >> N;

	vector<vector<int>> v(N);
	vector<vector<int>> dp(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			int n;
			cin >> n;
			v[i].push_back(n);
			dp[i].push_back(0);
		}
	}

	dp[0][0] = v[0][0];
	int mx = dp[0][0];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			if(j == 0)
				dp[i][j] = dp[i - 1][j] + v[i][j];
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + v[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1] + v[i][j], dp[i - 1][j] + v[i][j]);
			}
			mx = max(mx, dp[i][j]);
		}
	}

	cout << mx << "\n";

}