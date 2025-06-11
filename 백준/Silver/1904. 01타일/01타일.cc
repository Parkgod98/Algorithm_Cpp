#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
int N;

int main() {
	cin >> N;
	vector<long long> v(N+3);

	v[1] = 1;
	v[2] = 2;

	for (int i = 3; i <= N; ++i) {
		v[i] = (v[i - 1] + v[i - 2])%15746;
	}

	cout << v[N] << "\n";
}  