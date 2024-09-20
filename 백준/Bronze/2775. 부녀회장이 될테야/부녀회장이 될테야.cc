//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;


//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

//cout << fixed;
//cout.precision(2);

void Solve(int k, int n, vector<vector<int>> &v)
{
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j == 0 || j == 1 || i == 0)
				v[i][j] = j;
			else {
				v[i][j] = v[i][j - 1] + v[i - 1][j];
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int k, n;
		cin >> k >> n;
		vector<vector<int>> v;
		for (int j = 0; j <= k; ++j) {
			vector<int> a(n + 1);
			v.push_back(a);
		}
		Solve(k, n, v);
		cout << v[k][n] << "\n";
	}
}