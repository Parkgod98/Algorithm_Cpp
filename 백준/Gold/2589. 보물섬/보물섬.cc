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
void InitVisit(vector<vector<int>>& visited)
{
	for (int i = 0; i < visited.size(); ++i) {
		for (int j = 0; j < visited[i].size(); ++j)
			visited[i][j] = 0;
	}
}

int GetMax(vector<vector<int>>& visited)
{
	int mx = 0;
	for (int i = 0; i < visited.size(); ++i) {
		for (int j = 0; j < visited[i].size(); ++j) {
			if (mx < visited[i][j])
				mx = visited[i][j];
		}
	}
	return mx;
}

void PrintV(vector<vector<int>>& visited)
{
	for (int i = 0; i < visited.size(); ++i) {
		for (int j = 0; j < visited[i].size(); ++j)
			cout << visited[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			v[i][j] = s[j];
		}
	}

	int mx = 0;
	vector<vector<int>> visited(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == 'L') {
				queue<pair<int,int>> q;
				q.push({ i,j });
				visited[i][j] = 1;
				while (!q.empty()) {
					pair<int, int> tmp = q.front();
					q.pop();
					int y = tmp.first;
					int x = tmp.second;
					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= m)
							continue;
						if (!visited[ny][nx] && v[ny][nx] == 'L') {
							q.push({ ny,nx });
							visited[ny][nx] = visited[y][x] + 1;
						}
					}
				}
			}

			mx = max(GetMax(visited), mx);
			InitVisit(visited);
		}
	}
	cout << mx-1;

}
