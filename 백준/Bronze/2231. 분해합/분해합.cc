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


string GetTarget(int n) {
	string s =  to_string(n);

	int sum = 0;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		sum += (s[i] - '0');
	}
	s = to_string(n + sum);
	return s;
}

int main()
{	
	string s;
	cin >> s;

	int n = stoi(s);
	for (int i = 1; i <= n; ++i) {
		if (GetTarget(i) == s) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
	return 0;

}