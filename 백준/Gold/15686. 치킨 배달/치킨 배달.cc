#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int N, M;
vector<vector<int>> v;
vector<pair<int, int>> chicks,house;
vector<int> ans;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt = 10000000;
int what = 0;
void Comb(int depth,int idx) {
	if (ans.size() == M) {
		vector<int> visited(house.size(),100000000);
		for (int i = 0; i < (int)house.size(); ++i) {
			for (int j = 0; j < (int)ans.size(); ++j) {
				visited[i] = min(visited[i], abs(house[i].first - chicks[ans[j]].first) + abs(house[i].second - chicks[ans[j]].second));
			}
		}
		int sum = 0;
		for (int i = 0; i < (int)house.size(); ++i) {
			sum += visited[i];
		}
		cnt = min(cnt, sum);
		return;
	}

	for (int i = idx; i < (int)chicks.size(); ++i) {
		ans.push_back(i);
		Comb(depth + 1, i + 1);
		ans.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				chicks.push_back({ i,j });
			}
			else if (v[i][j] == 1) {
				house.push_back({ i,j });
			}
		}
	}

	Comb(0,0);
	cout << cnt << "\n";
}