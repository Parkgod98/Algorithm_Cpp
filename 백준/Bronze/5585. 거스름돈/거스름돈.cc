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
	int n;
	cin >> n;

	n = 1000 - n;

	int res = 0;
	res += n / 500;
	n %= 500;
	res += n / 100;
	n %= 100;
	res += n / 50;
	n %= 50;
	res += n / 10;
	n %= 10;
	res += n / 5;
	n %= 5;
	res += n;

	cout << res;
}