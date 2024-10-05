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
#define INF 99999999
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void PrintV(vector<vector<int>>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int r, c;
	cin >> r >> c;

	vector<vector<char>> v(r, vector<char>(c));
	queue <pair<int, int>> fq;
	vector<vector<int>> f_visited(r, vector<int>(c,INF));
	int jy, jx;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 'F') {
				f_visited[i][j] = 1;
				fq.push({ i,j });
			}
			else if (v[i][j] == 'J') {
				jy = i;
				jx = j;
			}
		}
	}
	while (!fq.empty()) {
		pair<int, int> p = fq.front();
		int y = p.first;
		int x = p.second;
		fq.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;
			if (f_visited[ny][nx] == INF && v[ny][nx] != '#') {
				fq.push({ ny,nx });
				f_visited[ny][nx] = f_visited[y][x] + 1;
			}
		}
	}

	vector<vector<int>> visited(r, vector<int>(c));
	queue<pair<int, int>> q;
	q.push({ jy,jx });
	visited[jy][jx] = 1;
	int ret = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		int y = p.first;
		int x = p.second;
		q.pop();
		if (y == 0 || y == r - 1 || x == 0 || x == c - 1) {
			ret = visited[y][x];
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;
			if (visited[ny][nx] || v[ny][nx] == '#' || v[ny][nx] == 'F')
				continue;
			if (!visited[ny][nx] && f_visited[ny][nx] > visited[y][x] + 1) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	if (ret != 0)
		cout << ret;
	else
		cout << "IMPOSSIBLE";
}
