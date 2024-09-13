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
	int m, n;
	cin >> m >> n;

	int sum,min_p;
	sum = 0;
	for (int i = m; i <= n; ++i) {
		if (IsPrime(i)) {
			if (sum == 0)
				min_p = i;
			sum += i;
		}
	}
	if (sum != 0)
		cout << sum << "\n" << min_p;
	else
		cout << -1;
}