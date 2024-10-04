#define _crt_secure_no_warnings
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
//cin.tie(null);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

typedef long long ll;

int IsHansu(int n)
{
	if (n < 100)
		return 1;
	else if (n >= 100 && n < 1000) {
		int a = n / 100;
		int b = (n % 100) / 10;
		int c = n % 10;
		if (a - b == b - c)
			return 1;
		return 0;
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;

	int count = 0;
	for (int i = 1; i <= n; ++i) {
		count += IsHansu(i);
	}
	cout << count;
}
