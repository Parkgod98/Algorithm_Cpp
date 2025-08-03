#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int N,M;
#define INF 999999999

int main() {
	cin >> N;
	cin >> M;

	vector<vector<int>> v(N+1, vector<int>(N + 1,INF));
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b] = min(c,v[a][b]);
	}
	for (int i = 1; i <= N; ++i)
		v[i][i] = 0;

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (v[i][k] + v[k][j] < v[i][j]) {
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (v[i][j] == INF)
				cout << 0 << " ";
			else
				cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}