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
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i) {
		int s, t;
		cin >> s >> t;
		v[i] = { t,s };
	}

	sort(v.begin(), v.end());
	int cnt = 0;
	int end_time = 0;
	for (int i = 0; i < N; ++i) {
		int cur = v[i].second;
		if (cur >= end_time) {
			++cnt;
			end_time = v[i].first;
		}
	}

	cout << cnt << "\n";
}