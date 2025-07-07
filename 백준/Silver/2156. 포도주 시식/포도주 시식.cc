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

int main(void) {
	cin >> N;

	vector<int> v(10001), dp(10001);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	dp[0] = v[0];
	dp[1] = v[0] + v[1];
	dp[2] = max(dp[0] + v[2], max(v[1] + v[2],v[0]+v[1]));

	int mx = max(dp[0], max(dp[1], dp[2]));
	for (int i = 3; i < N; ++i) {
		dp[i] = max(dp[i - 3] + v[i - 1] + v[i], max(dp[i - 2] + v[i],dp[i-1]));
		mx = max(dp[i], mx);
	}

	cout << mx << "\n";
}