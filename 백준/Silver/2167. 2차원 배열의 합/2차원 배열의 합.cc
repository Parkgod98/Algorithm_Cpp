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

	vector<vector<int>> prefix_sum(N+1, vector<int>(M+1));
	for (int i = 1; i < N+1; ++i) {
		prefix_sum[i][1] = v[i-1][0];
		for (int j = 2; j < M+1; ++j) {
			prefix_sum[i][j] = prefix_sum[i][j - 1] + v[i-1][j-1];
		}
	}
	for (int j = 1; j < M + 1; ++j) {
		for (int i = 1; i < N + 1; ++i) {
			prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j];
		}
	}

	int K;
	cin >> K;

	for (int tc = 0; tc < K; ++tc) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;

		int sum = prefix_sum[x][y] - prefix_sum[x][j - 1] - prefix_sum[i-1][y] + prefix_sum[i - 1][j - 1];

		cout << sum << "\n";
	}
}