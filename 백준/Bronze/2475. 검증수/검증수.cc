//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int sum, k;
	sum = 0;
	for (int i = 0; i < 5; ++i) {
		cin >> k;
		sum += k * k;
	}
	cout << sum % 10 << "\n";
}