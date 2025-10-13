#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int N, M;
int true_num;
map<int,bool> t_man;
vector<vector<int>> party;
vector<int> parent;

int FindParent(int cur) {
	if (parent[cur] != cur) {
		return parent[cur] = FindParent(parent[cur]);
	}
	return cur;
}

void UnionParent(int a, int b) {
	int pa = FindParent(a);
	int pb = FindParent(b);

	if (pa == pb)
		return;

	if (pa > pb)
		parent[pa] = pb;
	else
		parent[pb] = pa;
}

int main() {
	cin >> N >> M;
	cin >> true_num;
	parent = vector<int>(N + 1);
	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	for (int i = 0; i < true_num; ++i) {
		int k;
		cin >> k;
		t_man[k] = 1;
	}
	
	party = vector<vector<int>>(M);
	for (int i = 0; i < M; ++i) {
		int n;
		cin >> n;
		party[i] = vector<int>(n);
		for (int j = 0; j < n; ++j)
			cin >> party[i][j];

		for (int a = 0; a < n; ++a) {
			for (int b = a + 1; b < n; ++b)
				UnionParent(party[i][a], party[i][b]);
		}
	}

	for (int i = 1; i <= N; ++i)
		FindParent(i);
	map<int, bool> new_t_man;
	for (auto &it : t_man) {
		new_t_man[it.first] = 1;
		new_t_man[parent[it.first]] = 1;
	}

	int res = 0;
	for (int i = 0; i < M; ++i) {
		int sz = party[i].size();

		bool Can = true;
		for (int j = 0; j < sz; ++j) {
			if (new_t_man.find(parent[party[i][j]]) != new_t_man.end()) {
				Can = false;
				break;
			}
		}
		if (Can)
			++res;
	}
	cout << res << "\n";
}
