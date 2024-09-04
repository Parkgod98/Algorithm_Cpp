//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n / 4; ++i)
		cout << "long ";

	cout << "int" << "\n";

	return 0;
}