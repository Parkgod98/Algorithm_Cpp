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
	int n;
	string num;

	cin >> n >> num;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (num[i] - '0');
	}
	cout << sum << "\n";

}