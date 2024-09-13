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

void range_reverse(int a, int b, vector<int> &v) {
	while (a <= b) {
		swap(v[a - 1], v[b - 1]);
		a++;
		b--;
	}
}

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
		range_reverse(a, b, v);
	}
	for (int i : v)
		cout << i << " ";
}