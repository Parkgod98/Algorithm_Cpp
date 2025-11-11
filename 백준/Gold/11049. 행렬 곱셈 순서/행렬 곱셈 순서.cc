#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, int>> v;
vector<vector<pair<int, int>>> dp_matrix;

vector<vector<int>> dp;

int Sum(int dx, int mid, int dy) {
	return dp_matrix[dx][mid].first * dp_matrix[dx][mid].second * dp_matrix[mid + 1][dy].second;
}


int main()
{
	cin >> N;
	v = vector<pair<int, int>>(N + 1);
	dp_matrix = vector<vector<pair<int, int>>>(N + 1,vector<pair<int,int>>(N+1));
	dp = vector<vector<int>>(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		cin >> v[i].first >> v[i].second;
		dp_matrix[i][i] = v[i];
	}

	for (int i = 1; i < N; ++i) {
		for (int dx = 1; dx + i <= N; ++dx) {
			int dy = dx + i;
			dp[dx][dy] = 2147483647;

			for (int mid = dx; mid < dy; ++mid) {
				dp[dx][dy] = min(dp[dx][dy], dp[dx][mid] + dp[mid + 1][dy] + Sum(dx, mid, dy));
			}
			dp_matrix[dx][dy].first = v[dx].first;
			dp_matrix[dx][dy].second = v[dy].second;
		}
	}

	cout << dp[1][N] << "\n";
	return 0;
}