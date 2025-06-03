#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<char>> v(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}

	int cnt1, cnt2;
	cnt1 = cnt2 = 0;
	for (int i = 0; i < N; ++i) {
		int r = 0;
		for (int j = 0; j < N; ++j) {
			if (v[i][j] == '.')
				r++;
			else
				r = 0;

			if (r == 2)
				cnt1++;
		}
	}

	for (int j = 0; j < N; ++j) {
		int c = 0;
		for (int i = 0; i < N; ++i) {
			if (v[i][j] == '.')
				c++;
			else
				c = 0;

			if (c == 2)
				cnt2++;
		}
	}

	cout << cnt1 << " " << cnt2 << "\n";
}