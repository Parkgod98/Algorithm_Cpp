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
	int m, f;
	while (1) {
		cin >> m >> f;
		if (m == 0 && f == 0)
			break;
		cout << m + f << "\n";
	}

	return 0;
}