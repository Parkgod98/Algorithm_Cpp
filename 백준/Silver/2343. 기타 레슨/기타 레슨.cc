#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int N, M;

int main(){
	cin >> N >> M;
	vector<int> v(N);

	int l, r;
	l = r = 0;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		r += v[i];
		l = max(v[i], l);
	}

	while (l <= r) {
		int mid = (l + r) / 2;

		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			if (sum + v[i] > mid) {
				sum = 0;
				++cnt;
			}
			sum += v[i];
		}
		if (sum != 0)
			++cnt;

		if (cnt > M) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << l << "\n";
}