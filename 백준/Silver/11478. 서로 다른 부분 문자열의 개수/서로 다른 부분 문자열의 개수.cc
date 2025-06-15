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
	string s;
	cin >> s;

	map<string, bool> mp;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 1; j <= s.size(); ++j) {
			mp[s.substr(i, j)] = true;
		}
	}
	cout << mp.size() << "\n";
}  