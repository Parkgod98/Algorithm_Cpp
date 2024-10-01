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

void PrintV(vector<vector<int>>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool AllZero(vector<vector<int>> &v)
{
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j)
			if (v[i][j] != 0)
				return false;
	}
	return true;
}

void InitAir(vector<vector<int>>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (v[i][j] == 2) {
				v[i][j] = 0;
			}
		}
	}
}

/* 왼쪽, 오른쪽에 치즈가 있는가? */
bool LRCheck(vector<int>& v, int cur)
{
	if (cur == 0 || cur == v.size() - 1)
		return false;
	bool lc, rc;
	lc = rc = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 1 && i < cur)
			lc = 1;
		else if (v[i] == 1 && i > cur)
			rc = 1;
	}
	return lc && rc;
}

/* 위 아래에 치즈가 있는가? */
bool UDCheck(vector<vector<int>>& v, int r, int c)
{
	if (r == 0 || r == v.size() - 1 || c == 0 || c == v[0].size() - 1)
		return false;

	bool uc, dc;
	uc = dc = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i][c] == 1 && i < r) {
			uc = 1;
		}
		else if (v[i][c] == 1 && i > r) {
			dc = 1;
		}
	}
	return uc && dc;
}

void DFS(int y, int x, vector<vector<int>>& v, vector<vector<int>>& visited)
{
	visited[y][x] = 1;
	v[y][x] = 2;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= v.size() || nx >= v[i].size())
			continue;
		if (!visited[ny][nx] && v[ny][nx] == 0) {
			DFS(ny, nx, v, visited);
		}
	}
}

/* 공기 표시하기 공기는 전부 2로.*/
void AirCheck(vector<vector<int>>& v, vector<vector<int>>& visited)
{
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (v[i][j] == 0) {
				if (!(LRCheck(v[i], j) && UDCheck(v, i, j))) {
					DFS(i, j, v, visited);
				}
			}
		}
	}
}

/* 삭제할 치즈 고르기 */
int ChooseCheese(vector<vector<int>>& v)
{
	int count = 0;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (v[i][j] == 1) {
				for (int k = 0; k < 4; ++k) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= v.size() || nx >= v[i].size())
						continue;
					if (v[ny][nx] == 2) {
						count++;
						v[i][j] = 3;
						break;
					}
						
				}
			}
		}
	}

	return count;
}

/* 삭제 대상인 치즈 삭제하는 함수 */
void Pop(vector<vector<int>>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (v[i][j] == 3)
				v[i][j] = 0;
		}
	}
}

void InitVisit(vector<vector<int>>& visited)
{
	for (int i = 0; i < visited.size(); ++i) {
		for (int j = 0; j < visited[i].size(); ++j) {
			visited[i][j] = 0;
		}
	}
}

/* 구멍은 2, 팝되어야 할건 3*/
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n);
	vector<vector<int>> visited(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int k;
			cin >> k;
			v[i].push_back(k);
			visited[i].push_back(0);
		}
	}
	 
	int time, res;
	time = res = 0;
	while (!AllZero(v)) {
		AirCheck(v,visited); // 구멍 표시가 끝났을것.

		res = ChooseCheese(v);
		time++;
		Pop(v);
		InitAir(v);
		InitVisit(visited);
	}
	cout << time << "\n" << res;

}
