#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
#define INF 2100000000
int N, E;

struct Edge {
	int e;
	int cost;

	bool operator<(const Edge &other) const {
		if (cost != other.cost)
			return cost > other.cost;

		return e > other.e;
	}
};
vector<vector<Edge>> v;

int e1, e2;

vector<int> distra(int start) {
	priority_queue<Edge> pq;
	vector<int> dist(N+1,INF);
	pq.push({ start,0 });
	dist[start] = 0;

	while (!pq.empty()) {
		int cur = pq.top().e;
		int cost = pq.top().cost;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (auto it : v[cur]) {
			int nxt = it.e;
			int nxt_cost = it.cost;

			if (cost + nxt_cost >= dist[nxt])
				continue;
			pq.push({ nxt,cost + nxt_cost });
			dist[nxt] = cost + nxt_cost;
		}
	}

	return dist;
}
int main() {
	cin >> N >> E;
	v = vector<vector<Edge>>(N + 1);
	for (int i = 0; i < E; ++i) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}

	cin >> e1 >> e2;


	vector<int> d1 = distra(1);
	if (d1[N] == INF || d1[e1] == INF || d1[e2] == INF) {
		cout << -1 << "\n";
		return 0;
	}

	vector<int> d2 = distra(e1);
	vector<int> d3 = distra(e2);
	int res1 = d1[e1] + d2[e2] + d3[N];
	int res2 = d1[e2] + d3[e1] + d2[N];
	int res = min(res1, res2);
	

	cout << res << "\n";
}