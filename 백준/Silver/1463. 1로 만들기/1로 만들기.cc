#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
	int X;
	cin >> X;

	vector<int> v(X + 1, X+1);
	v[X] = 0;
	for (int i = X; i >= 1; --i) {
		if (i % 3 == 0) {
			v[i / 3] = min(v[i] + 1,v[i/3]);
		}
		if (i % 2 == 0) {
			v[i / 2] = min(v[i] + 1, v[i/2]);
		}
		v[i - 1] = min(v[i] + 1, v[i-1]);
	}
	cout << v[1] << "\n";
}