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
	vector<long long> v(91);

	v[1] = 1;
	v[2] = 1;

	for (int i = 3; i <= N; ++i) {
		v[i] = v[i - 1] + v[i - 2];
	}

	cout << v[N] << "\n";
}