#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> hak(2, vector<int>(7)); // 성별, 각 학년
	for(int i = 0; i < n; ++i) {
		int s, y;
		cin >> s >> y;
		hak[s][y]++;
	}

	int cnt = 0;
	for(int i = 0; i < hak.size(); ++i) {
		for(int j = 1; j < hak[i].size(); ++j) {
			cnt += ceil((double)hak[i][j] / k);
		}
	}
	cout << cnt;
}