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
	string s;
	int n;
	cin >> s >> n;

	reverse(s.begin(), s.end());
	int len = s.length();
	long long decimal = 0;
	for (int i = 0; i < len; ++i) {
		if (isalpha(s[i])) {
			decimal += (s[i] - 'A' + 10) * pow(n, i);
		}
		else
			decimal += (s[i] - '0') * pow(n, i);
	}
	cout << decimal;
}