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

/* l명 이상, r명 이하라면 국경선 열고 하루동안 인구 이동 시작.*/
/* 국경선 열려있고, 인접한 칸으로 이동 가능하면 연합.*/
/* 각 칸의 인구수는 (연합의 인구수)/ 나라 갯수 */
/* 연합 해체. */

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void DFS(int y, int x, vector<vector<int>>& v, vector<pair<int, int>> &relate, vector<vector<int>> &visited, int n, int l, int r)
{
	visited[y][x] = 1;
	relate.push_back({ y,x });
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		if (!visited[ny][nx] && abs(v[y][x] - v[ny][nx]) >= l && abs(v[y][x] - v[ny][nx]) <= r) {
			DFS(ny, nx, v, relate, visited, n, l, r);
		}
	}
}

bool IsMove(vector<vector<int>>& v, int n, int l, int r)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 4; ++k) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
					continue;
				if (abs(v[i][j] - v[ny][nx]) >= l && abs(v[i][j] - v[ny][nx]) <= r)
					return true;
			}
		}
	}
	return false;
}

void InitRelate(vector<pair<int, int>>& relate)
{
	while (relate.size()) {
		relate.pop_back();
	}
}

void Move(vector<vector<int>>& v, vector<pair<int, int>>& relate)
{
	int sum = 0;
	for (int i = 0; i < relate.size(); ++i) {
		sum += v[relate[i].first][relate[i].second];
	}

	sum /= relate.size();
	for (int i = 0; i < relate.size(); ++i) {
		v[relate[i].first][relate[i].second] = sum;
	}
}

void PrintV(vector<vector<int>>& v, int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int n, l, r;
	cin >> n >> l >> r;

	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
	}

	int res = 0;
	while (IsMove(v,n,l,r)) {
		vector<vector<int>> visited(n, vector<int>(n));
		vector<pair<int, int>> relate;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!visited[i][j]) {
					InitRelate(relate);
					DFS(i, j, v, relate, visited, n, l, r);
					if (relate.size())
						Move(v, relate);
				}
			}
		}
		res++;
	}
	cout << res;

}
