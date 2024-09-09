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
	long long a, b, c;
	cin >> a >> b >> c;

	int profit = c - b;
	if (profit <= 0)
		cout << -1;
	else {
		cout << (a / profit) + 1;
	}
	return 0;
}