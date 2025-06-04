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

	int i, j;
	i = 0;
	j = 1;
	int sum = v[j];
	int cnt = 0;

	while (j <= N) {
		if (sum == M) {
			sum -= v[i];
			i++;
			j++;
			if (j <= N)
				sum += v[j];
			++cnt;
		}
		else if (sum < M) {
			j++;
			if (j <= N)
				sum += v[j];
		}
		else if (sum > M) {
			sum -= v[i];
			i++;
		}
	}
	cout << cnt << "\n";
}
