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
	int sum = 0;
	for (int i = 0; i < 4; ++i) {
		int n;
		cin >> n;
		sum += n;
	}
	cout << sum / 60 << "\n" << sum % 60;
}
