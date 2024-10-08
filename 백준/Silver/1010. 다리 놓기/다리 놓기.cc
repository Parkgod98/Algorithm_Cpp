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

long long Comb(int n, int r)
{
	ll top = 1;
	int k = 1;
	for (int i = n; i > n - r; --i) {
		top *= i;
		top /= k;
		k++;
	}
	
	return top;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int n, r;
		cin >> r >> n;
		cout << Comb(n, r) << "\n";
	}
}
