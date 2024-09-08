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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a - 1; j <= b - 1; ++j) {
				v[j] = c;
		}
	}
	for (int i : v)
		cout << i << " ";
}
	
