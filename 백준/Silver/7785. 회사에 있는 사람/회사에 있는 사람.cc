#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<string, bool> mp;
	for (int i = 0; i < n; ++i) {
		string name, com;
		cin >> name >> com;
		if (com == "enter") {
			mp[name] = true;
		}
		else if (com == "leave")
			mp[name] = false;
	}

	for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
		if (it->second)
			cout << it->first << "\n";
	}
}