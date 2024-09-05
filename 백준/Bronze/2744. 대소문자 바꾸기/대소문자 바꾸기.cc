//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;
	
	cin >> s;

	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (islower(s[i]))
			s[i] = toupper(s[i]);
		else
			s[i] = tolower(s[i]);
	}
	cout << s << "\n";
}