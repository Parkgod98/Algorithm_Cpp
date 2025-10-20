#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define INF 99999999
struct Edge {
	pair<int, int> cur;
	int cost;

	bool operator<(const Edge &other) const {
		if (cost != other.cost)
			return cost > other.cost;
		return cur.first > other.cur.first;
	}
};


int N;
vector<vector<int>> v;
vector<vector<int>> dist;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void distra() {
	priority_queue<Edge> pq;
	pq.push({{ 0,0 }, v[0][0]});
	dist[0][0] = v[0][0];

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();

		int y = it.cur.first;
		int x = it.cur.second;
		int cur_cost = it.cost;

		if (dist[y][x] < cur_cost)
			continue;

		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (v[ny][nx] + cur_cost >= dist[ny][nx])
				continue;

			pq.push({{ ny,nx }, v[ny][nx] + cur_cost});
			dist[ny][nx] = v[ny][nx] + cur_cost;
		}
	}
}

int main() {
	int pb = 1;
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		v = dist = vector<vector<int>>(N, vector<int>(N,INF));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> v[i][j];
			}
		}

		distra();


		cout << "Problem " << pb << ": " << dist[N-1][N-1] << "\n";
		++pb;
	}
}
