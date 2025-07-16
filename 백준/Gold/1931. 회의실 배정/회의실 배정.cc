#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int N;

int main() {
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		v[i] = { b,a };
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	int time = 0;
	for (int i = 0; i < N; ++i) {
		if (time <= v[i].second) {
			++cnt;
			time = v[i].first;
		}
	}

	cout << cnt << "\n";
}