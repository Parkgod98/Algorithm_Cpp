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
int mx = -2000000000;
int mn = 2000000000;
int main(void) {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	vector<int> op;
	for (int i = 0; i < 4; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			op.push_back(i);
		}
	}
	
	do {
		int res = v[0];
		for (int i = 0; i < N-1; ++i) {
			if (op[i] == 0) {
				res += v[i + 1];
			}
			else if (op[i] == 1) {
				res -= v[i + 1];
			}
			else if (op[i] == 2) {
				res *= v[i + 1];
			}
			else {
				res /= v[i + 1];
			}
		}
		mx = max(mx, res);
		mn = min(mn, res);
	} while (next_permutation(op.begin(), op.end()));

	cout << mx << "\n" << mn << "\n";
}
