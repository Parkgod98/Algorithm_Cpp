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
	map<int, int> mp;

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k == 0)
			v.pop_back();
		else
			v.push_back(k);
	}
	int sum = 0;
	for (int i : v)
		sum += i;
	cout << sum;
}
