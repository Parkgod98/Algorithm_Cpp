#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int N, M;
vector<int> v;
vector<int> visited;

void DFS(int depth) {
	if (depth == M) {
		for (int &u : v)
			cout << u << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			v.push_back(i);
			visited[i] = 1;
			DFS(depth + 1);
			v.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;

	visited = vector<int>(N+1);
	DFS(0);
}