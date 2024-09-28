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

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	int n, m;
	cin >> n >> m;

	int j;
	cin >> j;

	int ret = 0;
	int s = 0;
	int f = m -1;
	for (int i = 0; i < j; ++i) {
		int k;
		cin >> k;
		k = k - 1;
		if (s <= k && k <= f)
			continue;
		else {
			int sk_len, fk_len;
			sk_len = abs(s - k);
			fk_len = abs(f - k);
			if (sk_len > fk_len) {
				ret += fk_len;
				s += fk_len;
				f += fk_len;
			}
			else if (sk_len == fk_len) {
				ret += sk_len;
				if (k < s) {
					s -= sk_len;
					f -= fk_len;
				}
				else {
					s += fk_len;
					f += fk_len;
				}
			}
			else {
				ret += sk_len;
				f -= sk_len;
				s -= sk_len;
			}
		}
	}
	cout << ret;

	
}
