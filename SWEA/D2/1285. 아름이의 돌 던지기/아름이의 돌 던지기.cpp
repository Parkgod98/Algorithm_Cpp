#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int mn = 1000000;
int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		int cnt = 1;
		for (int i = 0; i < N; ++i) {
			int k;
			cin >> k;

			if (abs(0 - k) < mn)
				mn = abs(0 - k);
			else if (abs(0 - k) == mn)
				++cnt;
		}
		cout << "#" << tc << " " << mn << " " <<cnt  << "\n";
		mn = 1000000;
	}
}