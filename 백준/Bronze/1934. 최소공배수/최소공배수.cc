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
// atoi(s.c_str());
// stoi()

int GetGCD(int a, int b)
{
	while (a % b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;
		int gcd = GetGCD(a, b);

		cout << (a / gcd) * b << "\n";
	}
}