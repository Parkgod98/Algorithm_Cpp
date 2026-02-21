#include <iostream>
using namespace std;

long long N, M, K;
long long arr[1000005], tree[1000005];

void update(int idx, long long val) {

	while (idx < 1000005) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

long long query(int idx) {
	long long sum = 0;

	while (idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

int main(void) {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		update(i, arr[i]);
	}

	for (int i = 0; i < M + K; ++i) {
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(b, -arr[b]);
			update(b, c);
			arr[b] = c;
		}
		else if (a == 2) {
			cout << query(c) - query(b-1) << "\n";
		}
	}
}