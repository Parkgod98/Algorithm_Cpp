#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, C;
vector<vector<int>> v;
vector<pair<int, int>> start_list;
int mx = 0;
int comb_mx = 0;
void GetStartList() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= N - M; ++j) {
			start_list.push_back({ i,j });
		}
	}
}

void Comb(int k, int idx, vector<int> &tmp, vector<int> &ans) {
	if (ans.size() == k) {
		int res = 0;
		int sum = 0;
		for (int i = 0; i < k; ++i) {
			res += (ans[i] * ans[i]);
			sum += ans[i];
		}
		if (sum > C)
			return;
		comb_mx = max(res, comb_mx);
		return;
	}

	for (int i = idx; i < M; ++i) {
		ans.push_back(tmp[i]);
		Comb(k, i + 1, tmp, ans);
		ans.pop_back();
	}
}
int GetMax(pair<int, int> &p) {
	vector<int> tmp(M);
	int y = p.first;
	int x = p.second;
	int sum = 0;
	for (int i = x; i < x + M; ++i) {
		tmp[i-x] = v[y][i];
	}
	int res = 0;
	vector<int> ans;
	for (int i = 1; i <= M; ++i) {
		Comb(i,0,tmp,ans);
	}

	return comb_mx;
}

void Solve() {
	int sz = start_list.size();
	
	for (int i = 0; i < sz; ++i) {
		for (int j = i + 1; j < sz; ++j) {
			if ((start_list[i].first != start_list[j].first) || ((start_list[i].second + M) <= start_list[j].second)) {
				int a = GetMax(start_list[i]);
				comb_mx = 0;
				int b = GetMax(start_list[j]);
				comb_mx = 0;
				mx = max(mx, a + b);
			}
		}
	}
}
int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> C;
		v = vector<vector<int>>(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				cin >> v[i][j];
		}
		GetStartList();
		//for (int i = 0; i < start_list.size(); ++i) {
		//	cout << start_list[i].first << " " << start_list[i].second << "\n";
		//}
		Solve();

		cout << "#" << tc << " " << mx << "\n";
		mx = 0;
		start_list.clear();
	}
}
