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

	int s, e;
	e = 1;
	s = 1;
	long long sum = 0;
	int min_length = INF;
	while (e <= N && s <= e) {
		if (sum < S) {
			sum += p_sum[e];
			e++;
		}
		while(sum >=S) {
			min_length = min(e-s, min_length);
			sum -= p_sum[s];
			s++;
		}
	}

	if (min_length == INF)
		cout << 0 << "\n";
	else
		cout << min_length << "\n";
}
