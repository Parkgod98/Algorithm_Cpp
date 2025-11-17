#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;
int N, M, R;
#define INF 2000000000

vector<int> item;
struct Edge {
	int nxt;
	int cost;

	bool operator<(const Edge &other) const {
		if (cost != other.cost)
			return cost > other.cost;
		return nxt < other.nxt;
	}
};
vector<vector<Edge>> edge;

vector<int> distra(int start) {
	priority_queue<Edge> pq;
	pq.push({ start,0 });
	vector<int> dist(N + 1, INF);
	dist[start] = 0;

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();

		int cur = it.nxt;
		int cur_cost = it.cost;

		if (cur_cost > dist[cur])
			continue;

		for (auto &iit : edge[cur]) {
			int nxt = iit.nxt;
			int cost = iit.cost;

			if (cost + cur_cost >= dist[nxt])
				continue;
			pq.push({ nxt,cost + cur_cost });
			dist[nxt] = cost + cur_cost;
		}
	}

	return dist;
}
int main() {
	cin >> N >> M >> R;
	item = vector<int>(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> item[i];

	edge = vector<vector<Edge>>(N + 1);
	for (int i = 0; i < R; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}

	int mx = 0;
	for (int i = 1; i <= N; ++i) {
		vector<int> dist = distra(i);

		int cur = 0;
		for (int j = 1; j <= N; ++j) {
			if (dist[j] <= M) {
				cur += item[j];
			}
		}

		mx = max(mx, cur);
	}
	cout << mx << "\n";

}