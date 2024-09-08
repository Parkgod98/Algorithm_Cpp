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
	int a, b;
	vector<int> v;

	cin >> a >> b;

	for (int i = 0; i < 5; ++i) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	for (int i : v) {
		cout << i - a * b << " ";
	}
}
