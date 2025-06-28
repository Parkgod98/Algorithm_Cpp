#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N, M, R;

vector<vector<int>> v;
vector<int> visited;
int depth = 1;
void DFS(int cur) {
	if (visited[cur])
		return;

	visited[cur] = depth++;
	for (int &i : v[cur]) {
		if (!visited[i])
			DFS(i);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> R;

	v = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i)
		sort(v[i].begin(), v[i].end());
	DFS(R);

	for (int i = 1; i <= N; ++i) {
		if (visited[i] >= 1)
			cout << visited[i] << "\n";
		else
			cout << 0 << "\n";
	}
}  