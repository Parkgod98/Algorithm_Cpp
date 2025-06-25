#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

long long GetMeter(vector<int> &v, long long cut) {

	long long res = 0;
	for (int i = 0; i < v.size(); ++i) {
		res += v[i] / cut;
	}

	return res;
}

int main() {
	int K, N;
	cin >> K >> N;

	vector<int> v(K);
	for (int i = 0; i < K; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	long long start = 1;
	long long end = v[K-1];

	long long ans = -1;
	while (start <= end) {
		long long mid = (start + end) / 2;

		long long res = GetMeter(v, mid);
		if (res >= N) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ans << "\n";
}  