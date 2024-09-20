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
	int n, k;
	cin >> n >> k;

	if (k > n - k) 
		k = n - k;

	int res = 1;
	for (int i = n; i > n - k; --i) 
		res *= i;
	for (int i = 1; i <= k; ++i)
		res /= i;

	cout << res;
}