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


int main()
{
	vector<int> v;

	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		int n;
		cin >> n;
		v.push_back(n);
		sum += n;
	}
	sort(v.begin(), v.end());
	cout << sum / 5 << "\n" << v[2];
}