#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

bool IsPrime(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if ( n% i == 0)
			return false;
	}
	return true;
}


int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = n; i <= m; ++i) {
		if (IsPrime(i))
			cout << i << "\n";
	}
}
