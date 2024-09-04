//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		cout << s[0] << s[s.length() - 1] << "\n";
	}
}