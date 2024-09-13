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
	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 1; i <= n; ++i)
		v.push_back(i);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		swap(v[a - 1], v[b - 1]);
	}

	for (int i : v)
		cout << i << " ";
}