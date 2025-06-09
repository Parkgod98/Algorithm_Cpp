#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, M;
		cin >> N >> M;

		queue<pair<int,int>> q;
		priority_queue<pair<int, int>> pq;

		for (int i = 0; i < N; ++i) {
			int n;
			cin >> n;
			q.push({ n,-i });
			pq.push({ n,-i });
		}

		int cnt = 0;
		while (!pq.empty()) {
			if (pq.top().first == q.front().first) {
				++cnt;
				if (-q.front().second == M) {
					cout << cnt << "\n";
					break;
				}
				else {
					pq.pop();
					q.pop();
				}
			}
			else {
				pair<int, int> p = q.front();
				q.pop();
				q.push(p);
			}
		}
	}
}