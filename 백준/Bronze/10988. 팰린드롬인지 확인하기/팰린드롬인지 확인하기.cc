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
	string s,s1;
	cin >> s;
	s1 = s;
	reverse(s.begin(), s.end());

	if (s1 == s)
		cout << 1;
	else
		cout << 0;
}