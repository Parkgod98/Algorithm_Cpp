#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
#define SZ 100001
int s, e;

struct Node {
	int p;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> e;
	vector<int> visited(SZ);
	vector<Node> par(SZ);
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	par[s].p = -1;

	vector<int> res;
	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (n == e) {
			cout << visited[n] - 1 << "\n";
			for (int i = e; i != -1; i = par[i].p)
				res.push_back(i);
			break;
		}

		if (n + 1 <= SZ && !visited[n+1]) {
			q.push(n + 1);
			visited[n + 1] = visited[n] + 1;
			par[n + 1].p = n;
		}
		if (n - 1 >= 0 && !visited[n-1]) {
			q.push(n - 1);
			visited[n - 1] = visited[n] + 1;
			par[n - 1].p = n;
		}
		if (n * 2 <= SZ && !visited[n*2]) {
			q.push(n * 2);
			visited[n * 2] = visited[n] + 1;
			par[n * 2].p = n;
		}
	}

	for (int i = res.size() - 1; i >= 0; --i)
		cout << res[i] << " ";
	cout << "\n";

}