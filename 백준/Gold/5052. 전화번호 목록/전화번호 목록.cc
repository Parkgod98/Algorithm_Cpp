#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;


int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;
		vector<string> v(n);

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		map<string, bool> mp;

		sort(v.begin(), v.end());
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			string tmp = "";

			string &s = v[i];

			for (int j = 0; j < s.size() - 1; ++j) {
				tmp += s[j];
				if (mp.find(tmp) != mp.end()) {
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			mp[s] = 1;
		}
		if (flag)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";

	}
}