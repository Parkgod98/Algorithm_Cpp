//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;


//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

//cout << fixed;
//cout.precision(2);

int main()
{
	int n;
	cin >> n;

	vector<int> v(10001);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		v[k]++;
	}
	for (int i = 1; i < 10001; ++i) {
		for (int j = 0; j < v[i]; ++j)
			cout << i << '\n';
	}
}