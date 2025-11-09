#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int N;
struct Edge {
	int cur;
	int nxt;
	double cost;

	bool operator<(const Edge &other) const {
		if (cost != other.cost)
			return cost < other.cost;

		if (cur != other.cur)
			return cur < other.cur;
		return nxt < other.nxt;
	}
};

struct Node {
	double x, y;
};

vector<Edge> v;
vector<Node> node;
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

	if (pa < pb)
		parent[pb] = pa;
	else
		parent[pa] = pb;

	return true;
}

int main()
{
	cin >> N;

	node = vector<Node>(N + 1);
	parent = vector<int>(N + 1);
	for (int i = 1; i <= N; ++i) {
		double a, b;
		cin >> a >> b;
		node[i] = { a,b };
		parent[i] = i;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			double dist = sqrt(pow(node[i].x - node[j].x, 2) + pow(node[i].y - node[j].y, 2));
			v.push_back({ i,j,dist });
		}
	}
	sort(v.begin(), v.end());

	int sz = v.size();
	double res = 0;
	int cnt = 0;
	for (int i = 0; i < sz; ++i) {
		auto &it = v[i];

		int cur = it.cur;
		int nxt = it.nxt;
		double cost = it.cost;
		if (union_parent(cur, nxt)) {
			++cnt;
			res += cost;
		}

		if (cnt == N - 1)
			break;
	}


	cout << fixed;
	cout.precision(2);
	cout << res << "\n";
}