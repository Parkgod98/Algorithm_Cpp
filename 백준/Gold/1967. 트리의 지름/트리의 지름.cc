#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
#define INF 999999999
int n;
struct Edge {
	int e, cost;
	bool operator<(const Edge& other) const {
		if (cost != other.cost)
			return cost > other.cost;
		return e > other.e;
	}
};
vector<vector<Edge>> v;

vector<int> distra(int start) {
	priority_queue<Edge>pq;
	pq.push({ start,0 });
	vector<int> dist(n + 1, INF);
	dist[start] = 0;

	while (!pq.empty()) {
		int cur = pq.top().e;
		int cost = pq.top().cost;
		pq.pop();

		if (cost > dist[cur])
			continue;

		for (auto &it : v[cur]) {
			int nxt = it.e;
			int n_cost = it.cost;

			if (n_cost + cost >= dist[nxt])
				continue;
			pq.push({ nxt,n_cost + cost });
			dist[nxt] = n_cost + cost;
		}
	}
	
	return dist;
}

int main() {
	cin >> n;
	v = vector<vector<Edge>>(n + 1);
	for (int i = 1; i <= n-1; ++i) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}

	vector<int> d1 = distra(1);
	int node = 0;
	int len1 = 0;
	for (int i = 1; i <= n; ++i) {
		if (d1[i] != INF && len1 < d1[i]) {
			len1 = d1[i];
			node = i;
		}
	}

	vector<int> d2 = distra(node);
	int len2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (d2[i] != INF && len2 < d2[i]) {
			len2 = d2[i];
		}
	}
	cout << len2 << "\n";


}