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
	int T;
	cin >> T;

	vector<bool> v(10001,true);
	v[0] = v[1] = false;

	for (int i = 2; i*i <= 10000; ++i) {
		if (v[i]) {
			for (int j = i * 2; j <= 10000; j += i)
				v[j] = false;
		}
	}

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;

		int start = n / 2;
		for (int i = start; i >= 2; --i) {
			if (v[i] && v[n - i]) {
				cout << i << " " << n - i << "\n";
				break;
			}
		}
	}
}