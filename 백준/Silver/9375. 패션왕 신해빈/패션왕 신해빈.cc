#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

int main() {
	int T;
	cin >> T;

	
	for (int tc = 1; tc <= T; ++tc) {
		int k;
		cin >> k;

		map<string, int> mp;
		for (int i = 0; i < k; ++i) {
			string a, b;
			cin >> a >> b;
			mp[b]++;
		}
		long long n = 1;
		for (auto &it : mp) {
			n *= (it.second+1);
		}
		cout << n - 1 << "\n";
	}
}  