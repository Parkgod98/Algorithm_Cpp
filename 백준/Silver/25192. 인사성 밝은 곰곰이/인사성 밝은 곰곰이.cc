#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt = 0;
	map<string, bool> mp;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		if (s == "ENTER") {
			mp.clear();
		}
		else {
			if (mp.find(s) == mp.end()) {
				mp[s] = true;
				++cnt;
			}
		}
	}

	cout << cnt << "\n";
}