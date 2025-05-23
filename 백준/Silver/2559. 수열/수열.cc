#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;


int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v(N+1);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];

	vector<int> prefix_sum(N + 1);
	prefix_sum[1] = v[1];

	for (int i = 2; i <= N; ++i) {
		prefix_sum[i] = prefix_sum[i - 1] + v[i];
	}
	
	int mx = prefix_sum[0 + K] - prefix_sum[0];
	for (int i = 0; i <= N-K; ++i) {
		if (prefix_sum[i + K] - prefix_sum[i] > mx) {
			mx = prefix_sum[i + K] - prefix_sum[i];
		}
	}
	cout << mx << "\n";

}	