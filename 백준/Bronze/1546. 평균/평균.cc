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
	
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		v.push_back(k);
	}

	int max = v[max_element(v.begin(), v.end()) - v.begin()];
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum += ((double)v[i] / max) * 100;

	cout << fixed;
	cout.precision(2);
	cout << sum / n;
}