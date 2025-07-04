#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N, M, K, X;
vector<vector<int>> v;
vector<bool> visited;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K >> X;
	v = vector<vector<int>>(N+1);
	visited = vector<bool>(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	queue<pair<int,int>> q;
	q.push({ X,0 });
	visited[X] = true;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	while (!q.empty()) {
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();
		
		if (depth == K) {
			pq.push(cur);
			continue;
		}
		for (int &i : v[cur]) {
			if (!visited[i]) {
				visited[i] = 1;
				q.push({ i,depth+1 });
			}
		}
	}

	if (pq.empty())
		cout << -1 << "\n";
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
}