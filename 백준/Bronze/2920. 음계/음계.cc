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
	for (int i = 0; i < 8; ++i) {
		char c;
		cin >> c;
		s += c;
	}
	if (s == "12345678")
		cout << "ascending" << "\n";
	else if (s == "87654321")
		cout << "descending" << "\n";
	else
		cout << "mixed" << "\n";
}