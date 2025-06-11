#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
int N,M;

vector<int> v;
vector<int> v2;
vector<int> visited;

void DFS(int depth) {
	if (depth == M) {
		for (int &i : v2) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			v2.push_back(i);
			visited[i] = 1;
			DFS(depth + 1);
			visited[i] = 0;
			v2.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;
	v = vector<int>(N);
	visited = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	DFS(0);
}  