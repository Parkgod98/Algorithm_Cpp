#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int GetMin(int y, int x, vector<vector<int>>& v, vector<pair<int, int>> chicks, vector<int> &r)
{
	int min_distance = 500000;
	for (int i = 0; i < r.size(); ++i) {
		int cy = chicks[r[i]].first;
		int cx = chicks[r[i]].second;
		min_distance = min(min_distance, abs(x-cx) +abs(y-cy));
	}
	return min_distance;
}

void Comb(int n, int k, int depth, vector<int> &r, vector<vector<int>> &v, vector<pair<int, int>> &chicks, int &res)
{
	if (r.size() == k) {
		for (int i = 0; i < r.size(); ++i) {
			v[chicks[r[i]].first][chicks[r[i]].second] = 2;
		}
		int tmp = 0;
		for (int i = 0; i < v.size(); ++i) {
			for (int j = 0; j < v.size(); ++j) {
				if (v[i][j] == 1)
					tmp += GetMin(i, j, v, chicks,r);
				if (tmp >= res)
					return;
			}
		}
		res = min(res, tmp);
		for (int i = 0; i < r.size(); ++i) {
			v[chicks[r[i]].first][chicks[r[i]].second] = 0;
		}
		return;
	}
	for (int i = depth; i < chicks.size(); ++i) {
		r.push_back(i);
		Comb(chicks.size(), k, i + 1, r, v, chicks,res);
		r.pop_back();
	}
}


int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(n));
	vector<pair<int,int>> chicks;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				chicks.push_back({ i,j });
				v[i][j] = 0;
			}
		}
	}

	
	int res = 5000000;
	vector<int> r;
	for (int k = 1; k <= m; ++k) {
		/* tmp 구하기.*/
		Comb(chicks.size(), k, 0, r, v, chicks, res);
	}

	cout << res;
}
