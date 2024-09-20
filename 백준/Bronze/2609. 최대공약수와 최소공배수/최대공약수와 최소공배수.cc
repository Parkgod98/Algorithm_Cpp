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

int GetGCD(int a, int b)
{
	while (a % b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}

int GetLCM(int a, int b)
{
	return (a * b) / GetGCD(a, b);
}

int main()
{
	int a, b;
	cin >> a >> b;

	cout << GetGCD(a, b) << "\n" << GetLCM(a, b);
}