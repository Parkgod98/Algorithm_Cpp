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
	int n;
	cin >> n;

	vector<int> v(n + 1,99999999);
	v[n] = 0;
	for (int i = n; i >=1; --i) {
		if (i % 3 == 0) {
			v[i / 3] = min(v[i / 3], v[i] + 1);
		}
		if (i % 2 == 0) {
			v[i / 2] = min(v[i / 2], v[i] + 1);
		}
		v[i - 1] = min(v[i - 1], v[i]+1);
	}
	cout << v[1];
}
