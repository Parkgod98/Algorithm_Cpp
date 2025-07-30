#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define INF 99999999
int V, E, K;
vector<int> dist;

int main() {
	cin >> V >> E;
	vector<vector<pair<int,int>>> v(V + 1);
	dist = vector<int>(V + 1, INF);

	cin >> K;
	for (int i = 0; i < E; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ b,w });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0,K });
	dist[K] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (auto it : v[cur]) {
			int nxt = it.first;
			int nxt_cost = cost + it.second;
			if (nxt_cost < dist[nxt]) {
				dist[nxt] = nxt_cost;
				pq.push({ nxt_cost,nxt });
			}
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (dist[i] != INF)
			cout << dist[i];
		else
			cout << "INF";
		cout << "\n";
	}
}