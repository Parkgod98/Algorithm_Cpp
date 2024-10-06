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

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		if (c <= k)
			v.push_back(c);
	}

	int res = 0;

	for (int i = v.size() - 1; i >= 0; --i) {
		res += k / v[i];
		k %= v[i];
		if (k == 0)
			break;
	}
	cout << res;

}
