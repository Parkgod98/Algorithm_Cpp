#define _crt_secure_no_warnings
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
//cin.tie(null);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

typedef long long ll;

void fill(vector<vector<int>>& v, int y, int x)
{
	for (int i = y - 1; i < y + 9; ++i) {
		for (int j = x - 1; j < x + 9; ++j) {
			v[i][j] = 1;
		}
	}
}
int GetArea(vector<vector<int>>& v)
{
	int count = 0;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			if (v[i][j])
				count++;
		}
	}
	return count;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> v(100, vector<int>(100));
	for (int i = 0; i < n; ++i) {
		int y, x;
		cin >> y >> x;
		fill(v, y, x);
	}
	cout << GetArea(v);
}
