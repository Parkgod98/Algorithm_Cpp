#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void DFS(vector<vector<int>>& v, int y,int x, int h,vector<vector<int>> &visited)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= v.size() || nx >= v.size() || visited[ny][nx] || v[ny][nx] <=h)
			continue;
		DFS(v, ny, nx, h, visited);
	}
}

int main(void)
{
	int n;
	cin >> n;

	// 영역 입력 받기
	int mx = 0; // 가장 높은 지역의 높이
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			cin >> v[i][j];
			mx = max(mx, v[i][j]);
		}
	}

	int mx_count = 0;
	int count = 0;
	for (int h = 0; h <= mx; ++h) {
		vector<vector<int>> visited(n, vector<int>(n));
		for (int r = 0; r < v.size(); ++r) {
			for (int c = 0; c < v.size(); ++c) {
				if (v[r][c] > h && !visited[r][c]) {
					DFS(v, r, c, h, visited);
					count++;
				}
			}
		}
		mx_count = max(mx_count, count);
		count = 0;
	}

	cout << mx_count;
}