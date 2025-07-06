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
int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> dp(n,1);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int mx = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		mx = max(dp[i], mx);
	}

	cout << mx << "\n";
}