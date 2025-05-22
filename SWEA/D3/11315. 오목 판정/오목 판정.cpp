#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int N;

string Solve(vector<vector<char>> &v) {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N -4; ++j) {
			if (v[i][j] == 'o') {
				if (v[i][j + 1] == 'o' &&v[i][j + 2] == 'o' &&v[i][j + 3] == 'o' &&v[i][j + 4] == 'o')
					return "YES";
			}
		}
	}

	for (int i = 0; i < N - 4; ++i) {
		for (int j = 0; j < N; ++j) {
			if (v[i][j] == 'o') {
				if (v[i+1][j] == 'o' &&v[i+2][j] == 'o' &&v[i+3][j] == 'o' &&v[i+4][j] == 'o')
					return "YES";
			}
		}
	}

	for (int i = 0; i < N - 4; ++i) {
		for (int j = 0; j < N-4; ++j) {
			if (v[i][j] == 'o') {
				if (v[i + 1][j + 1] == 'o'&&v[i + 2][j + 2] == 'o'&&v[i + 3][j + 3] == 'o'&&v[i + 4][j + 4] == 'o')
					return "YES";
			}
		}
	}

	for (int i = 0; i < N -4; ++i) {
		for (int j = N-1; j >= 4; --j) {
			if (v[i][j] == 'o') {
				if (v[i + 1][j - 1] == 'o' && v[i + 2][j - 2] == 'o' && v[i + 3][j - 3] == 'o' && v[i + 4][j - 4] == 'o')
					return "YES";
			}
		}
	}

	return "NO";
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;

		vector<vector<char>> v(N, vector<char>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				cin >> v[i][j];
		}
		
		cout << "#" << tc << " " << Solve(v) << "\n";
	}
}