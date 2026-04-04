#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> v[100002];
int visited[100002];
int order[100002];
int target[100002];
int N;
int cnt = 1;
vector<int> act;
bool cmp(int a, int b) {
	return order[a] < order[b];
}

void DFS(int cur) {
	visited[cur] = cnt++;
	act.push_back(cur);

	for (int &n : v[cur]) {
		if (!visited[n]) {
			DFS(n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; ++i) {
		cin >> target[i];
		order[target[i]] = i;
	}
	for (int i = 1; i <= N; ++i) {
		sort(v[i].begin(), v[i].end(), cmp);
	}

	DFS(1);

	for (int i = 0; i < N; ++i) {
		if (act[i] != target[i]) {
			cout << 0 << "\n";
			return 0;
		}
	}

	cout << 1 << "\n";
}