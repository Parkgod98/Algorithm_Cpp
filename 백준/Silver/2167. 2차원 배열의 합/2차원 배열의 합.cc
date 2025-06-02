#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> v[i][j];
	}

	int K;
	cin >> K;

	for (int tc = 0; tc < K; ++tc) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;

		int sum = 0;
		for (int r = i - 1; r <= x - 1; ++r) {
			for (int c = j - 1; c <= y - 1; ++c) {
				sum += v[r][c];
			}
		}
		cout << sum << "\n";
	}
}