//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		v.push_back(k);
	}

	int num;
	cin >> num;
	cout << count(v.begin(), v.end(), num) << "\n";
	

	return 0;
}