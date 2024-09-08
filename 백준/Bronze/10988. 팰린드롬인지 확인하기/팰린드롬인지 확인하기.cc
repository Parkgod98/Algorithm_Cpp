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
	string s;
	cin >> s;

	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (!(s[i] == s[len - i - 1])) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1;

	return 0;
}
	
