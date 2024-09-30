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

void PrintV(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void Go(int y, int x, vector<vector<int>> &v, vector<vector<int>>& visited, int n, int m)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if (!visited[ny][nx] && v[ny][nx] == 0) {
			v[ny][nx] = 2;
			Go(ny, nx, v, visited, n, m);
		}
	}
}

int ZCount(vector<vector<int>> v)
{
	int count = 0;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (v[i][j] == 0)
				count++;
		}
	}
	return count;
}

void InitVisit(vector<vector<int>>& visited)
{
	for (int i = 0; i < visited.size(); ++i) {
		for (int j = 0; j < visited[i].size(); ++j)
			visited[i][j] = 0;
	}
}
int DFS(int z1, int z2, int z3, vector<pair<int,int>> &zero, vector<vector<int>> v, vector<vector<int>>& visited, int n, int m)
{
	v[zero[z1].first][zero[z1].second] = 1;
	v[zero[z2].first][zero[z2].second] = 1;
	v[zero[z3].first][zero[z3].second] = 1;

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (!visited[i][j] && v[i][j] == 2)
				Go(i, j, v, visited,n,m);
		}
	}
	v[zero[z1].first][zero[z1].second] = 0;
	v[zero[z2].first][zero[z2].second] = 0;
	v[zero[z3].first][zero[z3].second] = 0;

	return (ZCount(v) -3);

}



/* zero 데이터 조작 X*/
/* v 데이터 조작 O 원복되어야함.*/
/* Visited도 하나의 경우의 수를 보고 난 다음엔 원복되어야 함.*/

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n);
	vector<pair<int,int>> zero;
	vector<vector<int>> visited(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int k;
			cin >> k;
			v[i].push_back(k);
			if (k == 0)
				zero.push_back({ i,j });
			visited[i].push_back(0);
		}
	}

	//for (int i = 0; i < zero.size(); ++i) {
	//	cout << "(" << zero[i].first << "," << zero[i].second << ")" << endl;
	//}
	int z_sz = zero.size();
	int count = 0;
	int max_count = 0;
	for (int i = 0; i < z_sz; ++i) {
		for (int j = i + 1; j < z_sz; ++j) {
			for (int k = j + 1; k < z_sz; ++k) {
				count = DFS(i, j, k, zero, v, visited,n,m);
				max_count = max(max_count, count);
				InitVisit(visited);
				//break;
			}
			//break;
		}
		/*break;*/
	}
	cout << max_count;
}
