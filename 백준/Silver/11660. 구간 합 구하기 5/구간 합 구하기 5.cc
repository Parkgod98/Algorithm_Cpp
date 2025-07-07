#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N,M;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	vector<vector<int>> v(N+1, vector<int>(N+1));
	vector<vector<int>> p_sum(N+1, vector<int>(N+1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			cin >> v[i][j];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			p_sum[i][j] = p_sum[i][j - 1] + v[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			p_sum[j][i] = p_sum[j - 1][i] + p_sum[j][i];
		}
	}

	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int sum = p_sum[x2][y2] - p_sum[x2][y1-1] - p_sum[x1-1][y2] + p_sum[x1 - 1][y1 - 1];
		cout << sum << "\n";
	}
}