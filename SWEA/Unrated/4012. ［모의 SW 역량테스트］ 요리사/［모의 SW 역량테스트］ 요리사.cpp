#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 999999999
int N;
vector<vector<int>> v;
vector<int> selected;
int mn = INF;

void Input() {
	cin >> N;
	v = vector<vector<int>>(N, vector<int>(N));
	selected = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i][j];
	}
	mn = INF;
}

int Calculate() {
	vector<int> v1, v2;
	for (int i = 0; i < N; ++i) {
		if (selected[i])
			v1.push_back(i);
		else
			v2.push_back(i);
	}

	int sum1, sum2;
	sum1 = sum2 = 0;

	for (int i = 0; i < N / 2; ++i) {
		for (int j = i + 1; j < N / 2; ++j) {
			int idx1 = v1[i];
			int idx2 = v1[j];

			int i1 = v2[i];
			int i2 = v2[j];
			sum1 += (v[idx1][idx2] + v[idx2][idx1]);
			sum2 += (v[i1][i2] + v[i2][i1]);
		}
	}

	return abs(sum1 - sum2);
}

void Comb(int idx, int depth, int k) {
	if (depth == k) {
		mn = min(mn, Calculate());
		return;
	}
	for (int i = idx; i < N; ++i) {
		selected[i] = 1;
		Comb(i + 1, depth + 1, k);
		selected[i] = 0;
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		Input();
		Comb(0, 0, N / 2);

		cout << "#" << tc << " " << mn << "\n";
	}
}