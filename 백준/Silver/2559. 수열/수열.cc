#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	int i, j;
	i = 0;
	j = i + K;

	int sum = 0;
	for (int k = i; k < j; ++k)
		sum += v[k];

	int mx = sum;
	while (j <= N) {
		sum -= v[i];
		i++;
		j++;
		if (j <= N) {
			sum += v[j - 1];
			if (mx < sum)
				mx = sum;
		}
	}
	cout << mx << "\n";
}  