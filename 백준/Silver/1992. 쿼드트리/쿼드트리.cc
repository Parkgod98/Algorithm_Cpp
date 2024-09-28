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

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void PrintV(vector<vector<int>>& v)
{
	for (vector<int> a : v) {
		for (int i : a)
			cout << i << " ";
		cout << endl;
	}
}

int Check(vector<vector<int>>& v, int y1, int x1, int y2, int x2)
{
	bool flag0 = false;
	bool flag1 = false;
	if (y1 == y2 && x1 == x2) {
		return v[y2][x2];
	}
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			if (v[i][j] == 1)
				flag1 = true;
			else
				flag0 = true;
			if (flag0 && flag1)
				return -1;
		}
	}
	if (flag0)
		return 0;
	return 1;
}

void DFS(vector<vector<int>>& v, int y1, int x1, int y2, int x2, string &ret)
{
	int mode = Check(v, y1, x1, y2, x2);
	if (mode == 0)
		ret += "0";
	else if (mode == 1)
		ret += "1";
	else {
		ret += '(';
		DFS(v, y1, x1, y1 + (y2-y1)/2, x1 +(x2-x1)/2, ret);
		DFS(v, y1, x1 + (x2-x1)/ 2, y1 + (y2-y1) / 2, x2 , ret);
		DFS(v, y1 + (y2-y1) / 2, x1, y2, x1 + (x2-x1) / 2, ret);
		DFS(v, y1 + (y2-y1) / 2, x1 + (x2-x1) / 2, y2, x2, ret);
		ret += ')';
	}
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> v(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int len = s.length();
		for (int j = 0; j < len; ++j) {
			v[i].push_back(s[j] - '0');
		}
	}

	string ret = "";
	DFS(v, 0, 0, n, n,ret);
	cout << ret;

}
