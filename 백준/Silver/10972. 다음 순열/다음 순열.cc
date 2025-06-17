#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	if (next_permutation(v.begin(), v.end())) {
		for (int &i : v)
			cout << i << " ";
	}
	else
		cout << -1 << "\n";
}  