#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
int main() {
	cin >> N;
	priority_queue<long long, vector<long long>, greater<>> pq;

	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		pq.push(n);
	}

	long long a, b;
	a = b = 0;
	long long res = 0;
	while (!pq.empty()) {
		a = pq.top();
		pq.pop();
		if (pq.empty()) {
			cout << 0 << "\n";
			return 0;
		}
		b = pq.top();
		pq.pop();
		pq.push(a + b);
		res += (a + b);
		if (pq.size() == 1)
			break;
	}

	cout << res << "\n";
}