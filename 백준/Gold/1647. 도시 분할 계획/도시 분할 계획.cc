#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int N, M;
struct Edge {
	int s,e;
	int cost;

	bool operator<(const Edge &other) const {
		if (cost != other.cost)
			return cost < other.cost;
		if (s != other.s)
			return s < other.s;
		return e < other.e;
	}
};
vector<Edge> v;
vector<int> parent;

int find_parent(int cur) {
	if (cur != parent[cur])
		return parent[cur] = find_parent(parent[cur]);
	return cur;
}

bool union_parent(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);

	if (pa == pb)
		return false;

	if (pa > pb)
		parent[pa] = pb;
	else
		parent[pb] = pa;

	return true;
}

int main() {
	cin >> N >> M;
	parent = vector<int>(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
		v.push_back({ b,a,c });
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	int sum = 0;
	//cout << "\n";

	int mx = 0;
	for (int i = 0; i <2* M; ++i) {
		Edge &eg = v[i];
		int s = eg.s;
		int e = eg.e;
		int cost = eg.cost;

		if (union_parent(s, e)) {
			sum += cost;
			mx = max(mx, cost);
			//cout << s << " " << e << " " << cost << "\n";
		}
	}
	/*for (int i = 1; i <= N; ++i)
		cout << parent[i] << " ";
	cout << "\n";*/
	cout << sum - mx<< "\n";
}
