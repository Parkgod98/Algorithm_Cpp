#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int T;
vector<vector<int>> v;
vector<int> visited;
#define RED 2
#define BLUE 3
bool Cant = false;

void DFS(int start, int color) {
	if (Cant)
		return;

	for (int &nxt : v[start]) {
		if ((visited[nxt] == 0)) {
			if (color == RED)
				visited[nxt] = BLUE;
			else
				visited[nxt] = RED;
			DFS(nxt,visited[nxt]);
		}
		else if (visited[nxt] != 0 && visited[nxt] == color) {
			Cant = true;
			return;
		}
	}
}
int main() {
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int V, E;
		cin >> V >> E;
		v = vector<vector<int>>(V + 1);
		visited = vector<int>(V + 1);
		for (int i = 0; i < E; ++i) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= V; ++i) {
			if (!visited[i]) {
				visited[i] = RED;
				DFS(i, RED);
			}
		}

		if (Cant)
			cout << "NO\n";
		else
			cout << "YES" << "\n";
		Cant = false;
	}
}