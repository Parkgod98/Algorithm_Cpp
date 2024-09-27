#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
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

	map<int,int> m;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (m[k])
			m[k] += 1;
		else
			m[k] = 1;
	}
	for (auto it : m) {
		for (int i = 0; i < it.second; ++i)
			cout << it.first << "\n";
	}
}
