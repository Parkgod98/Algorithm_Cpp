#include <iostream>
using namespace std;
#define SZ 1000002

int price[SZ];
int T, N;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {

		cin >> N;

		int mx = 0;
		long long res = 0;

		for (int i = 0; i < N; ++i) {
			cin >> price[N - i - 1];
		}

		for (int i = 0; i < N; ++i) {
			if (mx < price[i])
				mx = price[i];
			res += (mx - price[i]);
		}

		cout << "#" << tc << " " << res << "\n";
	}
}