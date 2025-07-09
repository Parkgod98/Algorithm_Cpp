#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> v;
vector<vector<int>> ans;

void DFS(int start, int cur, vector<int> &visited) {
	for (int i = 0; i < N; ++i) {
		if (v[cur][i] == 1) {
			ans[start][i] = 1;
			if (!visited[i]) {
				visited[i] = 1;
				DFS(start, i, visited);
			}
		}
	}
}

int main()
{
	cin >> N;

	v = vector<vector<int>>(N, vector<int>(N));
	ans = v;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		vector<int> visited(N);
		DFS(i,i,visited);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
}