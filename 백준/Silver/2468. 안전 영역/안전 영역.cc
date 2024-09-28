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

void DFS(int y, int x, vector<vector<int>>& v, vector<vector<bool>>& visited, int n, int max)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;
		if (!visited[ny][nx] && v[ny][nx] > 0) {
			DFS(ny, nx, v, visited,n,max);
		}
	}
}

vector<vector<int>> MakeZero(vector<vector<int>> v, int max)
{
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j)
			if (v[i][j] <= max)
				v[i][j] = 0;
	}
	return v;
}

void initialize(vector<vector<bool>>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j)
			v[i][j] = 0;
	}
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> v(n);
	vector<vector<bool>> visited(n);

	int max = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int k;
			cin >> k;
			if (k > max)
				max = k;
			v[i].push_back(k);
			visited[i].push_back(false);
		}
	}

	int count = 0;
	int max_count = 0;
	for (int i = 0; i < max; ++i) {
		count = 0;
		vector<vector<int>> tmp = MakeZero(v, i);
		initialize(visited);
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (!visited[j][k] && tmp[j][k] > 0) {
					DFS(j, k, tmp, visited, n, i);
					count++;
				}
			}
		}
		
		if (max_count < count)
			max_count = count;
	}
	cout << max_count;
}
