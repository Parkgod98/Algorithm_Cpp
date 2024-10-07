#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()




int main()
{
	int n;
	cin >> n;
	
	vector<int> dp(12);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	for (int i = 5; i <= 12; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		cout << dp[k] << "\n";
	}
}
