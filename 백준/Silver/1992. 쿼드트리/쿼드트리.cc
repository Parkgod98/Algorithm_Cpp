#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N;
vector<vector<int>> v;
string ans = "";
void DFS(int y, int x, int sz) {
	int cur = v[y][x];
	for (int i = y; i < y + sz; ++i) {
		for (int j = x; j < x + sz; ++j) {
			if (v[i][j] != cur) {
				ans.push_back('(');
				DFS(y, x, sz / 2);
				DFS(y, x + sz / 2, sz / 2);
				DFS(y + sz / 2, x, sz / 2);
				DFS(y + sz / 2, x + sz / 2, sz / 2);
				ans.push_back(')');
				return;
			}
		}
	}
	ans.push_back(cur+'0');
}
int main()
{
	cin >> N;
	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j)
			v[i][j] = s[j] - '0';
	}


	DFS(0, 0, N);
	cout << ans << "\n";
}