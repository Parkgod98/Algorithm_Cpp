#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int N, D;
struct road {
	int s, e;
	int cost;
};

bool compare(road &a, road &b) {
	if (a.s != b.s) {
		return a.s < b.s;
	}
	else {
		if (a.e != b.e) {
			return a.e < b.e;
		}
		else {
			return a.cost < b.cost;
		}
	}
}
int main(){
	cin >> N >> D;

	vector<road> v(N);
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v[i] = { a,b,c };
	}
	sort(v.begin(), v.end(), compare);

	vector<int> dp(D + 1);
	for (int i = 0; i <= D; ++i)
		dp[i] = i;

	for (int i = 0; i < N; ++i) {
		int start = v[i].s;
		int end = v[i].e;
		int cost = v[i].cost;

		if (end <= D) {
			if (dp[start] + cost < dp[end]) {
				dp[end] = dp[start] + cost;
				for (int i = end; i < D; ++i) {
					dp[i + 1] = min(dp[i+1],dp[i] + 1);
				}
			}
		}

	}

	cout << dp[D] << "\n";
}