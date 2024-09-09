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
	vector<int> v = { 0,1 };
	int n;
	cin >> n;

	for (int i = 0; i <= n; ++i) {
		v.push_back(v[i] + v[i + 1]);
	}
	cout << v[n];
}