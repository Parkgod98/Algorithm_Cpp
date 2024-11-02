#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPossible(vector<vector<int>>& v, int start)
{
	for (int i = 0; i < v.size() && i + start < v.size(); ++i) {
		for (int j = 0; j < v[i].size() && j + start < v[i].size(); ++j) {
			if (v[i][j] == v[i][j + start] && v[i][j] == v[i + start][j] && v[i][j] == v[i + start][j + start])
				return true;
		}
	}
	return false;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			v[i][j] = s[j];
		}
	}

	int start = min(n, m) -1;
	for (int i = start; i >= 0; --i) {
		if (IsPossible(v, i)) {
			cout << (i+1) * (i+1) << "\n";
			return 0;
		}
	}
}
