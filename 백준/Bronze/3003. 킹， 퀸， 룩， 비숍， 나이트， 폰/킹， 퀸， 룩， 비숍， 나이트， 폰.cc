//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int k, q, l, b, n, p;
	cin >> k >> q >> l >> b >> n >> p;

	cout << 1 - k <<" " << 1 - q << " " << 2 - l << " " << 2 - b << " " << 2 - n << " " << 8 - p;
	

	return 0;
}