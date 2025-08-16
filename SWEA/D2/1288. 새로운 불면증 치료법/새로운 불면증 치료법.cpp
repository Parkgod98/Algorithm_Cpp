#include <iostream>
using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		int visited = 0;
		int i = 0;
		while (visited != ((1 << 10) - 1)) {
			++i;
			int tmp = N * i;
			while (tmp != 0) {
				visited |= (1 << (tmp % 10));
				tmp /= 10;
			}
		}
		cout << "#" << tc << " " << N*i << "\n";
	}
}