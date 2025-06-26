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

int main() {
	int N;
	cin >> N;

	double sum = 0;
	vector<int> v(N);
	int arr[8001] = { 0 };
	int mx, mn;
	mx = -4001;
	mn = 4001;

	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		mx = max(mx, n);
		mn = min(mn, n);

		v[i] = n;

		sum += n;

		arr[n + 4000]++;
	}

	int avg = round(sum / N);

	sort(v.begin(), v.end());
	int mid = v[N / 2];

	int many_n = -1;
	int res = -1;
	for (int i = 0; i <= 8000; ++i) {
		if (arr[i] > many_n) {
			many_n = arr[i];
			res = i - 4000;
		}
	}
	for (int i = res + 4001; i <= 8000; ++i) {
		if (arr[i] == many_n) {
			res = i - 4000;
			break;
		}
	}

	int range = mx - mn;

	cout << avg << "\n" << mid << "\n" << res << "\n" << range << "\n";

}  