#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int N, D;


int main(){
	cin >> N >> D;

	vector<vector<pair<int,int>>> v(D+1);
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (b > D || b - a <= c)
			continue;
		v[b].push_back({ a,c });
	}

	vector<int> dp(D + 1);

	for (int i = 1; i <= D; ++i) {
		dp[i] = dp[i - 1] + 1;
		
		for (int j = 0; j < v[i].size(); ++j) {
			dp[i] = min(dp[i], dp[v[i][j].first] + v[i][j].second);
		}

	}

	cout << dp[D] << "\n";
}