//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

bool IsPrime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (IsPrime(k))
			sum++;
	}
	cout << sum;
}