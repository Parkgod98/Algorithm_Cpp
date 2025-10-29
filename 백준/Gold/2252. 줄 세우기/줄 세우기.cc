#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int N, M;
vector<vector<int>> v;
vector<int> indegree;

void topology_sort() {
	queue<int> q;

	for (int i = 1; i <= N; ++i) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		cout << it << " ";

		for (int &n : v[it]) {
			indegree[n]--;
			if (indegree[n] == 0)
				q.push(n);
		}
	}
}
int main() {
	cin >> N >> M;
	v = vector<vector<int>>(N + 1);
	indegree = vector<int>(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		++indegree[b];
	}

	topology_sort();
	cout << "\n";
}
