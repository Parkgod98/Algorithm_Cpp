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

void FillV(int i, int j,vector<int>& v) {

	for (int n = i; n < j; ++n) {
		v[n] += 1;
	}
}

int main()
{
	int a, b, c;

	cin >> a >> b >> c;
	vector<int> v(101);
	vector<int> cm = { 0,a,b,c };
	for (int i = 0; i < 3; ++i) {
		int x, y;
		cin >> x >> y;
		FillV(x, y, v);
	}

	int money = 0;
	for (int i : v) {
		if (i == 1)
			money += a;
		else if (i == 2)
			money += (b * i);
		else if (i == 3)
			money += (c * i);
	}
	cout << money;
}