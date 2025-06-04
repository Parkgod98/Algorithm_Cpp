#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v(N+1);
	for (int i = 1; i <= N; ++i) {
		cin >> v[i];
	}

	vector<int> p_sum(N + 1);
	for (int i = 1; i <= N; ++i) {
		p_sum[i] = p_sum[i - 1] + v[i];
	}

	int cnt = 0;
	for (int i = 0; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (p_sum[j] - p_sum[i] == M)
				++cnt;
		}
	}
	cout << cnt << "\n";
}
