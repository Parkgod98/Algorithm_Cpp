#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;

	vector<int> v(11);
	v[1] = 1;
	v[2] = 2;
	v[3] = 4;
	for (int i = 4; i <= 10; ++i) {
		v[i] = v[i - 1] + v[i - 2] + v[i - 3];
	}

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;

		cout << v[n] << "\n";
	}
}