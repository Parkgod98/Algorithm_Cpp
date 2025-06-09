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

		vector<int> v(11);
		queue<pair<int,int>> q;
		for (int i = 0; i < N; ++i) {
			int n;
			cin >> n;
			q.push({ n,i });
			v[n]++;
		}

		int cnt = 0;
		while (!q.empty()) {
			bool IsOkay = true;
			for (int i = q.front().first+1; i <= 10; ++i){
				if (v[i]) {
					IsOkay = false;
					break;
				}
			}

			if (IsOkay) {
				++cnt;
				if (q.front().second == M) {
					cout << cnt << "\n";
					break;
				}
				else {
					v[q.front().first]--;
					q.pop();
				}
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
}