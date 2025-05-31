#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		map<char, int> mp1,mp2;
		string a, b;
		cin >> a >> b;

		for (int i = 0; i < a.size(); ++i) {
			mp1[a[i]]++;
		}
		for (int j = 0; j < b.size(); ++j) {
			mp2[b[j]]++;
		}

		if (mp1.size() != mp2.size()) {
			cout << a << " & " << b << " are NOT anagrams." << "\n";
		}
		else {
			bool flag = false;
			for (auto &it : mp1) {
				if (mp1[it.first] != mp2[it.first]) {
					cout << a << " & " << b << " are NOT anagrams." << "\n";
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << a << " & " << b << " are anagrams." << "\n";
			}

		}

	}
}