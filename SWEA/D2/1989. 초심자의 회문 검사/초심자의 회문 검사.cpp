#include <iostream>
#include <string>
using namespace std;

bool IsOkay(string &s) {
	int len = s.length();
	for (int i = 0; i < len / 2; ++i) {
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		string s;
		cin >> s;

		int res = 0;
		if (IsOkay(s))
			res = 1;

		cout << "#" << tc << " " << res << "\n";
	}
}