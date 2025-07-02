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

int main() {
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	int mx = 1;
	vector<int> dp(N,1);
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[j] > v[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		mx = max(dp[i], mx);
	}

	cout << mx << "\n";
}