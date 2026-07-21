#include <iostream>
#include <algorithm>
using namespace std;
#define SZ 1000002

int price[SZ];

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;

		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> price[N - i - 1];
		}

		long long res = 0;
		int mx = 0;
		for (int i = 0; i < N; ++i) {
			mx = max(mx, price[i]);
			res += (mx - price[i]);
		}

		cout << "#" << tc << " " << res << "\n";
	}
}