//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

//cout << fixed;
//cout.precision(2);

int main()
{
	string s;
	getline(cin, s);

	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (isalpha(s[i])) {
			unsigned char c = (s[i] + 13);
			if (islower(s[i])) {
				if (c > 'z')
					c = c % 'z' + 'a' - 1;
			}
			else {
				if (c > 'Z')
					c = c % 'Z' + 'A' -1;
			}
			s[i] = c;
		}
	}
	cout << s;
}