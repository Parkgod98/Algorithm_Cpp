#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, C;

int main() {
	cin >> N >> C;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	int start = 1;
	int end = v[N - 1] - v[0];
	int res = 0;
	while (start <= end) {
		int mid = (start + end) / 2;

		int cur = v[0];
		int cnt = 1;
		for (int i = 1; i < N; ++i) {
			if (v[i] >= cur + mid) {
				cur = v[i];
				++cnt;
			}
		}
		if (cnt >= C) {
			res = max(mid, res);
			start = mid + 1;
		}
		else if (cnt < C) {
			end = mid - 1;
		}
	}
	cout << res << "\n";
}