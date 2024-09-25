#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
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
	vector<int> v;

	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < i; ++j)
			v.push_back(i);
	}
	int a, b;
	cin >> a >> b;

	int sum = 0;
	for (int i = a - 1; i <= b - 1; ++i)
		sum += v[i];
	cout << sum;
}
