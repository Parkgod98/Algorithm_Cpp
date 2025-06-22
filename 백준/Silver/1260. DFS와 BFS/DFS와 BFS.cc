#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <queue>
using namespace std;
int N, M, S;

vector<vector<int>> v;
vector<bool> visited;
void DFS(int node) {
	if (visited[node])
		return;

	visited[node] = true;
	cout << node << " ";

	for (int &i : v[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

void BFS() {
	queue<int> q;
	q.push(S);
	visited[S] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int &i : v[cur]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> S;

	v = vector<vector<int>>(N+1);
	visited = vector<bool>(N + 1);
	for (int i = 0; i < M; ++i) {
		int s, e;
		cin >> s >> e;

		v[s].push_back(e);
		v[e].push_back(s);
	}

	for (int i = 1; i <= N; ++i) {
		sort(v[i].begin(), v[i].end());
	}

	DFS(S);
	cout << "\n";

	visited = vector<bool>(N + 1);
	BFS();
	cout << "\n";
}  