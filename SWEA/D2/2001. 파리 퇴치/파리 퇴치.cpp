#include <iostream>
using namespace std;

int T, N, M;
int arr[15][15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> arr[i][j];
			}
		}

		int res = 0;
		for (int i = 0; i < N - M + 1; ++i) {
			for (int j = 0; j < N - M + 1; ++j) {
				
				int sum = 0;
				for (int y = i; y < i + M; ++y) {
					for (int x = j; x < j + M; ++x) {
						sum += arr[y][x];
					}
				}
				if (res < sum)
					res = sum;
			}
		}

		cout << "#" << tc << " " << res << "\n";
	}
}