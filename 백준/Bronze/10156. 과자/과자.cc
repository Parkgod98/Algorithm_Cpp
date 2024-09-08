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
	int a, b, c;
	cin >> a >> b >> c;

	int n = a * b - c;
	if (n < 0)
		n = 0;

	cout << n << "\n";
}
