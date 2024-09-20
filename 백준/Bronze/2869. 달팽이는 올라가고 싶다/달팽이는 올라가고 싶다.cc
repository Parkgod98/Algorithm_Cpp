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
	long long a, b, v;
	cin >> a >> b >> v;

	v -= a;
	long long res = v / (a - b) +1;
	if (v % (a - b) != 0)
		res++;
	cout << res;
}