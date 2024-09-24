#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());

	cout << v[v.size() - 1] * v[0];
}
