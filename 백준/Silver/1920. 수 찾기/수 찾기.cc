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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		mp[k] = 1;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		if (mp[k])
			cout << 1;
		else
			cout << 0;
		cout << "\n";
	}
}
