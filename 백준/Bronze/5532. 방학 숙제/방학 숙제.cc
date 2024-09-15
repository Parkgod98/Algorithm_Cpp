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
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	a = a % c != 0 ? a / c + 1 : a / c;
	b = b % d != 0 ? b / d + 1 : b / d;
	a = a > b ? a : b;

	cout << l - a;
}