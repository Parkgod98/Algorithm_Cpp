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
int N;
int cnt = 0;
vector<vector<int>> v;
vector<int> ans, ans2;
map<int, bool> mp;
int mn = 20 * 20 * 100;

void Comb(int depth,int idx) {
	if (ans.size() == N / 2) {


		for (int i = 1; i <= N; ++i) {
			if (!mp[i])
				ans2.push_back(i);
		}
		int start, link;
		start = link = 0;
		for (int i = 0; i < ans.size(); ++i) {
			for (int j = i + 1; j < ans.size(); ++j) {
				int a = ans[i];
				int b = ans[j];
				start += v[a][b] + v[b][a];
				int c = ans2[i];
				int d = ans2[j];
				link += v[c][d] + v[d][c];
			}
		}
		mn = min(mn, abs(start - link));
		ans2.clear();
		return;
	}

	for (int i = idx + 1; i <= N; ++i) {
		ans.push_back(i);
		mp[i] = true;
		Comb(depth + 1, i);
		ans.pop_back();
		mp[i] = false;
	}
}
int main(void) {
	cin >> N;

	v = vector<vector<int>>(N+1,vector<int>(N+1));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> v[i+1][j+1];
	}

	for (int i = 1; i <= N; ++i)
		mp[i] = false;
	Comb(0,0);
	cout << mn << "\n";
}