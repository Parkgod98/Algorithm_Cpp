#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	priority_queue<int> pq;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
				cout << 0 << "\n";
		}
		else
			pq.push(x);
	}
}  