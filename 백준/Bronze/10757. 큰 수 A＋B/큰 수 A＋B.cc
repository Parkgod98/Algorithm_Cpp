//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string a, b;

	cin >> a >> b;

	int max_len = max(a.length(), b.length());
	a = string(max_len - a.length(), '0') + a;
	b = string(max_len - b.length(), '0') + b;

	int carry = 0;
	string result = "";
	for (int i = max_len - 1; i >= 0; --i) {
		int value = (a[i] - '0') + (b[i] - '0') + carry;
		carry = value / 10;
		result += ((value % 10) + '0');
	}
	if (carry != 0)
		result += ((carry % 10) + '0');

	reverse(result.begin(), result.end());
	cout << result;

}