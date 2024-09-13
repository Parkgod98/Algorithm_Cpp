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

	for (int n = i; n <= j; ++n) {
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
	for (int i = 1; i < v.size()-1; ++i) {
		if (v[i + 1] != 0 && v[i] >= v[i + 1])
			money += v[i + 1] * cm[v[i + 1]];
		else if (v[i + 1] != 0 && v[i] < v[i + 1])
			money += v[i] * cm[v[i]];
	}
	cout << money;
}