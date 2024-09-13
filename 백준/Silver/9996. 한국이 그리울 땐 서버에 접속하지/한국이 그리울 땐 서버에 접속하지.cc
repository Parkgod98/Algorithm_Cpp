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
	int n;
	string pattern;
	cin >> n >> pattern;

	int i = pattern.find("*");
	string s, e;
	s = pattern.substr(0, i);
	e = pattern.substr(i+1);
	int s_len, e_len;
	s_len = s.length();
	e_len = e.length();
	for (int i = 0; i < n; ++i) {
		string p;
		cin >> p;
		int len = p.length();
		if (len >= s_len + e_len &&p.substr(0, s_len) == s && p.substr(len - e_len) == e)
			cout << "DA";
		else
			cout << "NE";
		cout << "\n";
	}
}