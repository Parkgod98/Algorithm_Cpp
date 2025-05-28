#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;

int recursion(string &s, int f, int e) {
	cnt++;
	if (f >= e) {
		return 1;
	}
	else if (s[f] != s[e])
		return 0;
	else {
		return recursion(s, f + 1, e - 1);
	}
}

int IsPalindrome(string &s) {
	return recursion(s, 0, s.size() - 1);
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string s;
		cin >> s;

		int idx;
		cnt = 0;
		idx = IsPalindrome(s);

		cout << idx << " " << cnt << "\n";
	}
}