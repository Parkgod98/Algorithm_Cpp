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
	vector<bool> v(m + 1, true);
	v[1] = false;
	for (int i = 2; i < m + 1; ++i) {
		if (v[i] == true)
			for (int j = i*2; j < m + 1; j+=i) {
				v[j] = false;
			}
	}
	for (int i = n; i <= m; ++i) {
		if (v[i])
			cout << i << "\n";
	}
}
