#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
typedef long long ll;
int main()
{
	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		pq.push(k);
	}

	for (int i = 0; i < m; ++i) {
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();

		ll sum = a + b;
		pq.push(sum);
		pq.push(sum);
	}

	long long sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum << "\n";
}