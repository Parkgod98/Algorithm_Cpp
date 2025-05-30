#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	string s;
	cin >> s;

	int res = 10;
	char prev = s[0];
	for (int i = 1; i < s.size(); ++i) {
		if (prev == s[i]) {
			res += 5;
		}
		else
			res += 10;
		prev = s[i];
	}

	cout << res << "\n";
}