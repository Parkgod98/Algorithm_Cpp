#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define INF 999999999


int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int k;
		cin >> k;

		priority_queue<int> pq;
		priority_queue<int, vector<int>, greater<int>> pq2;
		map<int, int> mp;
		for (int i = 0; i < k; ++i) {
			char com;
			int n;
			cin >> com >> n;
			
			if (com == 'I') {
				pq.push(n);
				pq2.push(n);
				mp[n]++;
			}
			else if (com == 'D') {
				while (!pq.empty() && mp[pq.top()] <= 0) {
					pq.pop();
				}
				while (!pq2.empty() && mp[pq2.top()] <= 0) {
					pq2.pop();
				}
				if (n == 1) {
					while (!pq.empty() && mp[pq.top()] <= 0) {
						pq.pop();
					}
					if (!pq.empty() && mp[pq.top()] > 0) {
						mp[pq.top()]--;
						pq.pop();
					}
				}
				else {
					while (!pq2.empty() && mp[pq2.top()] <= 0) {
						pq2.pop();
					}
					if (!pq2.empty() && mp[pq2.top()] > 0) {
						mp[pq2.top()]--;
						pq2.pop();
					}
				}
			}


		}
		while (!pq.empty() && mp[pq.top()] <= 0) {
			pq.pop();
		}
		while (!pq2.empty() && mp[pq2.top()] <= 0) {
			pq2.pop();
		}
		if (pq.empty()) {
			cout << "EMPTY\n";
		}
		else {
			int mn, mx;
			if (!pq.empty()) {
				mx = pq.top();
			}
			while (!pq.empty()) {
				if(mp[pq.top()] > 0)
					mn = pq.top();
				pq.pop();
			}

			cout << mx << " " << mn << "\n";
		}
	}
}
