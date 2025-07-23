#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

int N, M;
vector<vector<int>> v;
vector<bool> visited;
bool Okay = false;
void DFS(int cur,int cnt) {
	if (cnt == 5 || Okay) {
		Okay = true;
		return;
	}


	for (int &n : v[cur]) {
		if (!visited[n]) {
			visited[n] = true;
			DFS(n,cnt+1);
			visited[n] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	v = vector<vector<int>>(N);
	visited = vector<bool>(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; ++i) {
		visited[i] = true;
		DFS(i,1);
		visited[i] = false;
	}

	if (Okay)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}