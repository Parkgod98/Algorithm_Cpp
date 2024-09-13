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

int main()
{
	char c, pc;
	pc = ' ';
	string s;
	getline(cin, s);
	
	int len = s.length();
	int count = 0;
	for (int i = 0; i < len; ++i) {
		c = s[i];
		if (isalpha(c) && isspace(pc))
			count++;
		pc = c;
	}
	cout << count << "\n";
}