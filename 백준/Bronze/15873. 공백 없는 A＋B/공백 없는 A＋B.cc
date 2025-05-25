#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	int res = 0;
	if (s.size() == 2) {
		res = (s[0] - '0') + (s[1] - '0');
	}
	else if (s.size() == 4)
		res = 20;
	else {
		if (s[1] == '0')
			res = 10 + (s[2] - '0');
		else {
			res = (s[0] - '0') + 10;
		}
	}

	cout << res << "\n";
}