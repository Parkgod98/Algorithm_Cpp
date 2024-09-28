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

void PrintV(vector<vector<int>>& v)
{
	for (vector<int> i : v) {
		for (int j : i)
			cout << j << " ";
		cout << "\n";
	}
}

int dy[4] = {-1,0,1,0};
int dx[4] = { 0,1,0,-1 };

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n);
	vector<vector<int>> visited(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			v[i].push_back(s[j] - '0');
			visited[i].push_back(0);
		}
	}

	int count = 0;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

	while (q.size()) {
		pair<int, int> p = q.front();
		q.pop();
		int y = p.first;
		int x = p.second;
		
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n || nx >= m || nx < 0 || ny < 0)
				continue;
			if (!visited[ny][nx] && v[ny][nx] == 1) {
				q.push({ ny,nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
	}
	cout << visited[n - 1][m - 1] << "\n";
}
