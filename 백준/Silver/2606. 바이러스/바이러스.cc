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

	queue<int> q;
	vector<int> visited(n + 1);
	q.push(1);
	visited[1] = 1;

	int count = 0;
	while (!q.empty()) {
		int nx = q.front();
		q.pop();
		for (int i = 0; i < v[nx].size(); ++i) {
			if (!visited[v[nx][i]]) {
				q.push(v[nx][i]);
				count++;
				visited[v[nx][i]] = 1;
			}
		}
	}
	cout << count;
}
