#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string s;
		cin >> s;

		int res = (s[0] - '0') + (s[2] - '0');
		cout << res << "\n";
	}
}