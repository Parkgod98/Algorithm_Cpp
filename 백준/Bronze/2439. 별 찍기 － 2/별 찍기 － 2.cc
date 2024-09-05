//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i -1; ++j)
			cout << " ";
		for (int k = 0; k < i + 1; k++)
			cout << "*";
		cout << "\n";
	}
}