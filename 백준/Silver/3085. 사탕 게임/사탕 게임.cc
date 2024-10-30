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

int GetMaxLength(vector<vector<int>>& v)
{
	int max_len = 1;
	/* 가로 최대 구하기 */
	for (int i = 0; i < v.size(); ++i){
		int len = 1;
		for (int j = 0; j < v.size() -1; ++j) {
			if (v[i][j] == v[i][j + 1])
				len++;
			else
				len = 1;
			max_len = max(len, max_len);
		}
	}

	/* 세로 최대 구하기 */
	for (int i = 0; i < v.size(); ++i) {
		int len = 1;
		for (int j = 0; j < v.size() -1; ++j) {
			if (v[j][i] == v[j + 1][i])
				len++;
			else
				len = 1;
			max_len = max(len, max_len);
		}
	}
	return max_len;
}


int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> v(n,vector<int>(n));

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
			v[i][j] = s[j];
	}
	int max_len = 1;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size()-1; ++j) {
			if (v[i][j] != v[i][j + 1]) {
				swap(v[i][j], v[i][j + 1]);
				max_len = max(max_len, GetMaxLength(v));
				swap(v[i][j], v[i][j + 1]);
			}
			if (v[j][i] != v[j + 1][i]) {
				swap(v[j][i], v[j+1][i]);
				max_len = max(max_len, GetMaxLength(v));
				swap(v[j][i], v[j + 1][i]);
			}
		}
	}

	cout << max_len << "\n";
	return 0;
}		
