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
typedef long long ll;
int N, M;
int mx;
ll sum;
int main() {
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		mx = max(mx, v[i]);
		sum += v[i];
	}

	cin >> M;

	if (sum <= M)
		cout << mx << "\n";
	else {
		ll ans = 0;
		ll gap = sum - M;
		ll start = mx - gap;
		ll end = mx;

		while (start <= end) {
			ll mid = (start + end) / 2;
			
			ll sum2 = 0;
			for (int i = 0; i < N; ++i) {
				if (v[i] > mid) {
					sum2 += mid;
				}
				else
					sum2 += v[i];
			}
			if (sum2 <= M) {
				ans = mid;
				start = mid + 1;
			}
			else { // sum2 > M
				end = mid - 1;
			}
		}

		cout << ans << "\n";
	}

}