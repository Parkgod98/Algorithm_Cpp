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

void DFS(int y, int x, vector<vector<int>>& v, vector<vector<bool>>& visited, int m, int n)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || nx >= m || ny < 0 || nx < 0)
			continue;
		if (!visited[ny][nx] && v[ny][nx] == 1) {
			DFS(ny, nx, v, visited,m,n);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	for (int c = 0; c < t; ++c) {
		int m, n, k;
		cin >> m >> n >> k;

		vector<vector<int>> v(n);
		vector<vector<bool>> visited(n);
		/* 맵,비지티드 초기화 */
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				v[i].push_back(0);
				visited[i].push_back(0);
			}
		}

		/* 배추 위치 표기 */
		for (int i = 0; i < k; ++i) {
			int y, x;
			cin >> x >> y;
			v[y][x] = 1;
		}

		int count = 0;
		for (int rr = 0; rr < n; ++rr) {
			for (int cc = 0; cc < m; ++cc) {
				if (!visited[rr][cc] && v[rr][cc] == 1) {
					DFS(rr, cc, v, visited, m, n);
					count++;
				}
			}
		}
		cout << count << endl;
	}
}
