#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;

int cnt;
vector<vector<int>> v;
vector<bool> visited;

void DFS(int n) {
	++cnt;
	visited[n] = 1;
	for (int &i : v[n]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<int>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	vector<int> ans;
	int mx = 0;
	for (int i = 1; i <= N; ++i) {
		visited = vector<bool>(N + 1);

		DFS(i);
		if (mx < cnt) {
			ans.clear();
			mx = cnt;
			ans.push_back(i);
		}
		else if (mx == cnt) {
			ans.push_back(i);
		}
		cnt = 0;
	}

	for (int &i : ans)
		cout << i << " ";
}