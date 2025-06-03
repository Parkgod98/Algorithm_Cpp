#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<char>> v(N, vector<char>(N));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		bool start = false;
		bool okay = false;
		for (int j = 0; j < N; ++j) {
			if (start && v[i][j] == '.') {
				okay = true;
				continue;
			}
			if (v[i][j] == '.')
				start = true;
			else {
				if (okay) 
					++cnt;
				start = false;
				okay = false;
			}
		}
		if (okay)
			++cnt;
	}

	int cnt2 = 0;
	for (int j = 0; j < N; ++j) {
		bool start = false;
		bool okay = false;
		for (int i = 0; i < N; ++i) {
			if (start && v[i][j] == '.') {
				okay = true;
				continue;
			}
			if (v[i][j] == '.')
				start = true;
			else {
				if (okay)
					++cnt2;
				start = false;
				okay = false;
			}
		}
		if (okay)
			++cnt2;
	}

	cout << cnt << " " << cnt2 << "\n";
}