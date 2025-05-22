#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int m, d, m1, d1;
		cin >> m >> d >> m1 >> d1;

		int res = 0;
		if (m1 - m == 0) {
			res = d1 - d + 1;
		}
		else {
			res += days[m] - d + 1;
			for (int s = m + 1; s < m1; ++s) {
				res += days[s];
			}
			res += d1;
		}
		cout << "#" << tc << " " << res << "\n";
	}
}