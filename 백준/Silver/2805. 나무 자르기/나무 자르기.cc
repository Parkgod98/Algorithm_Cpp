#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

long long GetTree(vector<int> &v, int cut) {
	long long res = 0;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] > cut)
			res += (v[i] - cut);
	}

	return res;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	long long sum = 0;

	sort(v.begin(), v.end(), greater<int>());

	int end = v[0];
	int start = 0;

	int answer = 0;
	while (start <= end) {
		int mid = (start + end) / 2;

		long long cur = GetTree(v, mid);
		if (cur < M) {
			end = mid-1;
		}
		else {
			answer = mid;
			start = mid + 1;
		}
	}

	cout << answer << "\n";
}  