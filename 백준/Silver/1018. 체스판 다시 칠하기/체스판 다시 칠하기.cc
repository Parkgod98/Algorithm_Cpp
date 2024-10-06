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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

/*
f1,f2 둘다 1이면 맨 왼쪽 위가 짝수,짝수,
f1,f2 1,0 맨 왼쪽위가 짝수, 홀수
f1,f2 0,1 맨 왼쪽이 홀수, 짝수
f1,f2 0,0 맨 왼쪽 위 둘다 홀수
*/
string WB[8] = { "WBWBWBWB","BWBWBWBW",
"WBWBWBWB","BWBWBWBW"
,"WBWBWBWB","BWBWBWBW"
,"WBWBWBWB","BWBWBWBW" };
string BW[8] = {"BWBWBWBW",
"WBWBWBWB","BWBWBWBW"
,"WBWBWBWB","BWBWBWBW"
,"WBWBWBWB","BWBWBWBW","WBWBWBWB" };

int Check(int y, int x, vector<vector<char>>& v)
{
	int a, b;
	a = b = 0;
	int res1, res2;
	res1 = res2 = 0;
	for (int i = y; i < y + 8; ++i) {
		b = 0;
		for (int j = x; j < x + 8; ++j) {
			if (WB[a][b] != v[i][j])
				res1++;
			if (BW[a][b] != v[i][j])
				res2++;
			b++;
		}
		a++;
	}
	return min(res1, res2);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n);

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			v[i].push_back(s[j]);
		}
	}

	int res = 5000000;
	for (int i = 0; i < n - 8 + 1; ++i) {
		for (int j = 0; j < m - 8 + 1; ++j) {
			res = min(res, Check(i, j, v));
		}
	}
	cout << res;
}
