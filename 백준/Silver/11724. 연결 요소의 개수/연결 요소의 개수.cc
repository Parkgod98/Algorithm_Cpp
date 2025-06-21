#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;

void DFS(int node) {
	if (visited[node])
		return;

	visited[node] = true;
	for (int &i : v[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;

	v = vector<vector<int>>(N + 1);

	for (int i = 0; i < M; ++i) {
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	visited = vector<bool>(N + 1,false);

	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			++cnt;
			DFS(i);
		}
	}

	cout << cnt << "\n";
}  