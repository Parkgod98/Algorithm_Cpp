#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int V, E;

struct Edge {
	int cost;
	int s, e;

	bool operator<(const Edge &other) {
		return cost < other.cost;
	}
};
vector<Edge> v;
vector<int> parent;

int find(int cur) {
	if (parent[cur] == cur)
		return cur;
	return parent[cur] = find(parent[cur]);
}

void UnionParent(int a, int b) {
	a = find(a);
	b = find(b);
	parent[b] = a;
}

int main() {
	cin >> V >> E;
	v = vector<Edge>(E);
	parent = vector<int>(V + 1);
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v[i] = { c,a,b };
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= V; ++i)
		parent[i] = i;

	long long ans = 0;
	int cnt = 0;
	for (int i = 0; i < E; ++i) {
		Edge cur = v[i];
		int cost = v[i].cost;
		int now = v[i].s;
		int nxt = v[i].e;

		if (find(now) == find(nxt)) // 두 부모가 같다면 싸이클이 생길것.
			continue;

		UnionParent(now, nxt);
		ans += cost;

		++cnt;
		if (cnt == V - 1)
			break;
	}
	cout << ans << "\n";
}
