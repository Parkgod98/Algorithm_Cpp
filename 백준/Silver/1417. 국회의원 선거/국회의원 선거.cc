#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	int me;
	cin >> me;

	priority_queue<int> pq;
	for (int i = 1; i < N; ++i) {
		int n;
		cin >> n;
		pq.push(n);
	}

	int cnt = 0;
	while (!pq.empty() && me <= pq.top()) {
		int n = pq.top();
		pq.pop();
		n--;
		me++;
		++cnt;
		pq.push(n);
	}
	cout << cnt;
}