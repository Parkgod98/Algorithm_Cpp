#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, M, K;
		cin >> N >> M >> K;
		int spare = 0;
		vector<int> human(N);
		for (int i = 0; i < N; ++i)
			cin >> human[i];

		sort(human.begin(), human.end());

		string res = "Possible";
		int idx = 0;
		for (int i = 0; i <= human[human.size() - 1]; ++i) {
			if (i != 0 && i%M == 0) {
				spare += K;
			}
			if (i == human[idx] && spare == 0) {
				res = "Impossible";
				break;
			}
			else if (i == human[idx] && spare > 0) {
				--spare;
				idx++;
			}
		}
		cout << "#" << tc << " " << res << "\n";
	}
}