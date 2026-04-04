#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
int visited[100002];
int parent[100002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;

	queue<int> q;
	q.push(N);
	visited[N] = 1;

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		if (n == K) {
			cout << visited[K] - 1 << "\n";
			break;
		}

		if (n - 1 >= 0 && visited[n - 1] == 0) {
			q.push(n - 1);
			visited[n - 1] = visited[n] + 1;
			parent[n - 1] = n;
		}
		if (n + 1 <= 100000 && visited[n + 1] == 0) {
			q.push(n + 1);
			visited[n + 1] = visited[n] + 1;
			parent[n + 1] = n;

		}
		if (n * 2 <= 100000 && visited[n * 2] == 0) {
			q.push(n * 2);
			visited[n * 2] = visited[n] + 1;
			parent[n * 2] = n;

		}
	}

	vector<int> res;
	int cur = K;
	while(1){
		res.push_back(cur);
		if (cur == N)
			break;
		cur = parent[cur];
	}

	for (int i = res.size() - 1; i >= 0; --i) {
		cout << res[i] << " ";
	}
	cout << "\n";
}