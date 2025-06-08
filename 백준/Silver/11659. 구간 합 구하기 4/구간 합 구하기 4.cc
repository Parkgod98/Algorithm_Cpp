#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int N, M;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<int> v(N+1);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];

	vector<int> p_sum(N + 1);
	for (int i = 1; i <= N; ++i) {
		p_sum[i] = p_sum[i - 1] + v[i];
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		cout << p_sum[b] - p_sum[a - 1] << "\n";
	}
}