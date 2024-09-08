//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	vector<int> v;
	for (int i = 0; i < 3; ++i) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	int money;
	if (v[0] == v[1] && v[1] == v[2]) {
		money = 10000 + v[0] * 1000;
	}
	else if (v[0] != v[1] && v[0] != v[2] && v[1] != v[2]) {
		money = v[2] * 100;
	}
	else {
		if (v[0] == v[1])
			money = 1000 + v[0] * 100;
		else
			money = 1000 + v[1] * 100;
	}
	cout << money << "\n";
}