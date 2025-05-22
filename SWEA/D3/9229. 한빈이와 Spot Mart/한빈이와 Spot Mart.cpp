#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int mx;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, M;
		cin >> N >> M;

		vector<int> v(N);
		for (int i = 0; i < N; ++i)
			cin >> v[i];

		sort(v.begin(), v.end(), greater<int>());
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (v[i] + v[j] > M)
					continue;
				else if (v[i] + v[j] <= M && (v[i] + v[j]) > mx) {
					mx = v[i] + v[j];
				}
			}
		}

		cout << "#" << tc << " " << mx << "\n";
		mx = -1;
	}
}