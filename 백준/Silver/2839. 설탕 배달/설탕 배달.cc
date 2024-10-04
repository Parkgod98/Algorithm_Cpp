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

int main()
{
	int n;
	cin >> n;

	int p = n;
	int five, thr;
	five = thr = 0;

	five += p / 5;
	p %= 5;
	thr += p / 3;
	p %= 3;
	if (p != 0) {
		while (five >= 0) {
			five--;
			p = n;
			p = p - five * 5;
			if (p % 3 == 0) {
				thr = p / 3;
				break;
			}
		}
	}
	if (five < 0)
		cout << -1;
	else
		cout << five + thr;
		

}
