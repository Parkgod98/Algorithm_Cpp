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
typedef long long ll;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };


void DFS(int y, int x, vector<vector<int>>& v, vector<vector<bool>>& visited, int& count, int n)
{
	visited[y][x] = 1;
	count++;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;
		if (!visited[ny][nx] && v[ny][nx] == 1) {
			DFS(ny, nx, v, visited, count, n);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	
	vector<vector<int>> v(n);
	vector<vector<bool>> visited(n);

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			v[i].push_back(s[j] - '0');
			visited[i].push_back(0);
		}
	}

	vector<int> res;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == 1 && !visited[i][j]) {
				DFS(i, j, v, visited, count, n);
				res.push_back(count);
				count = 0;
			}
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i : res)
		cout << i << "\n";

}
