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

void Fill(int x1, int y1, int x2, int y2, vector<vector<int>>& v)
{
	for (int i = y1; i < y2; ++i) {
		for (int j = x1; j < x2; ++j) {
			v[i][j] = 0;
		}
	}
}

void DFS(int y, int x, vector<vector<int>>& v, vector<vector<bool>>& visited, int m, int n, int &count)
{
	visited[y][x] = 1;
	count++;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n)
			continue;
		if (!visited[ny][nx] && v[ny][nx] == 1)
			DFS(ny, nx, v, visited, m, n, count);
	}
}

void PrintV(vector<vector<int>>& v)
{
	for (vector<int> a : v) {
		for (int i : a)
			cout << i << " ";
		cout << endl;
	}
}

int main()
{
	int m, n, k;
	cin >> m >> n >> k;

	vector<vector<int>> v(m);
	vector<vector<bool>> visited(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			v[i].push_back(1);
			visited[i].push_back(false);
		}
	}
	for (int i = 0; i < k; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Fill(x1, y1, x2, y2, v);
	}

	int count = 0;
	vector<int> res;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j] && v[i][j] == 1) {
				DFS(i, j, v, visited, m, n, count);
				res.push_back(count);
				count = 0;
			}
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i : res)
		cout << i << " ";

}
