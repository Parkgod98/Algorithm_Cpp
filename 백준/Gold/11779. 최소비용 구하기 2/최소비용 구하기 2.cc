#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
#define INF 2000000000
struct Edge {
	int nxt;
	int cost;

	bool operator<(const Edge &other) const {
		if (cost != other.cost)
			return cost > other.cost;
		return nxt > other.nxt;
	}
};
priority_queue<Edge> pq;
vector<vector<Edge>> v;
vector<int> prev_node;

vector<int> distra(int start) {
	vector<int> dist(N + 1, INF);
	dist[start] = 0;
	pq.push({ start,0 });

	while (!pq.empty()) {
		auto &it = pq.top();
		int cur = it.nxt;
		int cost = it.cost;
		pq.pop();

		if (cost > dist[cur])
			continue;

		for (auto &iit : v[cur]) {
			int nxt = iit.nxt;
			int nxt_cost = iit.cost;

			if (cost + nxt_cost >= dist[nxt])
				continue;
			pq.push({ nxt,cost + nxt_cost });
			dist[nxt] = cost + nxt_cost;
			prev_node[nxt] = cur;
		}
	}

	return dist;
}

int main()
{
	cin >> N >> M;

	v = vector<vector<Edge>>(N + 1);
	prev_node = vector<int>(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	int start, end;
	cin >> start >> end;

	vector<int> dist = distra(start);

	vector<int> ans;
	
	cout << dist[end] << "\n";
	while (end != 0) {
		ans.push_back(end);
		end = prev_node[end];
	}
	
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int &n : ans)
		cout << n << " ";
	cout << "\n";
}