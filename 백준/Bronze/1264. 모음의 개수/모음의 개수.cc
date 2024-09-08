//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	while (1) {
		string s;
		getline(cin, s);
		if (s == "#")
			break;
		int len = s.length();
		int sum = 0;
		for (int i = 0; i < len; ++i) {
			char c = tolower(s[i]);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				sum += 1;
		}
		cout << sum << "\n";
	}
}
