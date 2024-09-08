//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		if (b%a == 0)
			cout << "factor" << "\n";
		else if (a%b == 0)
			cout << "multiple" << "\n";
		else
			cout << "neither" << "\n";
	}
}
	
