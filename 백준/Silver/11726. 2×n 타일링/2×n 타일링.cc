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

	vector<int> v(1001);
	v[0] = 0;
	v[1] = 1;
	v[2] = 2;
	for (int i = 3; i <= 1000; ++i) {
		v[i] = (v[i - 1] + v[i - 2])%10007;
	}

	cout << v[n];
}