#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int ZeroCount(int n) {
	if (n == 0)
		return 1;

	int res = 0;
	while (n != 0) {
		if (n % 10 == 0)
			++res;
		n /= 10;
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		int n, m;
		cin >> n >> m;

		int sum = 0;
		for (int i = n; i <= m; ++i) {
			sum += ZeroCount(i);
		}
		cout << sum << "\n";
	}
}