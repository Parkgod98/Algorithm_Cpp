#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#define EPSILON 0.0000000001
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;
	
	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	double start = v[0]-0.5;

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (v[i] + 0.5 - start > EPSILON) {
			++cnt;
			start = v[i] - 0.5 + L;
		}
	}
	cout << cnt << "\n";
}  