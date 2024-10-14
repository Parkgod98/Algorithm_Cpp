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

int main(void)
{
	int n;
	cin >> n;

	vector<int> v(n+1);
	for (int i = 0; i < n; ++i)
		cin >> v[i+1];

	vector<int> dp(n + 1,1);
	
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	sort(dp.begin(), dp.end());
	cout << dp[n];
}