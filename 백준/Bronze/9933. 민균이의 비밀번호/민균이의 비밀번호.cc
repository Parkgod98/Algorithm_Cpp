#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, bool> mp;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		mp[s] = true;
	}

	for (auto &it : mp) {
		string s = it.first;
		reverse(s.begin(), s.end());
		if (mp.find(s) != mp.end()) {
			cout << s.size() << " " << s[s.size() / 2];
			return 0;
		}
	}
}