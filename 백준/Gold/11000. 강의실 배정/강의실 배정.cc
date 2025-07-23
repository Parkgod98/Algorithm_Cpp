#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
int N,cnt;

int main() {
	cin >> N;
	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; ++i) {
		int s, t;
		cin >> s >> t;
		v[i] = { s,t };
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	sort(v.begin(), v.end());

	pq.push(v[0].second);
	for (int i = 1; i < N; ++i) {
		if (v[i].first >= pq.top()) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
		}
	}

	cout << pq.size() << "\n";
}