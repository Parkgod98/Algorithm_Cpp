#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<int> visited(n + 1);
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	int cnt = 0;

	auto it = q.front();
	q.pop();

	for (int &i : v[1]) {
		if (!visited[i]) {
			q.push(i);
			visited[i] = 1;
		}
	}


	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		++cnt;

		for (int &i : v[it]) {
			if (!visited[i]) {
				++cnt;
				visited[i] = 1;
			}
		}
	}

	cout << cnt << "\n";
}