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

int Rev(string s)
{
	reverse(s.begin(), s.end());
	return stoi(s);
}

int main()
{
	string a, b;
	cin >> a >> b;

	cout << Rev(to_string(Rev(a) + Rev(b)));
}
