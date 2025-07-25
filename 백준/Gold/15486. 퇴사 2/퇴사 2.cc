#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int N;

struct Cons {
	int day, money;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	vector<Cons> v(N + 1);
	for (int i = 1; i <= N; ++i) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	vector<int> dp(N + 2); // 2차원이 될 수도 있어. 아직은 잘 몰라. DP라는것까지만.
	int mx = 0;
	for (int i = 1; i <= N; ++i) {
		dp[i] = max(dp[i - 1], dp[i]);
		if (i + v[i].day <= N+1) {
			dp[i + v[i].day] = max(dp[i + v[i].day], dp[i] + v[i].money);
			mx = max(mx, dp[i+v[i].day]);

		}
		mx = max(mx, dp[i]);
	}

	cout << mx << "\n";

}