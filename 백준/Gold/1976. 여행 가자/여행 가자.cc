#include <iostream>
#include <vector>
using namespace std;
int N, M;

vector<vector<int>> v;
vector<int> parent;
vector<int> tar;

int find_parent(int cur) {
	if (cur != parent[cur])
		return parent[cur] = find_parent(parent[cur]);
	return cur;
}

void Union_parent(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);

	if (pa == pb)
		return;
	if (pa < pb)
		parent[pb] = pa;
	else
		parent[pa] = pb;

	return;
}

int main() {
	cin >> N >> M;
	v = vector<vector<int>>(N,vector<int>(N));
	parent = vector<int>(N);
	for (int i = 0; i < N; ++i)
		parent[i] = i;
	tar = vector<int>(M);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int k;
			cin >> k;
			if (k == 1) {
				Union_parent(i, j);
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		int k;
		cin >> k;
		tar[i] = k - 1;
	}

	bool IsOkay = true;

	int root = -1;
	for (int i = 0; i < M; ++i) {
		if (i == 0) {
			root = find_parent(tar[i]);
		}
		else {
			if (root != find_parent(tar[i])) {
				IsOkay = false;
				break;
			}
		}
	}
	if (IsOkay)
		cout << "YES\n";
	else
		cout << "NO\n";
}