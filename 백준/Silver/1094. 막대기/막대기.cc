#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;

int main() {
	int X;
	cin >> X;
	if (X == 64) {
		cout << 1 << "\n";
		return 0;
	}

	vector<int> v(1, 64);
	int idx = 0;
	while (1) {
		int small_idx = v.size() - 1;
		v[small_idx] /= 2;
		v.push_back(v[small_idx]);

		int sum = 0;
		for (int i = 0; i < v.size() - 1; ++i)
			sum += v[i];
		if (sum > X) {
			v.pop_back();
		}
		else if (sum == X) {
			v.pop_back();
			cout << v.size() << "\n";
			break;
		}
	}
}