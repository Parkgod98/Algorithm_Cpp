//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

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
	sort(v.begin(), v.end());
	for (int i : v)
		cout << i << "\n";
}