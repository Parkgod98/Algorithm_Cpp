#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define INF 999999999
int N, M;
struct Edge {
	int s, e, cost;
	bool operator<(const Edge &other) const {
		if (cost != other.cost)
			return cost < other.cost;
		return s < other.s;
	}
};
vector<Edge> v;
vector<long long> dist;
bool BellmanFord() {
	dist = vector<long long>(N + 1, INF);
	dist[1] = 0;

	for (int i = 1; i <= N - 1; ++i) {

		for (int j = 0; j < M; ++j) {
			int s = v[j].s;
			int e = v[j].e;
			int c = v[j].cost;

			if (dist[s] != INF) {

				if (dist[e] > dist[s] + c)
					dist[e] = dist[s] + c;
			}
		}
	}

	for (int j = 0; j < M; ++j) {
		int s = v[j].s;
		int e = v[j].e;
		int c = v[j].cost;

		if (dist[s] != INF) {

			if (dist[e] > dist[s] + c)
				return false;
		}
	}

	return true;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	if (BellmanFord()) {
		for (int i = 2; i <= N; ++i) {
			if (dist[i] == INF)
				cout << -1 << "\n";
			else
				cout << dist[i] << "\n";
		}
	}
	else
		cout << -1 << "\n";
}
