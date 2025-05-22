#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, M;
int res;
vector<vector<int>> v;
vector<int> visited;
void DFS(int n, int depth) {
	if (depth > res)
		res = depth;
	for (int &i : v[n]) {
		if (!visited[i]) {
			visited[i] = 1;
			DFS(i, depth + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M;
		
		if (N == 1) {
			res = 1;
		}
		else {
			v = vector<vector<int>>(N + 1);
			for (int i = 0; i < M; ++i) {
				int a, b;
				cin >> a >> b;
				v[a].push_back(b);
				v[b].push_back(a);
			}
			for (int i = 1; i <= N; ++i) {
				visited = vector<int>(N + 1);
				visited[i] = 1;
				DFS(i,1);
				visited[i] = 0;
			}
		}
		cout << "#" << tc << " " << res << "\n";
		res = 0;
	}
}