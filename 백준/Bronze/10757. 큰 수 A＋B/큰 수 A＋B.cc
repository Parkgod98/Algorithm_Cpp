//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;

	cin >> a >> b;

	int a_len = a.length();
	int b_len = b.length();
	int max_len, min_len;
	
	if (a_len >= b_len) {
		max_len = a_len;
		min_len = b_len;
	}
	else {
		max_len = b_len;
		min_len = a_len;
		string tmp = a;
		a = b;
		b = tmp;
	}

	string mask = "";
	for (int i = 0; i < max_len - min_len; ++i)
		mask += "0";
	b = mask + b;

	string result = "";
	int carry = 0;
	for (int i = max_len - 1; i >= 0; --i) {
		int value = (a[i]-'0') + (b[i]-'0') + carry;
		if (value >= 10) {
			result += char(value % 10) + '0';
			carry = value / 10;
		}
		else {
			result += char(value) + '0';
			carry = 0;
		}
	}
	if (carry != 0)
		result += char(carry) + '0';

	reverse(result.begin(), result.end());
	cout << result;
}