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

int DFS(int cur, vector<vector<int>>& v, vector<int>& visited)
{
	int cnt = 1;
	visited[cur] = 1;

	for (int i = 0; i < v[cur].size(); ++i) {
		if (!visited[v[cur][i]]) {
			cnt +=DFS(v[cur][i], v, visited);
		}
	}
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<int> visited(n + 1);

	cout << DFS(1, v, visited) -1;
}
