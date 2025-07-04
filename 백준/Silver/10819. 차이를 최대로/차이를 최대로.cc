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

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int mx = 0;
	do {
		int sum = 0;
		for (int i = 0; i < N-1; ++i) {
			sum += abs(v[i] - v[i + 1]);
		}
		mx = max(mx, sum);

	} while (next_permutation(v.begin(), v.end()));

	cout << mx << "\n";
}