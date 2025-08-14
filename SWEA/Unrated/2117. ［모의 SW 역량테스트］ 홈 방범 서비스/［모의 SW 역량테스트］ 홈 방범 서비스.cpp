#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
int N, M;
vector<vector<int>> v;
vector<vector<int>> visited;
int mx;
int house_num = 0;
int k_limit = 0;

void Input() {
	mx = 1;
	house_num = k_limit = 0;
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 1)
				house_num++;
		}
	}

	int max_money = house_num * M;
	while ((k_limit*k_limit + (k_limit - 1)*(k_limit - 1)) < max_money) {
		k_limit++;
	}

}

void PrintV() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int Check(int y, int x, int k) {
	visited = vector<vector<int>>(N, vector<int>(N));

	int cnt = 0;
	int start = y - (k - 1);
	for (int r = y - (k - 1); r <= y; ++r) {
		for (int c = x - (r-start); c <= x + (r-start); ++c) {
			if (r < 0 || r >= N || c < 0 || c >= N)
				continue;
			if (v[r][c]) {
				++cnt;
				visited[r][c] = 1;
			}
		}
	}

	int end = y + (k - 1);
	for (int r = y + 1; r <= y + (k - 1); ++r) {
		for (int c = x - (end - r); c <= x + (end - r); ++c) {
			if (r < 0 || r >= N || c < 0 || c >= N)
				continue;
			if (v[r][c]) {
				++cnt;
				visited[r][c] = 1;
			}
		}
	}
	//PrintV();
	int cost = (cnt*M) - (k*k + (k - 1)*(k - 1));
	if (cost >= 0)
		return cnt;
	return -1;
}

void Solve() {
	for (int k = k_limit; k >= 2; --k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				mx = max(mx,Check(i, j, k));
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		Input();
		Solve();

		cout << "#" << tc << " " << mx << "\n";
	}
}