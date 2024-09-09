//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{	// 1,2~7 8~19,20~37
	long long n, sum;
	cin >> n;
	sum = 1;
	int fact = 1;
	while (1) {
		if (n <= sum) {
			cout << fact;
			return 0;
		}
		sum = sum + fact * 6;
		fact++;
	}

	return 0;
}