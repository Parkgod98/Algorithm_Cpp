#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N, M;
#define INF 100000000
int main() {
	cin >> N >> M;

	vector<vector<pair<int, int>>> v(N + 1);
	for (int i = 0; i < M; ++i) {
		int s, e, cost;
		cin >> s >> e >> cost;
		v[s].push_back({ cost,e });
	}

	int start, end;
	cin >> start >> end;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({ 0,start });

	vector<int> dist(N + 1,INF);
	dist[start] = 0;

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int cur = it.second;
		int cost = it.first;

		if (cost > dist[cur])
			continue;


		for (auto &p : v[cur]) {
			int nxt_cost = cost + p.first;
			if (nxt_cost < dist[p.second]) {
				dist[p.second] = nxt_cost;
				pq.push({ nxt_cost,p.second });
			}
		}
	}

	cout << dist[end] << "\n";

}
