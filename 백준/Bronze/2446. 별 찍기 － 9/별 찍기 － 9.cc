#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void PrintN(char c, int n) {
	for (int i = 0; i < n; ++i)
		cout << c;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		PrintN(' ', i);
		PrintN('*', 2 * n - 2*i - 1);
		PrintN('\n', 1);
	}

	for (int i = n-1; i > 0; --i) {
		PrintN(' ', i-1);
		PrintN('*', 2 * n - 2 * i + 1);
		PrintN('\n', 1);
	}
}