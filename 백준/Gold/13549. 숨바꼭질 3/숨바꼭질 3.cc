#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0};
int dx[4] = { 0,1,0,-1};
#define SZ 100001
#define INF 10000000
vector<int> visited(SZ, INF);
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int s, e;
	cin >> s >> e;

	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		if (n == e) {
			cout << visited[n] -1 << "\n";
			break;
		}

		if (n * 2 <= SZ && visited[n * 2] == INF) {
			q.push(n * 2);
			visited[n * 2] = min(visited[n * 2], visited[n]);
		}
		if (n - 1 >= 0 && visited[n - 1] == INF) {
			q.push(n - 1);
			visited[n - 1] = min(visited[n-1],visited[n] + 1);
		}
		if (n + 1 <= SZ && visited[n + 1] == INF) {
			q.push(n + 1);
			visited[n + 1] = min(visited[n+1], visited[n] + 1);
		}

	}
}