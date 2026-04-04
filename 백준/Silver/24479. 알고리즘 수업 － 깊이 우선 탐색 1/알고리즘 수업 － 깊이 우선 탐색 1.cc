#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> v[100002];
int visited[100002];
int cnt = 1;
void DFS(int cur) {
	visited[cur] = cnt++;
	for (int &n : v[cur]) {
		if (!visited[n]) {
			DFS(n);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> R;


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
		cout << visited[i] << "\n";
	}
}