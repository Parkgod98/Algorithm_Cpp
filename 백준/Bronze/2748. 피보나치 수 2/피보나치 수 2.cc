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
// atoi(s.c_str());
// stoi()

int main()
{
	vector<long long> v = { 0,1,1 };

	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		v.push_back(v[i - 1] + v[i]);
	}
	cout << v[n] << "\n";
}