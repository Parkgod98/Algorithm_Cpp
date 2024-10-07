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

void DFS(vector<vector<int>>& v, vector<int>& visited, int s)
{
	cout << s << " ";
	visited[s] = 1;
	sort(v[s].begin(), v[s].end());
	for (int nx : v[s]) {
		if (!visited[nx]) {
			DFS(v, visited, nx);
		}
	}
}

void BFS(vector<vector<int>>& v, vector<int>& visited, int s)
{
	queue<int> q;
	q.push(s);
	sort(v[s].begin(), v[s].end());
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		if (!visited[k])
			cout << k << " ";
		visited[k] = 1;
		for (int nx : v[k]) {
			if (!visited[nx]) {
				q.push(nx);
				
			}
		}
	}
}


int main()
{
	int n, m, s;
	cin >> n >> m >> s;

	vector<vector<int>> v(n+1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<int> visited(n+1);
	DFS(v, visited,s);
	cout << endl;
	for (int i = 0; i < visited.size(); ++i)
		visited[i] = 0;

	BFS(v, visited,s);

}
