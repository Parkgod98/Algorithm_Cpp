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

	vector<char> op;
	for (int i = 0; i < 4; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			if (i == 0)
				op.push_back('+');
			else if (i == 1) {
				op.push_back('-');
			}
			else if (i == 2)
				op.push_back('*');
			else
				op.push_back('/');
		}
	}
	sort(op.begin(), op.end());
	
	do {
		int idx = 0;
		int op_idx = 0;
		int res = v[0];
		while (idx + 1 < N) {
			if (op[op_idx] == '+') {
				res = res + v[idx + 1];
			}
			else if (op[op_idx] == '-') {
				res = res - v[idx + 1];
			}
			else if (op[op_idx] == '*')
				res = res * v[idx + 1];
			else if (op[op_idx] == '/')
				res = res / v[idx + 1];
			idx++;
			op_idx++;
		}
		mx = max(mx, res);
		mn = min(mn, res);
	} while (next_permutation(op.begin(), op.end()));

	cout << mx << "\n" << mn << "\n";
}
