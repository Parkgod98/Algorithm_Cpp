#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <list>
using namespace std;
int N, R, Q;
vector<vector<int>> tree;
vector<int> visited;
vector<int> sz_list;
int DFS(int cur) {
	int cnt = 1;
	for (int &n : tree[cur]) {
		if (!visited[n] && n != R) {
			visited[n] = 1;
			cnt += DFS(n);
			visited[n] = 0;
		}
	}

	sz_list[cur] = cnt;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> R >> Q;

	tree= vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}


	sz_list = vector<int>(N + 1);
	sz_list[R] = DFS(R);

	for (int i = 0; i < Q; ++i) {
		int n;
		cin >> n;
		cout << sz_list[n] << "\n";
	}
}