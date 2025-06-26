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
	int n = 123456;
	n = n*2 + 1;

	vector<bool> v(n+1, true);
	v[0] = v[1] = false;

	for (int i = 2; i <= n; ++i) {
		for (int j = i*2; j <= n; j += i) {
			v[j] = false;
		}
	}

	while (1) {
		int x;
		cin >> x;
		if (x == 0)
			break;

		int cnt = 0;
		for (int i = x+1; i <= x * 2; ++i) {
			if (v[i])
				++cnt;
		}
		cout << cnt << "\n";
	}
}  