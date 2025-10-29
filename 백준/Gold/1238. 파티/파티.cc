#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define INF 999999999
struct Edge {
	int nxt;
	int cost;

	bool operator<(const Edge &other) const {
		if (cost != other.cost)
			return cost > other.cost;
	}
};
int N, M, X;
vector<vector<Edge>> v, v2;

vector<int> distra(int start) {
	priority_queue<Edge> pq;
	vector<int> dist(N + 1, INF);

	pq.push({ start,0 });
	dist[start] = 0;

	while (!pq.empty()) {
		auto it = pq.top();
		int cur = it.nxt;
		int cost = it.cost;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (auto iit : v[cur]) {
			int nxt = iit.nxt;
			int nxt_cost = iit.cost;

			if (cost + nxt_cost >= dist[nxt])
				continue;
			pq.push({ nxt,cost + nxt_cost });
			dist[nxt] = cost + nxt_cost;
		}
	}

	return dist;
}

vector<int> distra2(int start) {
	priority_queue<Edge> pq;
	vector<int> dist(N + 1, INF);

	pq.push({ start,0 });
	dist[start] = 0;

	while (!pq.empty()) {
		auto it = pq.top();
		int cur = it.nxt;
		int cost = it.cost;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (auto iit : v2[cur]) {
			int nxt = iit.nxt;
			int nxt_cost = iit.cost;

			if (cost + nxt_cost >= dist[nxt])
				continue;
			pq.push({ nxt,cost + nxt_cost });
			dist[nxt] = cost + nxt_cost;
		}
	}

	return dist;
}

int main() {
	cin >> N >> M >> X;
	v = v2 = vector<vector<Edge>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v2[b].push_back({ a,c });
	}

	vector<int> x_dist = distra(X);
	vector<int> x_dist2 = distra2(X);
	int mx = 0;
	for (int i = 1; i <= N; ++i) {
		if (i == X)
			continue;
		if (mx < x_dist[i] + x_dist2[i])
			mx = x_dist[i] + x_dist2[i];
	}
	cout << mx << "\n";


}
