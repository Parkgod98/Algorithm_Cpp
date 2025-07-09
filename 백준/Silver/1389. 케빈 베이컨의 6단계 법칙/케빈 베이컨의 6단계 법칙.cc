#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 100000000
int N, M;
int v[101][101] = { 0 };
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			v[i][j] = INF;
		}
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}

	vector<vector<int>> dp(N + 1, vector<int>(N + 1));
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (v[i][k] + v[k][j] < v[i][j]) {
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}

	int mn = INF;
	int res = -1;
	for (int i = 1; i <= N; ++i) {
		int sum = 0;
		for (int j = 1; j <= N; ++j) {
			if (i != j)
				sum += v[i][j];
		}
		if (sum < mn) {
			mn = sum;
			res = i;
		}
	}

	cout << res << "\n";
}