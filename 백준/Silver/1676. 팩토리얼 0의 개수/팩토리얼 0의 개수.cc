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

int GetZero(int n)
{
	int divisor = 5;
	int sum = 0;
	while (divisor <= n) {
		sum += n / divisor;
		divisor *= 5;
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	cout << GetZero(n);
}
