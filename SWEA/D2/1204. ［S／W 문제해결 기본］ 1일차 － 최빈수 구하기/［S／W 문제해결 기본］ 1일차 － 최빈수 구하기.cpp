#include <iostream>
using namespace std;
#define SZ 102

int arr[SZ];
int T, N;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;

		for (int i = 0; i < 1000; ++i) {
			int n;
			cin >> n;
			arr[n]++;
		}

		int res = 0;
		int k = 0;
		for (int i = 100; i >= 0; --i) {
			if (k < arr[i]) {
				k = arr[i];
				res = i;
			}
			arr[i] = 0;
		}

		cout << "#" << tc << " " << res << "\n";

	}
}