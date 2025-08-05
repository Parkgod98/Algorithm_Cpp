#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int N, S;
#define INF 10000002

vector<long long> p_sum;
int main() {
	cin >> N >> S;
	p_sum = vector<long long>(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> p_sum[i];
	}
	for (int i = 1; i <= N; ++i) {
		p_sum[i] += p_sum[i - 1];
	}

	int s, e;
	s = e = 0;
	int min_length = INF;
	while (e <= N && s <= e) {
		long long sum = p_sum[e] - p_sum[s];
		if (sum < S) {
			e++;
		}
		else {
			min_length = min(e-s, min_length);
			s++;
		}
	}

	if (min_length == INF)
		cout << 0 << "\n";
	else
		cout << min_length << "\n";
}
