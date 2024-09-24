#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

bool Check(string s)
{
	int len = s.length();

	for (int i = 0; i < len / 2; ++i) {
		if (s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	while (1) {
		string s;
		cin >> s;
		if (s == "0")
			break;
		if (Check(s))
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
}
