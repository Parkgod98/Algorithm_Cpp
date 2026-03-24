#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for(int tc = 1; tc <= T; ++tc) {
		int orig;
		cin >> orig;

		int mask = 0;

		int cur = orig;
		while(mask != 0b1111111111) {
			int nxt = cur;
			while(nxt != 0) {
				mask |= (1 << (nxt % 10));
				nxt /= 10;
			}

			cur += orig;
		}

		cout << "#" << tc << " " << cur - orig << "\n";
	}

}