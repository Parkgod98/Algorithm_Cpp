#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int common = 0;
	set<int> s;
	for (int i = 0; i < a + b; ++i) {
		int n;
		cin >> n;

		int prev_sz = s.size();
		s.insert(n);
		int cur_sz = s.size();
		if (prev_sz == cur_sz) {
			++common;
		}
	}

	int res = (a + b) - 2 * common;
	cout << res << "\n";
}
