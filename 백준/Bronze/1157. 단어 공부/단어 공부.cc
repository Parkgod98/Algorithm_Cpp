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

int main()
{
	int count[26] = { 0 };
	string s;
	cin >> s;

	int len = s.length();
	for (int i = 0; i < len; ++i) {
		count[toupper(s[i]) - 'A']++;
	}
	int i = max_element(count, count + 26) - count;
	for (int j = 0; j < 26; ++j) {
		if (j != i && count[j] == count[i]) {
			cout << "?";
			return 0;
		}
	}
	cout << (char)('A' + i);
}