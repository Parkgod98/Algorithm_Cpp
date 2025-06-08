#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> v(1001);
	v[1] = 1;
	v[2] = 3;
	v[3] = 5;
	v[4] = 11;
	for (int i = 5; i <= 1000; ++i) {
		if (i % 2 == 1) {
			v[i] = v[i - 1] * 2 - 1;
		}
		else
			v[i] = v[i - 1] * 2 + 1;
		v[i] %= 10007;
	}
	cout << v[n] << "\n";
}