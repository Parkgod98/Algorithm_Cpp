#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> dist(N-1);
	for (int i = 0; i < N - 1; ++i) {
		cin >> dist[i];
	}
	vector<long long> price(N);
	for (int i = 0; i < N; ++i)
		cin >> price[i];

	long long cost = 0;
	int i = 0;
	while(i < N) {
		int j = i+1;
		while (j < N && price[i] <= price[j]) {
			++j;
		}

		long long cur_dist = 0;
		for (int k = i; k < N-1 && k < j; ++k) {
			cur_dist += dist[k];
		}
		cost += cur_dist * price[i];
		i = j;
	}
	cout << cost << "\n";
}  