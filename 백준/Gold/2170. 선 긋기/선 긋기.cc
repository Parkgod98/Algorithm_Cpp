#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	sort(v.begin(), v.end());

	int start_time = v[0].first;
	int end_time = v[0].second;

	int res = 0;
	for (int i = 1; i < N; ++i) {
		if (v[i].first <= end_time) {
			if (end_time <= v[i].second)
				end_time = v[i].second;
		}
		else {
			res += end_time - start_time;
			start_time = v[i].first;
			end_time = v[i].second;
		}
	}
	res += (end_time - start_time);

	cout << res << "\n";
}