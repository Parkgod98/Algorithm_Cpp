#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int N, M;

int main() {

	int T;
	cin >> T;

	vector<long long> v(101);
	v[1] = v[2] = v[3] = 1;
	v[4] = v[5] = 2;
	v[6] = 3;
	for (int i = 7; i <= 100; ++i) {
		v[i] = v[i - 2] + v[i - 3];
	}

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;
		cout << v[N] << "\n";
	}
}