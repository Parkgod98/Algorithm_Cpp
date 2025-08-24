#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		cout << "#" << tc << " ";
		priority_queue<int> pq;

		int cmd;
		for (int i = 0; i < N; ++i) {
			cin >> cmd;
			if (cmd == 1) {
				int x;
				cin >> x;
				pq.push(x);
			}
			else {
				if (pq.empty())
					cout << -1 << " ";
				else {
					cout << pq.top() << " ";
					pq.pop();
				}
			}
		}
		cout << "\n";
	}
}
