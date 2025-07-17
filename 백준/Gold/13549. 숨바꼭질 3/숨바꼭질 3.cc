#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int N, K;
#define INF 2000000
int main() {
	cin >> N >> K;

	queue<int> q;
	q.push(N);
	vector<int> visited(100001,2000000);
	visited[N] = 1;

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (n == K) {
			cout << visited[n] - 1 << "\n";
			break;
		}

		if (n * 2 <= 100000 && visited[n * 2] == INF) {
			q.push(n * 2);
			visited[n * 2] = min(visited[n * 2], visited[n]);
		}
		if (n - 1 >= 0 && visited[n - 1] == INF) {
			q.push(n - 1);
			visited[n - 1] = min(visited[n - 1], visited[n] + 1);
		}
		if (n + 1 <= 100000 && visited[n + 1] == INF) {
			q.push(n + 1);
			visited[n + 1] = min(visited[n + 1], visited[n] + 1);
		}
	}
}