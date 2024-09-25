#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int main()
{
	string s;
	cin >> s;

	int len = s.length();
	if (len % 3 == 1)
		s = "00" + s;
	else if (len % 3 == 2)
		s = "0" + s;

	for (int i = 0; i < len; i+=3) {
		int num = ((s[i]-'0') * 4) + ((s[i+1] - '0') * 2) + (s[i+2] - '0');
		cout << num;
	}
	
}
