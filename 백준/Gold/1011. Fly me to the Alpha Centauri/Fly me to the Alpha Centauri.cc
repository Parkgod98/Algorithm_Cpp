#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		long long x, y;
		cin >> x >> y;

		long long distance = y - x;

		long long start = 1;
		while (start*start <= distance) {
			start++;
		}
		--start;
		long long res = start * 2 - 1;
		long long remain = distance - (start*start);
		if (remain) {
			res += ceil((double)(remain) / start);
		}
		cout << res << "\n";
	}
}
