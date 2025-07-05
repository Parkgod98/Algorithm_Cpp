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

	vector<bool> v(1000001,true);
	v[0] = v[1] = false;
	for (int i = 2; i*i <= 1000000; ++i) {
		for (int j = i * 2; j <= 1000000; j += i) {
			v[j] = false;
		}
	}


	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		int limit = N / 2;
		int cnt = 0;
		for (int i = 2; i <= limit; ++i) {
			if (v[i] && v[N - i]) {
				++cnt;
			}
		}
		cout << cnt << "\n";
	}
}